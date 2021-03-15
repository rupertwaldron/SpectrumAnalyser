#include "datagenerator.h"
#include <QRandomGenerator>

DataGenerator::DataGenerator()
{
    qInfo("DataGenerator()");
}

DataGenerator::~DataGenerator()
{
    qInfo("~DataGenerator()");
}


void DataGenerator::generateData(float step, float *pDataArray) {
    double randA = QRandomGenerator::global()->bounded(1.0);
    double randB = QRandomGenerator::global()->bounded(1.0);
    double randC = QRandomGenerator::global()->bounded(1.0);
    double randD = QRandomGenerator::global()->bounded(1.0);
    double randE = QRandomGenerator::global()->bounded(1.0);
    for (int i = 0; i < 256; ++i) {
        float t = i * step;
        pDataArray[i] = sin(t) + randA * sin(3 * t) + randB * sin(5 * t) + randC * sin(7 * t) + randD * sin(9 * t) + randE * sin(11 * t);
    }
}
