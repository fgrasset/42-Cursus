#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", false, 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : Form(src.getName(), src.getState(), src.getGradeSigned(), src.getGradeExecute()), _target(this->getTarget())
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	Form::operator=(*this);
	this->_target = src._target;
	return *this;
}

std::string			RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void				RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->allowed(executor.getGrade()))
		throw(GradeTooLowException());
	if ((rand() % 2) % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " has failed the robotomization" << std::endl;
}
