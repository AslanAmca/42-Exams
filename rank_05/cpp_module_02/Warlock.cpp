#include "Warlock.hpp"

Warlock::Warlock(const string &name, const string &title) : name(name), title(title)
{
	cout << name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock()
{
	cout << name << ": My job here is done!" << endl;
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
	spellBook.learnSpell(spell);
}

void Warlock::forgetSpell(string spellName)
{
	spellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(string spellName, const ATarget &target)
{
	ASpell *spell = spellBook.createSpell(spellName);

	if (!spell)
		return;

	spell->launch(target);
	delete spell;
}