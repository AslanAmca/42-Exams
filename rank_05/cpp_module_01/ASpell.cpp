#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell(const string &name, const string &effects) : name(name), effects(effects)
{
}

ASpell::~ASpell()
{
}

const string &ASpell::getName() const
{
	return name;
}

const string &ASpell::getEffects() const
{
	return effects;
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
