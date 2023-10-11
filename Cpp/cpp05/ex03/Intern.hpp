#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	Form	*makePPF(std::string target);
	Form	*makeRRF(std::string target);
	Form	*makeSCF(std::string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern &src);

		Intern	&operator=(const Intern &src);
		Form	*makeForm(std::string name, std::string target);
		class NoFormException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("There is no such Form available");
				}
		};
};

#endif
