#pragma once
#include "IContext.h"
class SafeFrame : public IContext
{
public:
    SafeFrame();
    virtual ~SafeFrame() = default;

    void setClock(int hour) override;
    void changeState(IState& state) override;
    void callSecurityCenter(std::string msg) override;
    void recordLog(std::string msg) override;
    void doUse();
    void doAlarm();
    void doPhone();

private:
    mutable IState* currentState_;
    mutable int currentHour_;
};

