#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
	std::map<std::string, float>	_map;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &src);
		void			fillMap();
		float			getValueForDate(std::string date);
		std::string		previousDate(std::string &date);
		void			processInput(char *input);
		bool			isDateCorrect(std::string &date);
		bool			isValueCorrect(std::string &value, double *floatValue);
		void			printResult(std::string &date, double &floatValue, double &btcRatio);
		std::string		trim(const std::string& str);
};

#endif
