#include "ProximityMonitor.hpp"

#include <Components.hpp>
#include <thread>
#include <chrono>
#include "tof.h"
#include <pigpio.h>

ProximityMonitor::ProximityMonitor(QObject *parent, Components* components)
    : AppBase(parent, components)
{
    qDebug() << "proximity monitor init";
    auto initResult = tofInit(1, 0x29, true);

    int model, revision;
    tofGetModel(&model, &revision);

    gpioSetPWMfrequency(17, 100);

    gpioSetMode(17, PI_OUTPUT);
    gpioWrite(17, PI_HIGH);

    qDebug() <<"Proximity sensor init: "<< (initResult !=1 ? "Failure" : "Success")  << "Model ID/rev:"<<model << "/"<<revision;
}

ProximityMonitor::~ProximityMonitor()
{
    gpioWrite(17, PI_HIGH);
}

void ProximityMonitor::run()
{   
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        auto distance = tofReadDistance();
        if(distance < 1950)
        {
            emit(proximityChange(true));
            qDebug() << "Presence detected: "<<distance;
            gpioPWM(17, 128); //screen at half brightness

            auto f = gpioGetPWMfrequency(17);
            qDebug() << "current pwm frequency: "<<f;

            int counter = 0;
            while(counter <1800)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                counter++;
            }

            emit(proximityChange(false));
        }
        else
        {
            gpioWrite(17, PI_LOW);
            gpioSetPullUpDown(17, PI_PUD_DOWN);
        }
    }
}
