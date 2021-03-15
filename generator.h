#ifndef GENERATOR_H
#define GENERATOR_H

#include <QRandomGenerator>
#include <chrono>
#include <thread>

class Generator
{
public:
    Generator();
    ~Generator();
    void generateData(float step, float *pDataArray);
    bool dataReady();
private:
    bool isReady{false};
};

#endif // GENERATOR_H
