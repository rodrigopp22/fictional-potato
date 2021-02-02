#ifndef DETECTOR_HPP
#define DETECTOR_HPP
#include <vector>
#include "Datatype.hpp"
#include "Dataset.hpp"
#include "result.hpp"
#include "Config_file.hpp"
#include "Geometry.hpp"

class Detector
{
private:
    std::vector<datatype *> *self_dataset;
    int generation;
    std::vector<datatype *> *detectors;
    Config_file config_file;
    Geometry geometry;

public:
    Detector(Config_file, std::vector<datatype *>*);
    void random_vector(datatype *);
    std::vector<datatype *> *generate_detectors();
    result apply_detectors(std::vector<datatype*> *);
};

#endif