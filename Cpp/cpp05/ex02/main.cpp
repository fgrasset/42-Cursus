#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "Basic first test" << std::endl;
	try
	{
		Bureaucrat	prs1 = Bureaucrat("John", 150);
		std::cout << prs1 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's try a grade of 151" << std::endl;
	try
	{
		Bureaucrat	prs2 = Bureaucrat(151);
		std::cout << prs2 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's play with the incrementation and decrementation" << std::endl;
	try
	{
		Bureaucrat	prs3 = Bureaucrat("Paul", 2);
		std::cout << prs3 << std::endl;
		prs3.decrement();
		std::cout << prs3 << std::endl;
		prs3.increment();
		prs3.increment();
		prs3.increment();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

}
