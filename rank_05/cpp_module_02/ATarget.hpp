#pragma once

#include <iostream>

using namespace std;

class ASpell;

class ATarget
{
protected:
	string type;

public:
	ATarget(const string &type);
	virtual ~ATarget();

	virtual ATarget *clone() const = 0;

	const string &getType() const;

	void getHitBySpell(const ASpell &spell) const;
};