#pragma once

#include "ASpell.hpp"
#include <map>

class SpellBook
{
private:
	map<string, ASpell *> book;

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *spell);
	void forgetSpell(const string &spellName);
	ASpell *createSpell(const string &spellName);
};