#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#define CHAR 0
#define INT 1
#define DOUBLE 2
#define FLOAT 3
#define ERROR 4

class ScalarConverter
{
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &src);

	ScalarConverter	&operator=(const ScalarConverter &src);
	static bool		isAlpha(char c);
	static bool		isDigit(char c);
	static int		getType(std::string str);
	static void		printDouble(double nb);
	static void		printInt(int nb);
	static void		printFloat(float nb);
	static void		printChar(char c);
	static void		printAll(int nbInt, double nbDouble, float nbFloat, char nbChar);

	public:
		static void	convert(std::string str);
};

#endif
