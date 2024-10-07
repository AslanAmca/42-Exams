#include "Warlock.hpp"

Warlock::Warlock(const string &name, const string &title) : name(name), title(title)
{
	cout << name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock()
{
	cout << name << ": My job here is done!" << endl;

	for (map<string, ASpell *>::iterator it = spells.begin(); it != spells.end(); ++it)
		delete it->second;

	spells.clear();
}

const string &Warlock::getName() const
{
	return name;
}

const string &Warlock::getTitle() const
{
	return title;
}

void Warlock::setTitle(const string &_title)
{
	title = _title;
}

void Warlock::introduce() const
{
	cout << name << ": I am " << name << ", " << title << "!" << endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (!spell)
		return;

	if (spells.find(spell->getName()) != spells.end())
		return;

	spells[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(string spellName)
{
	if (spells.find(spellName) == spells.end())
		return;

	delete spells[spellName];
	spells.erase(spellName);
}

void Warlock::launchSpell(string spellName, const ATarget &target)
{
	if (spells.find(spellName) == spells.end())
		return;

	spells[spellName]->launch(target);
}
