#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(const ScalarConverter &src) {(void) src;};

ScalarConverter::~ScalarConverter() {};

ScalarConverter		&ScalarConverter::operator=(const ScalarConverter &src) {(void) src; return *this;}

void				ScalarConverter::getType(std::string str)
{
	bool				isDouble = false;
	bool				isFloat = false;
	std::stringstream	ss(str);

	if (str.empty())
		return printError();
	if (std::isalpha(str[0]) && str.size() == 1)
		return printChar();
	for(int i = 0; i < (int)str.length(); i++)
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
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
		printDouble(atof(str.c_str()));
	}
	else if (isFloat)
	{
		printFloat(atof(str.c_str()));
	}
	else
	{
		printInt(std::atoi(str.c_str()));
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

void ScalarConverter::convertChar(char nb)
{
	std::cout << "number: " << nb << std::endl;
	if ((nb < 32 || nb == 127) && !(nb >= '0' && nb <= '9')) {
		std::cout << "testing" << std::endl;
	std::cout << "Char: Non-displayable" << std::endl;
	} else if (nb > 127) {
		std::cout << "Char: Impossible" << std::endl;
	} else {
		std::cout << "Char: '" << nb << "'" << std::endl; // Added quotes for clarity
	}
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

	if (std::isalpha(str[0]) && std::isalpha(str[1]) && strcmp(str.c_str(), "nan") && strcmp(str.c_str(), "nanf"))
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
