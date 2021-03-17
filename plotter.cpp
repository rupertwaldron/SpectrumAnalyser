#include "plotter.h"
#include "renderscreen.cpp"

Plotter::Plotter()
{
    qInfo("Plotter()");
}

Plotter::~Plotter()
{
//    delete [] pData;
    qInfo("~Plotter()");
}

void Plotter::plotData(QRect &canvas, QPainter &painter, float *pData, float intervalLength)
{
    float step = intervalLength / RenderScreen::m_dataSize;
    int x_scale = canvas.width() / intervalLength;

    float max = pData[0];
    for (int i = 0; i < RenderScreen::m_dataSize; ++i)
    {
        if (pData[i] > max) max = pData[i];
    }

    int y_scale = canvas.height() / (4 * max);

    QPoint previousPixel = calculatePoint(0, step, canvas, pData[0], x_scale, y_scale);
    for (int i = 0; i < RenderScreen::m_dataSize; ++i)
    {
        QPoint pixel = calculatePoint(i, step, canvas, pData[i], x_scale, y_scale);
        painter.drawLine(previousPixel, pixel);
        previousPixel = pixel;
    }
}

QPoint Plotter::calculatePoint(int index, float step, QRect &canvas, float data, float x_scale, float y_scale)
{
    QPoint center = canvas.center();
    return QPoint (
                index * step * x_scale,
                data * y_scale + center.y()
                );
}


