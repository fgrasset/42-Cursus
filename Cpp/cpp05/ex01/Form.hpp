#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
	const std::string	_name;
	bool				_sign;
	const int			_gradeSigned;
	const int			_gradeExecute;

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Grade is too low to sign");
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
		Form();
		Form(const std::string name);
		Form(const std::string name, bool sign, const int gradeSigned, const int gradeExecute);
		Form(const Form &src);
		~Form();

		Form	&operator=(const Form &src);
		std::string	getName() const;
		bool		getSign();
		int			getGradeSigned() const;
		int			getGradeExecute() const;
		void		checkGrade();
		void		beSigned(Bureaucrat &pers);
};

std::ostream	&operator<<(std::ostream &ori, const Form &src);

#endif
