#pragma once
#include <TinyGPS++.h>
#include <TinyGPSPlus.h>

class MdDateTime
{
private:
    TinyGPSPlus gps;

public:
    MdDateTime();
    String readDate();
    String readTime();
};