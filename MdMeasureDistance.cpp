#include "MdMeasureDistance.h"
#include "DrUltraSonic.h"

DrUltraSonic drul;

double getDistance()
{
    double distance = drul.measureReturnTime();
    if (distance >= 0)
    {
        distance = distance * 340 * (0.000001) * 0.5 * 100;
    }

    return distance;
}