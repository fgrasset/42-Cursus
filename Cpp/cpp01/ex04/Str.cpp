#include "Str.hpp"


Str::Str()
{
}

Str::~Str()
{
}

/* checks that the 2 strings are the same size and then adds them to the class */
int		Str::addString(std::string s1, std::string s2)
{
	if (s1.length() != s2.length())
		return (0);
	_s1 = s1;
	_s2 = s2;
	return (1);
}

/* retrusn teh size of the string _s1 */
int	Str::s1Size(void)
{
	return (_s1.length());
}

std::string	Str::getS1(void)
{
	return (_s1);
}

std::string	Str::getS2(void)
{
	return (_s2);
}

