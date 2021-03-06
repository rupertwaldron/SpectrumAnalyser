#ifndef AUDIOGENERATORIODEVICE_H
#define AUDIOGENERATORIODEVICE_H

#include <QIODevice>
#include <QObject>

class RenderScreen;

class AudioGeneratorIODevice : public QIODevice
{
    Q_OBJECT
public:
    AudioGeneratorIODevice(RenderScreen * screen, float step, float *data, QObject *parent = 0);
    ~AudioGeneratorIODevice();

protected:
    qint64 readData(char *data, qint64 maxSize) Q_DECL_OVERRIDE;
    qint64 writeData(const char *data, qint64 maxSize) Q_DECL_OVERRIDE;

private:
    float m_step;
    float *m_screenData;
    RenderScreen *m_renderScreen;
};

#endif // AUDIOGENERATORIODEVICE_H
