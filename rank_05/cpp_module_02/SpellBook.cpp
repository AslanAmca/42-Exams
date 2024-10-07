#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	for (map<string, ASpell *>::iterator it = book.begin(); it != book.end(); ++it)
		delete it->second;

	book.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	if (!spell)
		return;

	if (book.find(spell->getName()) != book.end())
		return;

	book[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const string &spellName)
{
	if (book.find(spellName) == book.end())
		return;

	delete book[spellName];
	book.erase(spellName);
}

ASpell *SpellBook::createSpell(const string &spellName)
{
	if (book.find(spellName) != book.end())
		return book[spellName]->clone();

	// nullptr || NULL || 0
	return 0;
}