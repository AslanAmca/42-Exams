#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	for (map<string, ATarget *>::iterator it = targets.begin(); it != targets.end(); ++it)
		delete it->second;

	targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (!target)
		return;

	if (targets.find(target->getType()) != targets.end())
		return;

	targets[target->getType()] = target->clone();
}

void TargetGenerator::forgetTargetType(const string &targetType)
{
	if (targets.find(targetType) == targets.end())
		return;

	delete targets[targetType];
	targets.erase(targetType);
}

ATarget *TargetGenerator::createTarget(const string &targetType)
{
	if (targets.find(targetType) != targets.end())
		return targets[targetType]->clone();

	// nullptr || NULL || 0
	return 0;
}