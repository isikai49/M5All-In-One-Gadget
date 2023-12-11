#include "DrUltraSonic.h"
#include <Arduino.h>

DrUltraSonic::DrUltraSonic(int echo_pin, int trig_pin)
{
  m_echo_pin = echo_pin;
  m_trig_pin = trig_pin;
  pinMode(echo_pin, INPUT);
  pinMode(trig_pin, OUTPUT);
}

double DrUltraSonic::measureReturnTime()
{
  double t = 0;

  // 超音波の発生
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // 返ってくるまでの時間測定
  t = pulseIn(echo_pin, HIGH);
  if (t >= 0)
  {
    t = (double)t * 340 * (0.000001) * 0.5 * 100;
  }
  return t;
}