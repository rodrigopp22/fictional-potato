#include "Detector.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include "debug.hpp"
#include "Datatype.hpp"
#include "Geometry.hpp"

Detector::Detector(Config_file config_file, std::vector<datatype *> *self_dataset)
{
    this->config_file = config_file;
    geometry.setProblemSize(config_file.GetProblem_size());
    this->self_dataset = self_dataset;
}

void Detector::random_vector(datatype *vector)
{
    for (int i = 0; i < config_file.GetProblem_size(); i++)
    {
#ifdef DEBUG
        vector[i] = config_file.GetSearch_spaceIndex(2 * i) + ((config_file.GetSearch_spaceIndex(2 * i + 1) - config_file.GetSearch_spaceIndex(2 * i)) * Random());
#else
        vector[i] = config_file.GetSearch_spaceIndex(2 * i) + ((config_file.GetSearch_spaceIndex(2 * i + 1) - config_file.GetSearch_spaceIndex(2 * i)) * uniform(engine));
#endif
    }
}

std::vector<datatype *> *Detector::generate_detectors()
{
    std::vector<datatype *> *detectors = new std::vector<datatype *>();
    std::cout << "Generating detectors..." << std::endl;
    datatype *detector = new datatype[config_file.GetProblem_size()];
    do
    {
        random_vector(detector);
        if (!geometry.matches(detector, self_dataset, config_file.GetMin_dist()))
        {
            if (!geometry.matches(detector, detectors, 0.0))
            {
                detectors->push_back(detector);
                detector = new datatype[config_file.GetProblem_size()];
                std::cout << detectors->size() << "/" << config_file.GetMax_detectors() << std::endl;
            }
        }
    } while (detectors->size() < config_file.GetMax_detectors());

    if (detector != *detectors->cend())
    {
        delete[] detector;
    }

    return detectors;
}
result Detector::apply_detectors(std::vector<datatype*> *detectors)
{
    std::set<int> *detected = new std::set<int>();
    int trial = 1;
    for (auto it = self_dataset->cbegin(); it != self_dataset->cend(); it++)
    {
        bool actual = geometry.matches(*it, detectors, config_file.GetMin_dist());
        bool expected = geometry.matches(*it, self_dataset, config_file.GetMin_dist());
        if (actual == expected)
        {
            detected->insert(trial);
        }
        trial++;
    }

    std::cout << "Expected to be detected: ";
    for (auto it = config_file.GetExpected_detected().cbegin(); it != config_file.GetExpected_detected().cend();)
    {
        std::cout << *it;
        if (++it != config_file.GetExpected_detected().cend())
            std::cout << ", ";
    }
    std::cout << std::endl;

    std::cout << "Found: ";
    for (auto it = detected->cbegin(); it != detected->cend();)
    {
        std::cout << *it;
        if (++it != detected->cend())
            std::cout << ", ";
    }
    std::cout << std::endl;

    std::set<int> expected_detected(config_file.GetExpected_detected().begin(), config_file.GetExpected_detected().end());
    datatype expected_detected_size = expected_detected.size();
    for (auto it = detected->cbegin(); it != detected->cend(); it++)
    {
        auto found = expected_detected.find(*it);
        if (found != expected_detected.end())
        {
            expected_detected.erase(*it);
        }
    }
    datatype new_expected_detected_size = expected_detected.size();

    result result;
    result.DR = (-(new_expected_detected_size - expected_detected_size) / expected_detected_size);

    expected_detected.clear();
    expected_detected.insert(config_file.GetExpected_detected().begin(), config_file.GetExpected_detected().end());
    for (auto it = expected_detected.cbegin(); it != expected_detected.cend(); it++)
    {
        auto found = detected->find(*it);
        if (found != detected->end())
        {
            detected->erase(*it);
        }
    }
    datatype new_detected_size = detected->size();
    result.FAR = (new_detected_size / expected_detected_size);

    return result;
}