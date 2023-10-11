#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public Form
{
	std::string	_target;

	public:
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &src);

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
		std::string				getTarget();
		void					execute(Bureaucrat const &executor) const;
};

#endif
