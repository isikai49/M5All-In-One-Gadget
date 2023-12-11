#pragma once

#include "M5All-In-One-Gadget.h"
#include <Arduino.h>

class MdLcd
{
private:

public:
    void displayJpgImage(const char* path);
    void displayJpgImageCoordinate(const char* path, uint16_t x, uint16_t y);
    void clearDisplay();
    void fillBackgroundWhite();
    void displayText(const char* text, int x, int y);
    void displayDateText(String text, int x, int y);
};