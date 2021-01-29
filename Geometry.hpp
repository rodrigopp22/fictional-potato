#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include "Datatype.hpp"
#include "Dataset.hpp"

class Geometry
{
private:
    int problem_size;
public:
    void setProblemSize(int problem_size);
    datatype euclidean_distance(datatype *, datatype *);
    bool matches(datatype *, std::vector<datatype *> *, datatype);
};

#endif