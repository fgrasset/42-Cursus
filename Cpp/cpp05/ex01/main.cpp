#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "Test with grade 2 and needed grade to sign 30" << std::endl;
	try
	{
		Bureaucrat	prs1 = Bureaucrat("John", 2);
		Form		form1 = Form("request");
		prs1.signForm(form1);
		std::cout << prs1 << std::endl;
		std::cout << form1 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's try a grade of 30 and 30 to sign" << std::endl;
	try
	{
		Bureaucrat	prs2 = Bureaucrat("Paul", 30);
		Form		form2 = Form("RH");
		std::cout << form2 << std::endl;
		prs2.signForm(form2);
		std::cout << prs2 << std::endl;
		std::cout << form2 << std::endl;

	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "Let's play with the decrementation and put the grade too low" << std::endl;
	try
	{
		Bureaucrat	prs3 = Bureaucrat("Paul", 30);
		Form		form3 = Form("Request");
		std::cout << prs3 << std::endl;
		prs3.decrement();
		prs3.signForm(form3);
		std::cout << form3 << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
