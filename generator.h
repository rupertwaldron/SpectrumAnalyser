#ifndef GENERATOR_H
#define GENERATOR_H

#include <QRandomGenerator>

class Generator
{
public:
    Generator();
    ~Generator();
    void generateData(float step, float *pDataArray);
};

#endif // GENERATOR_H
