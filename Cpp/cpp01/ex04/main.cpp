#include "Str.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "you have not given the correct number of arguments" << std::endl;
		return (0);
	}
	Str	str;
	std::string		nameOutput = av[1];
	nameOutput += ".replace";
	std::ifstream	inputFile(av[1]);
	std::ofstream	outputFile(nameOutput);
	std::string		line;
	std::string		modifiedLine;
	str.addString(av[2], av[3]);
	if (inputFile.is_open() && outputFile.is_open())
	{
		while (std::getline(inputFile, line))
		{
			size_t	startPos = 0;
			size_t	pos = line.find(str.getS1());
			while (pos != std::string::npos)
			{
				std::cout << "test\n";
				modifiedLine += line.substr(startPos, pos - startPos);
				modifiedLine += str.getS2();
				startPos += str.s1Size();
				pos = line.find(str.getS1(), startPos);
			}
			modifiedLine += line.substr(startPos);
			outputFile << modifiedLine << '\n';
			modifiedLine.clear();
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
