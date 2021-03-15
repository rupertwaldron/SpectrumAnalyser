#include "plotter.h"
#include <QPaintEvent>
#include <QPainter>
#include<chrono>
#include<thread>
#include <QRandomGenerator>

Plotter::Plotter() :
    mDataGenerator(DataGenerator())
{
    qInfo("Plotter()");
}

Plotter::~Plotter()
{
    delete [] pData;
    qInfo("~Plotter()");
}

//void Plotter::plotData(QRect &canvas, QPainter &painter)
//{
//    float step = mIntervalLength / mStepCount;
//    QPoint previousPixel = calculatePoint(0, canvas);
//    for (float t = step; t < mIntervalLength; t += step) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
//        QPoint pixel = calculatePoint(t, canvas);
//        painter.drawLine(previousPixel, pixel);
//        previousPixel = pixel;
//    }
//}

void Plotter::plotData(QRect &canvas, QPainter &painter)
{
    float step = mIntervalLength / mStepCount;
    mDataGenerator.generateData(step, pData);
    QPoint previousPixel = calculatePoint(0, step, canvas);
    for (int i = 0; i < 256; ++i) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        QPoint pixel = calculatePoint(i, step, canvas);
        painter.drawLine(previousPixel, pixel);
        previousPixel = pixel;
    }
}

QPoint Plotter::calculatePoint(int index, float step, QRect &canvas)
{
    QPoint center = canvas.center();
    return QPoint (
                index * step * mScale,
                pData[index] * mScale + center.y()
                );
}

QPointF Plotter::computeShape(float t)
{
    float x = t;
    float y = sin(t) + 0.33 * sin(3 * t) + 0.2 * sin(5 * t) + 0.14 * sin(7 * t) + 0.11 * sin(9 * t) + 0.09 * sin(11 * t);
    return QPointF(x, y);
}

void Plotter::generateData(float step) {
    double randA = QRandomGenerator::global()->bounded(1.0);
    double randB = QRandomGenerator::global()->bounded(1.0);
    double randC = QRandomGenerator::global()->bounded(1.0);
    double randD = QRandomGenerator::global()->bounded(1.0);
    double randE = QRandomGenerator::global()->bounded(1.0);
    for (int i = 0; i < 256; ++i) {
        float t = i * step;
        pData[i] = sin(t) + randA * sin(3 * t) + randB * sin(5 * t) + randC * sin(7 * t) + randD * sin(9 * t) + randE * sin(11 * t);
    }
}


