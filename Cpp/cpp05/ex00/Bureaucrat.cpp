#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("None"), _grade(150)
{

}

Bureaucrat::Bureaucrat(int grade) : _name("None")
{
	addGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	addGrade(grade);
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
	this->_grade = src._grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
	if (&src == this)
		return *this;

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

std::ostream	&operator<<(std::ostream &ori, Bureaucrat const &src)
{
	ori << src.getName() << ", Bureaucrat grade " << src.getGrade();
	return (ori);
}
