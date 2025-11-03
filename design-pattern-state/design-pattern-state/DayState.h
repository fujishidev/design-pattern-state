#pragma once
#include "IState.h"
class DayState : public IState
{
public:
	static DayState& getInstance()
	{
		static DayState instance;
		return instance;
	}

	void doClock(IContext& context, int hour) const override;
	void doUse(IContext& context) const override;
	void doAlarm(IContext& context) const override;
	void doPhone(IContext& context) const override;

private:
	DayState() = default;
	DayState(const DayState&) = delete;
	DayState& operator=(const DayState&) = delete;
};

