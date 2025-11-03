#pragma once
class IContext;

class IState
{
public:
    virtual ~IState() = default;
    virtual void doClock(IContext& context, int hour) const = 0;
    virtual void doUse(IContext& context) const = 0;
    virtual void doAlarm(IContext& context) const = 0;
    virtual void doPhone(IContext& context) const = 0;
};

