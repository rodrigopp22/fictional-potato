#include "Dataset.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include "csv.hpp"
#include "Datatype.hpp"

Dataset::Dataset(std::string &name, int problem_size)
{
    filename = name;
    problem_size = problem_size;
}

std::vector<datatype *> *Dataset::read_dataset()
{
    std::vector<datatype *> *data = new std::vector<datatype *>();
    std::vector<std::string> none(problem_size, "none");
    csv::CSVFormat format;
    format.trim({' ', '\t'});
    format.column_names(none);
    std::cout << "esse eh o filename:" << filename << "\n"
              << std::endl;
    csv::CSVReader reader(filename, format);
    for (csv::CSVRow &row : reader)
    {
        datatype *row_data = new datatype[problem_size];
        int row_count = 0;
        for (csv::CSVField &field : row)
        {
            row_data[row_count] = field.get<datatype>();
            row_count++;
        }
        data->push_back(row_data);
    }
    return data;
};
