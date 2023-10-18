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

void				ScalarConverter::getType(std::string str)
{
	bool				isDouble = false;
	bool				isFloat = false;
	std::stringstream	ss(str);

	if (str.empty())
		return printError();
	if (std::isalpha(str[0]) && (str[0] != '-'))
		return printChar(str[0]);
	for(int i = 0; i < (int)str.length(); i++)
	{
		if ((str[0] == '-') && i == 0)
			i++;
		if (std::isdigit(str[i]))
			continue;
		else if (str[i] == '.' && !isDouble)
			isDouble = true;
		else if (str[i] == 'f' && isDouble && !isFloat)
		{
			isFloat = true;
			isDouble = false;
		}
		else
			return printError();
	}
	if (isDouble)
	{
		double	d;
		ss >> d;
		printDouble(d);
	}
	else if (isFloat)
	{
		float	f;
		ss >> f;
		printFloat(f);
	}
	else
	{
		int	i;
		ss >> i;
		printInt(i);
	}
}

void				ScalarConverter::convertInt(int nb)
{
	if (nb < INT_MIN || nb > INT_MAX)
		std::cout << "Int : impossible" << std::endl;
	else
		std::cout << "Int : " << nb << std::endl;
}

void				ScalarConverter::convertDouble(double nb)
{
	std::cout << "Double : " << std::fixed << std::setprecision(1) << nb << std::endl;
}

void				ScalarConverter::convertFloat(float nb)
{
	std::cout << "Float : " << std::fixed << std::setprecision(1) << nb << "f" << std::endl;
}

void				ScalarConverter::convertChar(char nb)
{
	if ((nb >= 0 && nb < 32) || (nb == 127))
		std::cout << "Char : non displayable" << std::endl;
	else if (nb < 0 || nb > 127)
		std::cout << "Char : impossible" << std::endl;
	else
		std::cout << "Char : " << nb << std::endl;
}

void				ScalarConverter::printInt(int nb)
{
	convertChar(static_cast<char>(nb));
	convertInt(nb);
	convertDouble(static_cast<double>(nb));
	convertFloat(static_cast<float>(nb));
}

void				ScalarConverter::printDouble(double nb)
{
	convertChar(static_cast<char>(nb));
	convertInt(static_cast<int>(nb));
	convertDouble(nb);
	convertFloat(static_cast<float>(nb));
}

void				ScalarConverter::printFloat(float nb)
{
	convertChar(static_cast<char>(nb));
	convertInt(static_cast<int>(nb));
	convertDouble(static_cast<double>(nb));
	convertFloat(nb);
}

void				ScalarConverter::printChar(char c)
{
	convertChar(c);
	convertInt(static_cast<int>(c));
	convertDouble(static_cast<double>(c));
	convertFloat(static_cast<float>(c));
}

void				ScalarConverter::printError()
{
	std::cout << "This type conversion is impossible !" << std::endl;
}

void				ScalarConverter::printSpecial(std::string str)
{
	std::cout << "Char : impossible" << std::endl;
	std::cout << "Int : impossible" << std::endl;
	std::cout << "Double : " << str << std::endl;
	std::cout << "Float : " << str << "f" << std::endl;
}

void				ScalarConverter::convert(std::string str)
{
	std::string	special[2][3] = {{"-inf", "+inf", "nan"}, {"-inff", "+inff", "nanf"}};
	bool		flag_spe = false;

	if (std::isalpha(str[0]) && std::isalpha(str[1]))
	{
		printError();
		return ;
	}
	for (int i = 0; i < 3; i++)
	{
		if ((str == special[0][i]) || (str == special[1][i]))
		{
			printSpecial(special[0][i]);
			flag_spe = true;
		}
	}
	if (!flag_spe)
		getType(str);
}
