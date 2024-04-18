#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream	inputFile(filename);
	if (!inputFile) {
		std::cerr << "Failed to open the file." << std::endl;
		return ;
	}

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange		&BitcoinExchange::operator=(const BitcoinExchange &src)
{

}

void				BitcoinExchange::checkError(int file)
{

}

void				BitcoinExchange::fillMap(std::ifstream &inputFile)
{

}

void				BitcoinExchange::findDate(std::string date)
{

}

int					BitcoinExchange::previousDate(std::string date)
{

}
