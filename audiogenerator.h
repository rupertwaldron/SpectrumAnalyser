#ifndef AUDIOGENERATOR_H
#define AUDIOGENERATOR_H

#include <QObject>

class RenderScreen;
class AudioGeneratorIODevice;

QT_BEGIN_NAMESPACE
class QAudioInput;
QT_END_NAMESPACE

class AudioGenerator : public QObject
{
    Q_OBJECT
public:
    AudioGenerator(QObject *parent = 0);
    ~AudioGenerator();
    void subscribe(RenderScreen * screen, float *pDataArray, float step);

private:
    RenderScreen *m_renderScreen;
    AudioGeneratorIODevice *m_device;
    QAudioInput *m_audioInput;
signals:

};

#endif // AUDIOGENERATOR_H
