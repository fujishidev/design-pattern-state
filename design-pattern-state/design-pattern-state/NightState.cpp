#include "NightState.h"
#include "DayState.h"
#include "IContext.h"
#include <iostream>
#include <string>

void NightState::doClock(IContext& context, int hour) const
{
    if (9 <= hour && hour < 17) {
        context.changeState(DayState::getInstance());
    }
}

void NightState::doUse(IContext& context) const
{
    context.recordLog("非常：夜間の金庫使用！");
}

void NightState::doAlarm(IContext& context) const
{
    context.callSecurityCenter("非常ベル(夜間)");
}

void NightState::doPhone(IContext& context) const
{
    context.callSecurityCenter("夜間の通話録音");
}
