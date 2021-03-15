#ifndef RENDERSCREEN_H
#define RENDERSCREEN_H

#include <QWidget>
#include <QColor>
#include "plotter.h"

class RenderScreen final : public QWidget
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
//    void setDataType(DataType *dataType);
//    Plotter plotter() const {return mPlotter;}
//    QPainter & getPainter() {return mPainter;}

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

private:
    QColor mBackgroundColor;
    QColor mLineColor;
    Plotter mPlotter;
};

#endif // RENDERSCREEN_H
