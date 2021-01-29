#ifndef DATASET_H
#define DATASET_H
#include <string>
#include <vector>
#include "Datatype.hpp"

class Dataset
{
private:
    std::string filename;
    int problem_size;

public:
    Dataset(std::string &name, int problem_size);
    std::vector<datatype *> *read_dataset();
};

#endif