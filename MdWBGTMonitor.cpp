#include "MdWBGTMonitor.h"
#include <Arduino.h>

DrTHSensor dthsen;

void MdWBGTMonitor::init()
{
    dthsen.init();
}

void MdWBGTMonitor::getWBGT(double* temperature, double* humidity, WbgtIndex* index)
{
    dthsen.getTempHumi(double* temperature, double* humidity);

    index = 0.68 * temperature + 0.12 * humidity;

    if(index <= 15){

    }
    else if(15 < index <= 24){

    }
    else if(24 < index <= 27){

    }
    else if(27 < index <= 30){

    }
    else if(31 <= index){

    }
}