#pragma once

#include "M5All-In-One-Gadget.h"
#include "DrTHSensor.h"



class MdWBGTMonitor
{
private:

public:
void init();
void getWBGT(double* temperature, double* humidity, WbgtIndex* index);
};