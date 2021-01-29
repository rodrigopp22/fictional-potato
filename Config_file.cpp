#include "Config_file.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include "csv.hpp"

Config_file::Config_file(std::string &name)
{
    config_file = name;
}

void Config_file::read()
{
    csv::CSVFormat format;
    format.trim({' ', '\t'});
    format.variable_columns(csv::VariableColumnPolicy::KEEP);
    std::cout << "Esse eh o config_file_name: " << config_file << std::endl;
    csv::CSVReader reader(config_file, format);
    csv::CSVRow row;
    // 1st row
    reader.read_row(row);
    problem_size = row[0].get<int>();
    max_detectors = row[1].get<int>();
    min_dist = row[2].get<int>();
    amount_of_proofs = row[3].get<int>();
    training_dataset_csv_file = row[4].get();
    testing_dataset_csv_file = row[5].get();
    // 2nd row
    reader.read_row(row);
    for (csv::CSVField &field : row)
        expected_detected.push_back(field.get<int>());
}

std::string Config_file::GetConfig_file() const
{
    return config_file;
}

void Config_file::SetConfig_file(std::string config_file)
{
    config_file = config_file;
}

int Config_file::GetMax_detectors() const
{
    return max_detectors;
}

void Config_file::SetMax_detectors(int max_detectors)
{
    max_detectors = max_detectors;
}

datatype Config_file::GetMin_dist() const
{
    return min_dist;
}

void Config_file::SetMin_dist(datatype min_dist)
{
    min_dist = min_dist;
}

int Config_file::GetAmount_of_proofs() const
{
    return amount_of_proofs;
}

void Config_file::SetAmount_of_proofs(int amount_of_proofs)
{
    amount_of_proofs = amount_of_proofs;
}

std::string Config_file::GetTraining_dataset_csv_file() const
{
    return training_dataset_csv_file;
}

void Config_file::SetTraining_dataset_csv_file(std::string training_dataset_csv_file)
{
    training_dataset_csv_file = training_dataset_csv_file;
}

std::string Config_file::GetTesting_dataset_csv_file() const
{
    return testing_dataset_csv_file;
}

void Config_file::SetTesting_dataset_csv_file(std::string testing_dataset_csv_file)
{
    testing_dataset_csv_file = testing_dataset_csv_file;
}

std::vector<int> Config_file::GetExpected_detected() const
{
    return expected_detected;
}

void Config_file::SetExpected_detected(std::vector<int> expected_detected)
{
    expected_detected = expected_detected;
}

datatype *Config_file::GetSearch_space() const
{
    return search_space;
}

void Config_file::SetSearch_space(datatype *search_space)
{
    search_space = search_space;
}

void Config_file::SetSearch_spaceIndex(datatype value, int index)
{
    search_space[index] = value;
}

datatype Config_file::GetSearch_spaceIndex(int index) const{
    return search_space[index];
}

int Config_file::GetProblem_size() const
{
    return problem_size;
}

void Config_file::SetProblem_size(int problem_size)
{
    problem_size = problem_size;
}
