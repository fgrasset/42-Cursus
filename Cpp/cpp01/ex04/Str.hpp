#ifndef STR_HPP
# define STR_HPP

#include <iostream>
#include <istream>
#include <fstream>

class Str
{
	std::string	_s1;
	std::string	_s2;

public:
	Str();
	~Str();
	std::string	line;
	std::string	getS1(void);
	std::string	getS2(void);
	int			s1Size(void);
	void		replaceStr(void);
	int			addString(std::string s1, std::string s2);
};

#endif
