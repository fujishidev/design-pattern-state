#include "SafeFrame.h"
#include "IState.h"
#include "DayState.h"
#include <iostream>

SafeFrame::SafeFrame()
    : currentState_(&DayState::getInstance()), currentHour_(0)
{
}

void SafeFrame::setClock(int hour)
{
    currentHour_ = hour;
    //std::cout << "Œ»ÝŽž‚Í" << currentHour_ << ":00\n";
    if (currentState_)
        currentState_->doClock(*this, hour);
}

void SafeFrame::changeState(IState& state)
{
    //std::cout << "[SafeFrame] ó‘Ô‚ð•ÏX‚µ‚Ü‚·\n";
    currentState_ = &state;
}

void SafeFrame::callSecurityCenter(std::string msg)
{
    std::cout << "call! " << msg << "\n";
}

void SafeFrame::recordLog(std::string msg)
{
    std::cout << "record ... " << msg << "\n";
}

void SafeFrame::doUse()
{
    currentState_->doUse(*this);
}

void SafeFrame::doAlarm()
{
    currentState_->doAlarm(*this);
}

void SafeFrame::doPhone()
{
    currentState_->doPhone(*this);
}