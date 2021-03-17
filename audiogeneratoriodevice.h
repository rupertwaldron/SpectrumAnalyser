#ifndef AUDIOGENERATORIODEVICE_H
#define AUDIOGENERATORIODEVICE_H

#include <QIODevice>
#include <QObject>

class RenderScreen;

class AudioGeneratorIODevice : public QIODevice
{
    Q_OBJECT
public:
    AudioGeneratorIODevice(RenderScreen * screen, float *data, float intervalLength, QObject *parent = 0);
    ~AudioGeneratorIODevice();

protected:
    qint64 readData(char *data, qint64 maxSize) Q_DECL_OVERRIDE;
    qint64 writeData(const char *data, qint64 maxSize) Q_DECL_OVERRIDE;

private:
    RenderScreen *m_renderScreen;
    float *m_screenData;
    float m_intervalLength;
};

#endif // AUDIOGENERATORIODEVICE_H
