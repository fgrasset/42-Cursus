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
	_s1 = s1;
	_s2 = s2;
	return (1);
}

/* if the old string is found, it replaces it with the newer */
void	Str::replaceStr(void)
{
	int		j = _s1.size();
	size_t	pos = 0;

	while ((pos = line.find(_s1, pos)) != std::string::npos)
	{
		std::string sub = line.substr(pos, j);
		line.erase(pos, j);
		line.insert(pos, _s2);
		pos++;
	}
}

/* return the size of the string _s1 */
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

