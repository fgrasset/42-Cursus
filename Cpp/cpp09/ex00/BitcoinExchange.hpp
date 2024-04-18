#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange
{
	std::map<std::string, double>	_map;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &src);
		void	checkError(int file);	//Check to open the file and if there is any error doing so
		void	fillMap(std::ifstream &inputFile);				//fills the map with the data.csv file
		void	findDate(std::string date);		//checks in the map to find the correct date, if it doesn't find it, used previousDate() to get previous date and checks again
		int		previousDate(std::string date); //gets the previous date based on needed dates format
};

#endif
