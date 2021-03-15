#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include "plotter.h"

class DataGenerator
{
public:
    DataGenerator();
    ~DataGenerator();
    void generateData(float, float *);
    void startGenerator(float, float *);
};

#endif // DATAGENERATOR_H
