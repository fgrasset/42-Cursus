#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	std::string		_Name;
	unsigned int	_Hit;
	unsigned int	_Energy;
	unsigned int	_AD;

	public:
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		std::string	getName(void);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		stats(void);
		void		fight(ClapTrap &enemy);
};

#endif
