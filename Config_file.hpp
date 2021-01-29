#ifndef CONFIG_FILE_HPP
#define CONFIGS_FILE_HPP
#include <string>
#include <vector>
#include "Datatype.hpp"

class Config_file
{
private:
    std::string config_file;
    int problem_size;
    int max_detectors;
    datatype min_dist;
    int amount_of_proofs;
    std::string training_dataset_csv_file;
    std::string testing_dataset_csv_file;
    std::vector<int> expected_detected;
    datatype *search_space;

public:
    Config_file(std::string &name);
    void read();

    std::string GetConfig_file() const;
    void SetConfig_file(std::string config_file);

    int GetProblem_size() const;
    void SetProblem_size(int problem_size);

    int GetMax_detectors() const;
    void SetMax_detectors(int max_detectors);

    datatype GetMin_dist() const;
    void SetMin_dist(datatype min_dist);

    int GetAmount_of_proofs() const;
    void SetAmount_of_proofs(int amount_of_proofs);

    std::string GetTraining_dataset_csv_file() const;
    void SetTraining_dataset_csv_file(std::string training_dataset_csv_file);

    std::string GetTesting_dataset_csv_file() const;
    void SetTesting_dataset_csv_file(std::string testing_dataset_csv_file);

    std::vector<int> GetExpected_detected() const;
    void SetExpected_detected(std::vector<int> expected_detected);

    datatype *GetSearch_space() const;
    void SetSearch_space(datatype *search_space);
    void SetSearch_spaceIndex(datatype value, int index);
    datatype GetSearch_spaceIndex(int index) const;
};

#endif