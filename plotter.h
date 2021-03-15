#ifndef PLOTTER_H
#define PLOTTER_H

#include <QPaintEvent>
#include <QPainter>


class Plotter
{
public:
    Plotter();
    ~Plotter();
    void plotData(QRect &, QPainter &, float *);
private:
    QPoint calculatePoint(int, float, QRect &, float);
    QPointF computeShape(float);
    void generateData(float);
    float mIntervalLength{4 * M_PI};
    float mScale{40};
    int mStepCount{256};
//    float *pData{new float[256]};
};

#endif // PLOTTER_H
