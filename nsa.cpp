#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include "csv.hpp"
#include "Dataset.hpp"
#include "Detector.hpp"
#include "Datatype.hpp"
#include "result.hpp"
#include "Config_file.hpp"

void init_search_space(Config_file &config_file)
{
    datatype search_space = new datatype[config_file.GetProblem_size() * 2];
    config_file.SetSearch_space(search_space);
    for (int i = 0; i < config_file.GetProblem_size(); i++)
    {
        //config.search_space[2 * i] = 0.0;
        config_file.SetSearch_spaceIndex(0.0, (2 * i));
        //config.search_space[2 * i + 1] = 1.0;
        config_file.SetSearch_spaceIndex(1.0, (2 * i + 1);
    }
}

void run(Config_file &config_file)
{
    std::vector<result> general_results;
    init_search_space(config_file);
    //std::cout << "nome: " << config.training_dataset_csv_file << std::endl;
    Dataset training_dataset(config_file.GetTraining_dataset_csv_file());
    // Dataset training_dataset(config.training_dataset_csv_file);
    Dataset testing_dataset(config_file.GetTesting_dataset_csv_file());
    // Dataset testing_dataset(config.testing_dataset_csv_file);
    std::vector<datatype *> *self_dataset_for_training = training_dataset.read_dataset();
    std::vector<datatype *> *generate_self_dataset_for_testing = testing_dataset.read_dataset();
    Detector training_detectors(config_file, geometry, self_dataset_for_training);
    Detector testing_detectors(config_file, geometry, generate_self_dataset_for_testing);
    for (int proof = 0; proof < config_file.GetAmount_of_proofs(); proof++)
    {
        std::vector<datatype *> *detectors = training_detectors.generate_detectors();
        general_results.push_back(testing_detectors.apply_detectors());
    }
    std::cout << "Detectors: " << config_file.GetMax_detectors() << std::endl;
    std::cout << "Min. distance: " << config_file.GetMin_dist() << std::endl;
    std::cout << "Runs: " << config_file.GetAmount_of_proofs() << std::endl;
    datatype sum_DR = 0;
    datatype sum_FAR = 0;
    for (result &r : general_results)
    {
        std::cout << r.DR << ", " << r.FAR << std::endl;
        sum_DR += r.DR;
        sum_FAR += r.FAR;
    }
    std::cout << "Average: " << sum_DR / config_file.GetAmount_of_proofs() << ", " << sum_FAR / config_file.GetAmount_of_proofs() << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        std::string config_file_name = argv[1];
        Config_file config_file(config_file_name);
        config_file.read();
        run(config_file);
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " <CONFIG-FILE>" << std::endl
                  << std::endl;
        return -1;
    }

    return 0;
}
