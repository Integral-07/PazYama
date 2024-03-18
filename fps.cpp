#include "fps.h"
#include "Dxlib.h"

float fps::DeltaTime = 0;
unsigned int PreTime = 0;
void fps::initDeltaTime()
{
    PreTime = GetNowHiPerformanceCount();
    DeltaTime = 0;
}
void fps::setDeltaTime()
{
    unsigned int  curTime = GetNowHiPerformanceCount();
    DeltaTime = (curTime - PreTime) / 1000.0f;
    PreTime = curTime;
}
