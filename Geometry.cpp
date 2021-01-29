#include "Geometry.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include "Config_file.hpp"

void Geometry::setProblemSize(int problem_size){
    this->problem_size = problem_size;
}

datatype Geometry::euclidean_distance(datatype *vector, datatype *points)
{
    double sum = 0;
    for (int i = 0; i < problem_size; i++)
    {
        double tmp = vector[i] - points[i];
        sum += (tmp * tmp);
    }
    return std::sqrt(sum);
}

bool Geometry::matches(datatype *vector, std::vector<datatype *> *dataset, datatype min_dist)
{
    for (auto it = dataset->cbegin(); it != dataset->cend(); it++)
    {
        datatype dist = euclidean_distance(vector, *it);
        if (dist <= min_dist)
        {
            return true;
        }
    }
    return false;
}
