#pragma once

#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
private:
	string name;
	string title;
	map<string, ASpell *> spells;

public:
	Warlock(const string &name, const string &title);
	~Warlock();

	const string &getName() const;
	const string &getTitle() const;

	void setTitle(const string &_title);

	void introduce() const;

	void learnSpell(ASpell *spell);
	void forgetSpell(string spellName);
	void launchSpell(string spellName, const ATarget &target);
};
