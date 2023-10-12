#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &src) {};

ScalarConverter::~ScalarConverter() {};

ScalarConverter		&ScalarConverter::operator=(const ScalarConverter &src) {return *this;}

bool				isAlpha(char c)
{

}

bool				isDigit(int c)
{
}

// std::stoi() - converts a string to an integer
// std::stof() - converts a string to a float
// std::stod()
int					ScalarConverter::getType(std::string str)
{
	bool	isDouble = false;
	bool	isFloat = false;
	bool	isNegative = false;

	if (str.empty())
		return ERROR;
	if (isAlpha(str[0]) && (str[0] != '-'))
		return CHAR;
	for(char c : str)
	{
		if (isDigit(c))
			continue;
		else if (c == '.' && !isDouble)
			isDouble = true;
		else if (c == 'f' && !isFloat)
		{
			isFloat = true;
			isDouble = false;
		}
		else
			return ERROR;
	}
	// if (isDouble)
}
