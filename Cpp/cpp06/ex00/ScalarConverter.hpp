#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class ScalarConverter
{
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);

	ScalarConverter	&operator=(const ScalarConverter &src);
	static void		getType(std::string str);
	static void		convertInt(int nb);
	static void		convertDouble(double nb);
	static void		convertFloat(float nb);
	static void		convertChar(char nb);
	static void		printInt(int nb);
	static void		printDouble(double nb);
	static void		printFloat(float nb);
	static void		printChar(char c);
	static void		printError();
	static void		printSpecial(std::string str);

	public:
		static void	convert(std::string str);
};

#endif
