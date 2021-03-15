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

void Plotter::plotData(QRect &canvas, QPainter &painter, float *pData, float step, float scale)
{
//    mDataGenerator.generateData(step, pData);
    QPoint previousPixel = calculatePoint(0, step, canvas, pData[0], scale);
    for (int i = 0; i < 256; ++i) {
        QPoint pixel = calculatePoint(i, step, canvas, pData[i], scale);
        painter.drawLine(previousPixel, pixel);
        previousPixel = pixel;
    }
}

QPoint Plotter::calculatePoint(int index, float step, QRect &canvas, float data, float scale)
{
    QPoint center = canvas.center();
    return QPoint (
                index * step * scale,
                data * scale + center.y()
                );
}


