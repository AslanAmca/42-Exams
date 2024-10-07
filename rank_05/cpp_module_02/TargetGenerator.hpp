#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
private:
	map<string, ATarget *> targets;

public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget *target);
	void forgetTargetType(const string &targetType);
	ATarget *createTarget(const string &targetType);
};