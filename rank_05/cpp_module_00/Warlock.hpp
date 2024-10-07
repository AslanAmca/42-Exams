#pragma once

#include <iostream>

using namespace std;

class Warlock
{
private:
	string name;
	string title;

public:
	Warlock(const string &name, const string &title);
	~Warlock();

	const string &getName() const;
	const string &getTitle() const;

	void setTitle(const string &_title);

	void introduce() const;
};
