#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &src)
{
	(void) src;
	*this = src;
}

Intern::~Intern()
{

}

Intern		&Intern::operator=(const Intern &src)
{
	(void) src;
	return *this;
}

Form		*Intern::makePPF(std::string target)
{
	return (new PresidentialPardonForm(target));
}

Form		*Intern::makeRRF(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form		*Intern::makeSCF(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form		*Intern::makeForm(std::string name, std::string target)
{
	Form		*newForm = NULL;
	Form		*ptrFunctions[] = {Intern::makePPF(target), Intern::makeRRF(target), Intern::makeSCF(target)};
	std::string	existingForms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (name == existingForms[i])
		{
			std::cout << "Intern created the Form " << existingForms[i] << std::endl;
			newForm = ptrFunctions[i];
		}
	}
	if (!newForm)
	{
		throw(Intern::NoFormException());
	}
	return newForm;
}
