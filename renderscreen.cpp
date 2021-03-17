#include "renderscreen.h"

int const RenderScreen::m_dataSize{512};

RenderScreen::RenderScreen(QWidget *parent) :
    QWidget{parent},
    mBackgroundColor{Qt::darkMagenta},
    mLineColor{Qt::yellow},
    pPlotter{new Plotter()},
    pGenerator{new Generator()},
    pAudioGenerator{new AudioGenerator()}
{
    qInfo("RenderScreen(QWidget *)");
}

RenderScreen::~RenderScreen()
{
    delete pPlotter;
    delete pGenerator;
    delete pAudioGenerator;
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

void RenderScreen::startGenerator() {
    pGenerator->subscribe(this, pData, 4 * M_PI);
}

void RenderScreen::startAudio()
{
    pAudioGenerator->subscribe(this, pData, 512);
}

void RenderScreen::display(float intervalLength)
{
    mIntervalLength = intervalLength;
    repaint();
}

void RenderScreen::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setBrush(mBackgroundColor);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setPen(mLineColor);

    auto canvas = this->rect();
    painter.drawRect(canvas);
    pPlotter->plotData(canvas, painter, pData, mIntervalLength);
}
