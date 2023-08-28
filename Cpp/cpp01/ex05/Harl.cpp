#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::_debug(void)
{
	std::cout << "Wow there is a bug issue there !" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "For information you did this and that." << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "Be careful there ! What you are doing is wrong." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "There it is... Error 404 brain not found !" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functionPtr[]) (void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (size_t i = 0; i < levels->size(); i++)
	{
		if (level == levels[i])
		{
			(this->*functionPtr[i])();
			break ;
		}
		if (i == 4)
			std::cout << "Wrong level, this one is not found !" << std::endl;
	}
}
