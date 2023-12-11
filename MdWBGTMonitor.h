#pragma once

class MdWBGTMonitor
{
private:

public:
void init();
void getWBGT(double* temperature, double* humidity, WbgtIndex* index);
};