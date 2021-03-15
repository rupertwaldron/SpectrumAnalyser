#include "plotter.h"

Plotter::Plotter()
{
    qInfo("Plotter()");
}

Plotter::~Plotter()
{
//    delete [] pData;
    qInfo("~Plotter()");
}

void Plotter::plotData(QRect &canvas, QPainter &painter, float *pData)
{
    float step = mIntervalLength / mStepCount;
//    mDataGenerator.generateData(step, pData);
    QPoint previousPixel = calculatePoint(0, step, canvas, pData[0]);
    for (int i = 0; i < 256; ++i) {
        QPoint pixel = calculatePoint(i, step, canvas, pData[i]);
        painter.drawLine(previousPixel, pixel);
        previousPixel = pixel;
    }
}

QPoint Plotter::calculatePoint(int index, float step, QRect &canvas, float data)
{
    QPoint center = canvas.center();
    return QPoint (
                index * step * mScale,
                data * mScale + center.y()
                );
}

QPointF Plotter::computeShape(float t)
{
    float x = t;
    float y = sin(t) + 0.33 * sin(3 * t) + 0.2 * sin(5 * t) + 0.14 * sin(7 * t) + 0.11 * sin(9 * t) + 0.09 * sin(11 * t);
    return QPointF(x, y);
}

//void Plotter::generateData(float step) {
//    double randA = QRandomGenerator::global()->bounded(1.0);
//    double randB = QRandomGenerator::global()->bounded(1.0);
//    double randC = QRandomGenerator::global()->bounded(1.0);
//    double randD = QRandomGenerator::global()->bounded(1.0);
//    double randE = QRandomGenerator::global()->bounded(1.0);
//    for (int i = 0; i < 256; ++i) {
//        float t = i * step;
//        pData[i] = sin(t) + randA * sin(3 * t) + randB * sin(5 * t) + randC * sin(7 * t) + randD * sin(9 * t) + randE * sin(11 * t);
//    }
//}


