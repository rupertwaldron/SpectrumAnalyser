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
                point.x() * mScale + center.x(),
                point.y() * mScale + center.y()
                );
}

QPointF Plotter::computeShape(float t)
{
    float x = 2 * cos(t);
    float y = 2 * sin(t);
    return QPointF(x, y);
}


