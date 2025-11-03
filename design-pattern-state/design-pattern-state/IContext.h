#pragma once
#include <string>

class IState;

class IContext
{
public:
    virtual ~IContext() = default;
    virtual void setClock(int hour) = 0;
    virtual void changeState(IState& state) = 0;
    virtual void callSecurityCenter(std::string msg) = 0;
    virtual void recordLog(std::string msg) = 0;
};