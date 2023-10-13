#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &src) {(void) src;};

ScalarConverter::~ScalarConverter() {};

ScalarConverter		&ScalarConverter::operator=(const ScalarConverter &src) {(void) src; return *this;}

bool				ScalarConverter::isAlpha(char c)
{
	if (c < 32 || c > 126)
		return false;
	return true;
}

bool				ScalarConverter::isDigit(char c)
{
	if (c < 48 || c > 57)
		return false;
	return true;
}

// std::stoi() - converts a string to an integer
// std::stof() - converts a string to a float
// std::stod()
int					ScalarConverter::getType(std::string str)
{
	bool	isDouble = false;
	bool	isFloat = false;

	if (str.empty())
		return ERROR;
	if (std::isalpha(str[0]) && (str[0] != '-'))
		return CHAR;
	std::cout << "test" << std::endl;
	for(int i = 0; i < (int)str.length(); i++)
	{
		if ((str[0] == '-') && i == 0)
			i++;
		if (isDigit(str[i]))
			continue;
		else if (str[i] == '.' && !isDouble)
			isDouble = true;
		else if (str[i] == 'f' && isDouble && !isFloat)
		{
			isFloat = true;
			isDouble = false;
		}
		else
			return ERROR;
	}
	if (isDouble)
		return DOUBLE;
	else if (isFloat)
		return FLOAT;
	else
	{
		printInt(std::stoi(str));
		return 0;
	}
}

void				ScalarConverter::printInt(int nb)
{
	double	nbDouble = static_cast<double>(nb);
	float	nbFloat = static_cast<float>(nb);
	char	nbChar = static_cast<char>(nb);

	printAll(nb, nbDouble, nbFloat, nbChar);
}

void				ScalarConverter::printDouble(double nb)
{
	int		nbInt = static_cast<int>(nb);
	float	nbFloat = static_cast<float>(nb);
	char	nbChar = static_cast<char>(nb);

	printAll(nbInt, nb, nbFloat, nbChar);
}

void				ScalarConverter::printFloat(float nb)
{
	int		nbInt = static_cast<int>(nb);
	double	nbDouble = static_cast<double>(nb);
	char	nbChar = static_cast<char>(nb);

	printAll(nbInt, nbDouble, nb, nbChar);
}

void				ScalarConverter::printChar(char c)
{
	int		nbInt = static_cast<int>(c);
	double	nbDouble = static_cast<double>(c);
	float	nbFloat = static_cast<float>(c);

	printAll(nbInt, nbDouble, nbFloat, c);
}

void				ScalarConverter::printAll(int nbInt, double nbDouble, float nbFloat, char nbChar)
{
	std::cout << "Int : " << nbInt << std::endl;
	std::cout << "Double : " << nbDouble << std::endl;
	std::cout << "Float : " << nbFloat << std::endl;
	std::cout << "Char : " << nbChar << std::endl;
}

void				ScalarConverter::convert(std::string str)
{
	getType(str);
}
