#include "Str.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "You have not given the correct number of arguments" << std::endl;
		return (0);
	}
	Str	str;
	std::string		nameOutput = av[1];
	nameOutput += ".replace";
	std::ifstream	inputFile(av[1]);
	std::ofstream	outputFile(nameOutput);
	std::string		line;
	str.addString(av[2], av[3]);
	if (inputFile.is_open() && outputFile.is_open())
	{
		while (std::getline(inputFile, str.line))
		{
			str.replaceStr();
			outputFile << str.line << std::endl;
			str.line.clear();
		}
		inputFile.close();
		outputFile.close();
	}
	else
	{
		std::cout << "Failed to open the given File" << std::endl;
	}
	return (0);
}
