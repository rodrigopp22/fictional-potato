#ifndef CONFIG_FILE_HPP
#define CONFIG_FILE_HPP
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
    Config_file(std::string &);
    Config_file();
    void read();

    std::string GetConfig_file() const;
    void SetConfig_file(std::string);

    int GetProblem_size() const;
    void SetProblem_size(int);

    int GetMax_detectors() const;
    void SetMax_detectors(int);

    datatype GetMin_dist() const;
    void SetMin_dist(datatype);

    int GetAmount_of_proofs() const;
    void SetAmount_of_proofs(int);

    std::string GetTraining_dataset_csv_file() const;
    void SetTraining_dataset_csv_file(std::string);

    std::string GetTesting_dataset_csv_file() const;
    void SetTesting_dataset_csv_file(std::string);

    std::vector<int> GetExpected_detected() const;
    void SetExpected_detected(std::vector<int>);

    datatype *GetSearch_space() const;
    void SetSearch_space();
    void SetSearch_spaceIndex(datatype, int);
    datatype GetSearch_spaceIndex(int) const;
};

#endif