#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("None"), _grade(150)
{

}

Bureaucrat::Bureaucrat(int grade) : _name("None")
{
	addGrade(grade);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	addGrade(grade);
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	this->_grade = src._grade;
	this->_name = src._name;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (&src == this)
		return *this;

	this->_name = src._name;
	this->_grade = src._grade;
	return *this;
}

void	Bureaucrat::addGrade(int grade)
{
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void		Bureaucrat::decrement()
{
	std::cout << "decrementation" << std::endl;
	if (this->_grade == 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

void		Bureaucrat::increment()
{
	std::cout << "incrementation" << std::endl;
	if (this->_grade == 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void		Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout <<this->getName() << " couldn't sign the form " << form.getName() << " because grade is too low" << std::endl;
	}
}

void		Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " could not execute the form " << form.getName() << std::endl;
	}

}

std::ostream	&operator<<(std::ostream &ori, Bureaucrat const &src)
{
	ori << src.getName() << ", Bureaucrat grade " << src.getGrade();
	return (ori);
}
