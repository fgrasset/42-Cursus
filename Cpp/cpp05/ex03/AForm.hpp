#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <fstream>

class Bureaucrat;

class Form
{
	const std::string	_name;
	bool				_sign;
	const int			_gradeSigned;
	const int			_gradeExecute;

	public:
		Form();
		Form(const std::string name);
		Form(const std::string name, bool sign, const int gradeSigned, const int gradeExecute);
		Form(const Form &src);
		virtual ~Form();

		Form			&operator=(const Form &src);
		std::string		getName() const;
		bool			getState() const;
		int				getGradeSigned() const;
		int				getGradeExecute() const;
		void			checkGrade();
		void			beSigned(Bureaucrat &pers);
		bool			allowed(const int grade) const;
		virtual void	execute(Bureaucrat const &executor) const = 0;

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
};

std::ostream	&operator<<(std::ostream &ori, Form &src);

#endif
