#include "AForm.hpp"

Form::Form() : _name("None"), _sign(false), _gradeSigned(30), _gradeExecute(10)
{

}

Form::Form(const std::string name) : _name(name), _sign(false), _gradeSigned(30), _gradeExecute(10)
{

}

Form::Form(const std::string name, bool sign, const int gradeSigned, const int gradeExecute) : _name(name), _sign(sign), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute)
{
	checkGrade();
}

Form::Form(const Form &src) : _name(src._name), _sign(src._sign), _gradeSigned(src._gradeSigned), _gradeExecute(src._gradeExecute)
{

}

Form::~Form()
{

}

Form	&Form::operator=(const Form &src)
{
	if (this == &src) {
		return *this;
	}
	this->_sign = src._sign;
	return *this;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool		Form::getState() const
{
	return this->_sign;
}

int			Form::getGradeSigned() const
{
	return this->_gradeSigned;
}

int			Form::getGradeExecute() const
{
	return this->_gradeExecute;
}

void		Form::checkGrade()
{
	if ((this->_gradeExecute < 1) || (this->_gradeSigned < 1))
		throw(Form::GradeTooHighException());
	else if ((this->_gradeExecute > 150) || (this->_gradeSigned > 150))
		throw(Form::GradeTooLowException());
}

void		Form::beSigned(Bureaucrat &pers)
{
	if (pers.getGrade() > this->getGradeSigned())
		throw(Form::GradeTooLowException());
	else
		this->_sign = true;
}

bool		Form::allowed(const int grade) const
{
	if (grade > this->getGradeSigned() || grade > this->getGradeExecute())
	{
		return false;
	}
	else
		return true;
}

std::ostream	&operator<<(std::ostream &ori, Form &src)
{
	ori << "Name of the form: " << src.getName() << std::endl;
	ori << "Needed grade to sign: " << src.getGradeSigned() << std::endl;
	ori << "Needed grade to execute: " << src.getGradeExecute() << std::endl;
	if (src.getState())
		ori << "Form has been signed" << std::endl;
	else
		ori << "Form is not signed" << std::endl;
	return (ori);
}
