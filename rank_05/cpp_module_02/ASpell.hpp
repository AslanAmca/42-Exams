#pragma once

#include <iostream>

using namespace std;

class ATarget;

class ASpell
{
protected:
	string name;
	string effects;

public:
	ASpell(const string &name, const string &effects);
	virtual ~ASpell();

	virtual ASpell *clone() const = 0;

	const string &getName() const;
	const string &getEffects() const;

	void launch(const ATarget &target) const;
};