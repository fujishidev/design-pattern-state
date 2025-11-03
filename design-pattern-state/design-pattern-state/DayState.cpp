#include "DayState.h"
#include "NightState.h"
#include "IContext.h"
#include <iostream>
#include <string>

void DayState::doClock(IContext& context, int hour) const
{
    if (hour < 9 || hour >= 17) {
        context.changeState(NightState::getInstance());
    }
}

void DayState::doUse(IContext& context) const
{
    context.recordLog("金庫使用(昼間)");
}

void DayState::doAlarm(IContext& context) const
{
    context.callSecurityCenter("非常ベル(昼間)");
}

void DayState::doPhone(IContext& context) const
{
    context.callSecurityCenter("通常の通話(昼間)");
}
