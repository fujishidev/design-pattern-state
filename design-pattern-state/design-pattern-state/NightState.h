#pragma once
#include "IState.h"
class NightState : public IState
{
public:
	static NightState& getInstance()
	{
		static NightState instance;
		return instance;
	}

	void doClock(IContext& context, int hour) const override;
	void doUse(IContext& context) const override;
	void doAlarm(IContext& context) const override;
	void doPhone(IContext& context) const override;

private:
	NightState() = default;
	NightState(const NightState&) = delete;
	NightState& operator=(const NightState&) = delete;
};

