#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
	std::string	_target;

	public:
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &src);

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
		std::string				getTarget() const;
		void					execute(Bureaucrat const &executor) const;
};

#endif
