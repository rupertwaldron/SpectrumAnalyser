#ifndef PLOTTER_H
#define PLOTTER_H
#include <QPaintEvent>
#include <QPainter>


class Plotter
{
public:
    Plotter();
    ~Plotter();
    void plotData(QRect &, QPainter &);
private:
    QPoint calculatePoint(float, QRect &);
    QPointF computeShape(float);
    float mIntervalLength{4 * M_PI};
    float mScale{40};
    int mStepCount{256};
};

#endif // PLOTTER_H
