#ifndef PLOTTER_H
#define PLOTTER_H

#include <QPainter>


class Plotter
{
public:
    Plotter();
    ~Plotter();
    void plotData(QRect &canvas, QPainter &painter, float *pData, float step, float scale);
private:
    QPoint calculatePoint(int, float, QRect &, float, float);
    QPointF computeShape(float);
};

#endif // PLOTTER_H
