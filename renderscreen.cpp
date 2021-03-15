#include "renderscreen.h"

RenderScreen::RenderScreen(QWidget *parent) :
    QWidget{parent},
    mBackgroundColor{QColor (0, 0, 255)},
    mLineColor{255, 255, 255},
    pPlotter{new Plotter()},
    pGenerator{new Generator()}
{
    qInfo("RenderScreen(QWidget *)");
}

RenderScreen::~RenderScreen()
{
    delete pPlotter;
    delete pGenerator;
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
    pPlotter->plotData(canvas, painter, myData);
}
