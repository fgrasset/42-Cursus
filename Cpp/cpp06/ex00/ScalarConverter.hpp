#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
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
	bool			isAlpha(char c);
	bool			isDigit(int c);
	int				getType(std::string str);
	void			printConversion(int type, std::string str);
};

#endif
