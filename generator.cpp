#include "generator.h"
#include "renderscreen.h"

#include <QCoreApplication>

Generator::Generator()
{
    qInfo("Generator()");
}

Generator::~Generator()
{
    qInfo("~Generator()");
}


void Generator::generateData(float step, float *pDataArray) {
//    isReady = false;
    double randA = QRandomGenerator::global()->bounded(1.0);
    double randB = QRandomGenerator::global()->bounded(1.0);
    double randC = QRandomGenerator::global()->bounded(1.0);
    double randD = QRandomGenerator::global()->bounded(1.0);
    double randE = QRandomGenerator::global()->bounded(1.0);
    for (int i = 0; i < 256; ++i) {
        float t = i * step;
        pDataArray[i] = sin(t) + randA * sin(3 * t) + randB * sin(5 * t) + randC * sin(7 * t) + randD * sin(9 * t) + randE * sin(11 * t);
    }
//    using namespace std::this_thread;     // sleep_for, sleep_until
//    using namespace std::chrono_literals;
//    sleep_for(1s);
//    isReady = true;
}

bool Generator::dataReady()
{
    return isReady;
}

void Generator::subscribe(RenderScreen * screen, float *pDataArray, float step)
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals;
    pRenderScreen = screen;
    qInfo("Render Screen subscribed to Data Generator");
    for (int i = 0; i < 10; ++i) {
         std::thread gen([&]{generateData(step, pDataArray);});
         sleep_for(1s);
         gen.join();
         QCoreApplication::processEvents();
         pRenderScreen->display();
    }
}

