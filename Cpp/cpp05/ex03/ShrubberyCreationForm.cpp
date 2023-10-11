#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", false, 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form(src.getName(), src.getState(), src.getGradeSigned(), src.getGradeExecute()), _target(this->getTarget())
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	Form::operator=(*this);
	this->_target = src._target;
	return *this;
}

std::string				ShrubberyCreationForm::getTarget()
{
	return this->_target;
}

void					ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->allowed(executor.getGrade()))
		throw(GradeTooLowException());
	ShrubberyCreationForm copy = *this;
	std::ofstream outfile(copy.getTarget()+"_shrubbery");
	outfile << "      (__)" << std::endl;
	outfile << "       (oo)" << std::endl;
	outfile << "   /------\\/" << std::endl;
	outfile << "  * / |    ||" << std::endl;
	outfile << "   ~~   ~~" << std::endl;
	outfile << std::endl;
	outfile << "      /\\\n";
	outfile << "     /  \\\n";
	outfile << "    /    \\\n";
	outfile << "   /      \\\n";
	outfile << "  /        \\\n";
	outfile << " /          \\\n";
	outfile << "/            \\\n";
	outfile << "|    /\\      |\n";
	outfile << "|   /  \\     |\n";
	outfile << "|  /    \\    |\n";
	outfile << "| /      \\   |\n";
	outfile << "|/________\\  |\n";
	outfile << "  \\        /\n";
	outfile << "   \\      /\n";
	outfile << "    \\    /\n";
	outfile << "     \\  /\n";
	outfile << "      \\/\n";

	outfile.close();
}
