#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "AForm.hpp"

class Form;

class Bureaucrat
{
	std::string	_name;
	int			_grade;

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Grade is too low");
			}
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Grade is too high");
			}
	};
	public:
		Bureaucrat();
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &src);

		void		addGrade(int grade);
		std::string	getName() const;
		int			getGrade() const;
		void		increment();
		void		decrement();
		void		signForm(Form &form);
		void		executeForm(Form const &form);
};

std::ostream	&operator<<(std::ostream &ori, Bureaucrat const &src);

#endif
