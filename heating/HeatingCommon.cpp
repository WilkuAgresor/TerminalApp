#include "HeatingCommon.hpp"
#include <../common/subsystems/heating/HeatingDictionary.hpp>

QString formatTemperature(qint16 temp)
{
    QString text;
    if(temp == TEMPERATURE_INVALID)
    {
        text = "--.-";
    }
    else
    {
        double dTemp = static_cast<double>(temp)/100;
        text = QString().setNum(dTemp, 'f', 1);
    }
    text.append('\xB0');
    text.append(" C");
    return text;
}
