#pragma once

class DrUltraSonic
{
private:
    int m_echo_pin;
    int m_trig_pin;

public:
    DrUltraSonic(int echo_pin, int trig_pin);
    double measureReturnTime();
};