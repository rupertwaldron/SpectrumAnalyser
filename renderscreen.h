#ifndef RENDERSCREEN_H
#define RENDERSCREEN_H

#include <QWidget>
#include <QColor>
#include "plotter.h"
#include "generator.h"
#include <QPaintEvent>

class RenderScreen : public QWidget
{
    Q_OBJECT
public:
    explicit RenderScreen(QWidget *parent = nullptr);
    ~RenderScreen();
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    void setBackgroundColor(QColor color) {mBackgroundColor = color;}
    QColor backgroundColor() const {return mBackgroundColor;}
    void setLineColor(QColor color) {mLineColor = color;}
    QColor lineColor() const {return mLineColor;}
    void startGenerator();
    void display();
protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

private:
    QColor mBackgroundColor;
    QColor mLineColor;
    Plotter *pPlotter;
    Generator *pGenerator;
    float *pData{new float[256]};
    float mIntervalLength{4 * M_PI};
    float mScale{40};
    int mStepCount{256};
};

#endif // RENDERSCREEN_H
