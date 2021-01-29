#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include "Datatype.hpp"
#include "Dataset.hpp"

class Geometry
{
public:
    datatype euclidean_distance(datatype *vector, datatype *points);
    bool matches(datatype *vector, std::vector<datatype *> *dataset, datatype min_dist);
};

#endif