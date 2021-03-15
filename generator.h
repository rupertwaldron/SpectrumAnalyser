#ifndef GENERATOR_H
#define GENERATOR_H

#include "renderscreen.h"
#include <QWidget>



class Generator
{
public:
    Generator();
    ~Generator();
    void generateData(float step, float *pDataArray);
};

#endif // GENERATOR_H
