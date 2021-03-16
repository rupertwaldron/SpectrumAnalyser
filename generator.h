#ifndef GENERATOR_H
#define GENERATOR_H

#include <QRandomGenerator>
#include <chrono>
#include <thread>

class RenderScreen;

class Generator
{
public:
    Generator();
    ~Generator();
    void generateData(float step, float *pDataArray);
    bool dataReady();
    void subscribe(RenderScreen *screen, float *pDataArray, float step);
private:
    bool isReady{false};
    RenderScreen *pRenderScreen;
};

#endif // GENERATOR_H
