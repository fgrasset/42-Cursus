#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
	std::string	_target;

	public:
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &src);

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);
		std::string			getTarget() const;
		void				execute(Bureaucrat const &executor) const;
};

#endif
