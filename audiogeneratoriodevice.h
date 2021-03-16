#ifndef AUDIOGENERATORIODEVICE_H
#define AUDIOGENERATORIODEVICE_H

#include <QIODevice>
#include <QObject>

class RenderScreen;

class AudioGeneratorIODevice : public QIODevice
{
    Q_OBJECT
    RenderScreen * m_renderScreen;
public:
    AudioGeneratorIODevice(RenderScreen *screen, QObject *parent = 0);
    ~AudioGeneratorIODevice();

protected:
    qint64 readData(char *data, qint64 maxSize) Q_DECL_OVERRIDE;
    qint64 writeData(const char *data, qint64 maxSize) Q_DECL_OVERRIDE;
};

#endif // AUDIOGENERATORIODEVICE_H
