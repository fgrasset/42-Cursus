#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->_map = src._map;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange		&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_map = src._map;

	return *this;
}

void				BitcoinExchange::fillMap()
{
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
		throw std::invalid_argument("Error opening the data.csv file");

	std::string	line;
	size_t		comma;
	std::getline(dataFile, line); //discard the first line
	while (std::getline(dataFile, line))
	{
		if ((comma = line.find(",")) == std::string::npos)
			throw std::invalid_argument("Issue in the csv file");
		std::string	date = line.substr(0, comma);
		float		value = std::atof(line.substr(comma + 1).c_str());
		this->_map.insert(std::make_pair(date, value));
	}
}

std::string			BitcoinExchange::trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (first == std::string::npos) {
		return "";
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

float				BitcoinExchange::getValueForDate(std::string date)
{
	std::string earliestDate = this->_map.begin()->first;
	std::map<std::string, float>::iterator	it = this->_map.find(date);

	if (it != this->_map.end())
		return it->second;

	while (it == this->_map.end() && date >= earliestDate) {
		date = previousDate(date);
		it = this->_map.find(date);
	}

	if (it == this->_map.end()) {
		throw std::runtime_error("No value found within valid date range");
	}

	return it->second;
}

std::string			BitcoinExchange::previousDate(std::string &date)
{
	int	year, month, day;

	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
		throw std::runtime_error("Invalid date format");
	}
	day--;

	if (day == 0) {
		month--;
		if (month == 0) {
			year--;
			month = 12;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			day = 30;
		} else if (month == 2) {
			if (year % 400 == 0 || (year % 4 == 0  && year % 100 != 0)) {
				day = 29;
			} else {
				day = 28;
			}
		} else {
			day = 31;
		}
	}

	char buffer[11];
	sprintf(buffer, "%04d-%02d-%02d", year, month, day);

	return std::string(buffer);
}

void				BitcoinExchange::processInput(char *input)
{
	std::ifstream inputFile(input);
	if (!inputFile.is_open())
		throw std::invalid_argument("Error opening the given input file");

	this->fillMap();
	std::string	line;
	size_t		pipe;
	std::getline(inputFile, line); //discard the first line
	if (line != "date | value")
		throw std::invalid_argument( "Issue in the input file not containing proper header");
	while (std::getline(inputFile, line))
	{
		if ((pipe = line.find("|")) == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		double	floatValue;
		double	btcRatio;
		std::string	date = line.substr(0, pipe - 1);
		std::string	value = line.substr(pipe + 1).c_str();
		if (!isDateCorrect(date))
			continue;
		if (!isValueCorrect(value, &floatValue))
			continue;
		btcRatio = getValueForDate(date);
		printResult(date, floatValue, btcRatio);
	}
}

bool				BitcoinExchange::isDateCorrect(std::string &date)
{
	int year, month, day;

	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	if (day > 29 && month == 2) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	} else if (day == 29 && month == 2 &&
				!(year % 400 == 0 || (year % 4 == 0  && year % 100 != 0))) {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	return true;
}

bool				BitcoinExchange::isValueCorrect(std::string &value, double *floatValue)
{
	char	*endptr;

	strtod(value.c_str(), &endptr);
	if (value.empty() || value.c_str() == endptr || *endptr != '\0')
	{
		std::cerr << "Error: not a float" << std::endl;
		return (false);
	}
	*floatValue = atof(value.c_str());
	if (*floatValue < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (*floatValue > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void				BitcoinExchange::printResult(std::string &date, double &floatValue, double &btcRatio)
{
	std::cout << date <<  " => " << floatValue << " = " << (floatValue * btcRatio) << std::endl;
}
