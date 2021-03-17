#include "audiogeneratoriodevice.h"
#include "renderscreen.h"

#include <QTextStream>
#include <QCoreApplication>

static const int rowSize = RenderScreen::m_dataSize;

AudioGeneratorIODevice::AudioGeneratorIODevice(RenderScreen * screen, float *data, float intervalLength, QObject *parent) :
    QIODevice(parent),
    m_renderScreen(screen),
    m_screenData(data),
    m_intervalLength(intervalLength)
{
    qInfo("AudioGeneratorIODevice(float, float *, QObject *)");
}

qint64 AudioGeneratorIODevice::writeData(const char *data, qint64 maxSize)
{
    QTextStream(stdout) << "Max Size = " << maxSize << Qt::endl;
    float value = float(quint8(data[128]) - 128) / 1.28f + 0.01f;
    QTextStream(stdout) << "Value = " << value << Qt::endl;

    for (int i = 0; i < rowSize; ++i) {
//        m_screenData[i] = float(quint8(data[i]) - 128) / 1.28f + 0.01f;
        m_screenData[i] = float(quint8(data[i]) - 128) / 1.28f;
    }

    QCoreApplication::processEvents();
    m_renderScreen->display(m_intervalLength);

//    QTextStream(stdout) << "Data = " << value << Qt::endl;

//    // The amount of new data available.
//    int newDataSize = maxSize / resolution;

//    // If we get more data than array size, we need to adjust the start index for new data.
//    int newDataStartIndex = qMax(0, (newDataSize - rowSize));

//    // Move the old data ahead in the rows (only do first half of rows + middle one now).
//    // If the amount of new data was larger than row size, skip copying.
//    if (!newDataStartIndex) {
//        for (int i = 0; i <= middleRow; i++) {
//            QBarDataItem *srcPos = m_array->at(i)->data();
//            QBarDataItem *dstPos = srcPos + newDataSize;
//            memmove((void *)dstPos, (void *)srcPos, (rowSize - newDataSize) * sizeof(QBarDataItem));
//        }
//    }

//    // Insert data in reverse order, so that newest data is always at the front of the row.
//    int index = 0;
//    for (int i = newDataSize - 1; i >= newDataStartIndex; i--) {
//        // Add 0.01 to the value to avoid gaps in the graph (i.e. zero height bars).
//        // Also, scale to 0...100
//        float value = float(quint8(data[resolution * i]) - 128) / 1.28f + 0.01f;
//        (*m_array->at(middleRow))[index].setValue(value);
//        // Insert a fractional value into front half of the rows.
//        for (int j = 1; j <= middleRow; j++) {
//            float fractionalValue = value / float(j + 1);
//            (*m_array->at(middleRow - j))[index].setValue(fractionalValue);
//        }
//        index++;
//    }

//    // Copy the front half of rows to the back half for symmetry.
//    index = 0;
//    for (int i = rowCount - 1; i > middleRow; i--) {
//        QBarDataItem *srcPos = m_array->at(index++)->data();
//        QBarDataItem *dstPos = m_array->at(i)->data();
//        memcpy((void *)dstPos, (void *)srcPos, rowSize * sizeof(QBarDataItem));
//    }

//    // Reset the proxy array now that data has been updated to trigger a redraw.
//    m_proxy->resetArray(m_array);

    return maxSize;
}

qint64 AudioGeneratorIODevice::readData(char *data, qint64 maxSize)
{
    Q_UNUSED(data)
    Q_UNUSED(maxSize)
    return -1;
}

AudioGeneratorIODevice::~AudioGeneratorIODevice()
{
    qInfo("~AudioGeneratorIODevice()");
}
