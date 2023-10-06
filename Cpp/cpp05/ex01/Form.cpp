#include "Form.hpp"

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

bool		Form::getSign()
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

std::ostream	&operator<<(std::ostream &ori, const Form &src)
{
	ori << src.getName() << ", forms needs grade " << src.getGradeSigned() << " to be signed" << std::endl;
	return (ori);
}
