#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <istream>

class Zombie
{
	std::string	_name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	void	addName(std::string name);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
