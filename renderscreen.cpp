#include "renderscreen.h"
#include <QPaintEvent>
#include <QPainter>

RenderScreen::RenderScreen(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(QColor (0, 0, 255)),
    mLineColor(255, 255, 255),
    mPlotter(Plotter())
{
    qInfo("RenderScreen(QWidget *)");
}

RenderScreen::~RenderScreen()
{
//    delete mDataType;
    qInfo("~RenderScreen()");
}

QSize RenderScreen::minimumSizeHint() const
{
    return QSize(400, 400);
}

QSize RenderScreen::sizeHint() const
{
    return QSize(400, 400);
}

void RenderScreen::startGenerator()
{

}

void RenderScreen::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(mBackgroundColor);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(mLineColor);

    auto canvas = this->rect();

    float myData[256];

    painter.drawRect(canvas);
    mPlotter.plotData(canvas, painter, myData);
}
