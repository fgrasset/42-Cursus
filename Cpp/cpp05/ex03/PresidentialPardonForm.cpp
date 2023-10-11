#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", false, 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : Form(src.getName(), src.getState(), src.getGradeSigned(), src.getGradeExecute()), _target(this->getTarget())
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	Form::operator=(src);
	this->_target = src._target;
	return *this;
}

std::string				PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void					PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->allowed(executor.getGrade()))
		throw(GradeTooLowException());
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
