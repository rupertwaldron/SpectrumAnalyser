#include "audiogenerator.h"
#include "renderscreen.h"
#include "audiogeneratoriodevice.h"

#include <QtMultimedia/QAudioDeviceInfo>
#include <QtMultimedia/QAudioInput>

AudioGenerator::AudioGenerator(QObject *parent) :
    QObject(parent),
    m_device(0),
    m_audioInput(0)
{
//    QAudioDeviceInfo inputDevice = QAudioDeviceInfo::defaultInputDevice();
    qInfo("~AudioGenerator(QObject *)");
}

AudioGenerator::~AudioGenerator()
{
    qInfo("~AudioGenerator()");
}

void AudioGenerator::subscribe(RenderScreen * screen, float *pDataArray, float step)
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals;
    m_renderScreen = screen;
    qInfo("Render Screen subscribed");
    for (int i = 0; i < 10; ++i) {
//         std::thread gen([&]{generateData(step, pDataArray);});
//         sleep_for(1s);
//         gen.join();
//         QCoreApplication::processEvents();
         m_renderScreen->display();
    }
}
