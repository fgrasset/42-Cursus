#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{

	Bureaucrat highGradeBureaucrat("HighGradeBureaucrat", 5);
	Bureaucrat lowGradeBureaucrat("LowGradeBureaucrat", 145);

	ShrubberyCreationForm shrubberyForm("garden");
	RobotomyRequestForm robotomyForm("target_robot");
	PresidentialPardonForm pardonForm("criminal");

	try {
		highGradeBureaucrat.signForm(shrubberyForm);
		highGradeBureaucrat.signForm(robotomyForm);
		highGradeBureaucrat.signForm(pardonForm);

		highGradeBureaucrat.executeForm(shrubberyForm);
		highGradeBureaucrat.executeForm(robotomyForm);
		highGradeBureaucrat.executeForm(pardonForm);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		lowGradeBureaucrat.signForm(shrubberyForm);
		lowGradeBureaucrat.signForm(robotomyForm);
		lowGradeBureaucrat.signForm(pardonForm);

		lowGradeBureaucrat.executeForm(shrubberyForm);
		lowGradeBureaucrat.executeForm(robotomyForm);
		lowGradeBureaucrat.executeForm(pardonForm);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
