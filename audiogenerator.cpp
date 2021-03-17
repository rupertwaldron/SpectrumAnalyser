#include "audiogenerator.h"
#include "renderscreen.h"
#include "audiogeneratoriodevice.h"

#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioInput>
#include <QCoreApplication>

AudioGenerator::AudioGenerator(QObject *parent) :
    QObject(parent),
    m_device(0),
    m_audioInput(0)
{
    qInfo("~AudioGenerator(QObject *)");
}


void AudioGenerator::subscribe(RenderScreen * screen, float *pDataArray, float intervalLength)
{
    m_renderScreen = screen;
    qInfo("Render Screen subscribed to AudioGenerator");
    setUpAudio(pDataArray, intervalLength);
}

void AudioGenerator::setUpAudio(float *pDataArray, float intervalLength)
{
    qInfo("Setting up Audio");
    QAudioDeviceInfo inputDevice = QAudioDeviceInfo::defaultInputDevice();

    if (inputDevice.supportedSampleRates().size() > 0
            && inputDevice.supportedChannelCounts().size() > 0
            && inputDevice.supportedSampleSizes().size() > 0
            && inputDevice.supportedCodecs().size() > 0) {
        QAudioFormat formatAudio;
        formatAudio.setSampleRate(inputDevice.supportedSampleRates().at(0));
        formatAudio.setChannelCount(inputDevice.supportedChannelCounts().at(0));
        formatAudio.setSampleSize(inputDevice.supportedSampleSizes().at(0));
        formatAudio.setCodec(inputDevice.supportedCodecs().at(0));
        formatAudio.setByteOrder(QAudioFormat::LittleEndian);
        formatAudio.setSampleType(QAudioFormat::UnSignedInt);

        m_audioInput = new QAudioInput(inputDevice, formatAudio, this);
#ifdef Q_OS_MAC
        // OS X seems to wait for entire buffer to fill before calling writeData, so use smaller buffer
        m_audioInput->setBufferSize(RenderScreen::m_dataSize);
#else
        m_audioInput->setBufferSize(1024);
#endif
        m_device = new AudioGeneratorIODevice(m_renderScreen, pDataArray, intervalLength, this);
        m_device->open(QIODevice::WriteOnly);

        m_audioInput->start(m_device);
    } else {
        // No graph content can be shown, so add a custom warning label
      qInfo("No valid audio device found");
    }
}


AudioGenerator::~AudioGenerator()
{
    qInfo("~AudioGenerator()");
    if (m_audioInput)
        m_audioInput->stop();
    if (m_device)
        m_device->close();
    delete m_device;
}
