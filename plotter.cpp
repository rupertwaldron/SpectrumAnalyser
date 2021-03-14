#include "plotter.h"
#include <QPaintEvent>
#include <QPainter>

Plotter::Plotter()
{
    qInfo("Plotter()");
}

Plotter::~Plotter()
{
    qInfo("~Plotter()");
}

void Plotter::plotData(QRect &canvas, QPainter &painter)
{
    float step = mIntervalLength / mStepCount;
    QPoint previousPixel = calculatePoint(0, canvas);
    for (float t = step; t < mIntervalLength; t += step) {
        QPoint pixel = calculatePoint(t, canvas);
        painter.drawLine(previousPixel, pixel);
        previousPixel = pixel;
    }
}

QPoint Plotter::calculatePoint(float t, QRect &canvas)
{
    QPoint center = canvas.center();
    QPointF point = computeShape(t);
    return QPoint (
                point.x() * mScale,
                point.y() * mScale + center.y()
                );
}

QPointF Plotter::computeShape(float t)
{
    float x = t;
    float y = sin(t) + 0.33 * sin(3 * t) + 0.2 * sin(5 * t) + 0.14 * sin(7 * t) + 0.11 * sin(9 * t) + 0.09 * sin(11 * t);
    return QPointF(x, y);
}


