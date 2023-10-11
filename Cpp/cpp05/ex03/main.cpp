#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern		basicIntern;
	Form		*SCF;
	Form		*RRF;
	Form		*PPF;
	Form		*RRF_copy;
	Form		*WOW;


	try {
		SCF = basicIntern.makeForm("ShrubberyCreationForm", "garden");
		RRF = basicIntern.makeForm("RobotomyRequestForm", "target_robot");
		PPF = basicIntern.makeForm("PresidentialPardonForm", "criminal");
		RRF_copy = RRF;

		std::cout << *SCF << std::endl;
		std::cout << *RRF << std::endl;
		std::cout << *PPF << std::endl;
		std::cout << *RRF_copy << std::endl;
		delete SCF;
		delete RRF;
		delete PPF;

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try
	{
		WOW = basicIntern.makeForm("WOW", "haha");
		if (WOW)
		{
			std::cout << *WOW << std::endl;
			delete WOW;
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
