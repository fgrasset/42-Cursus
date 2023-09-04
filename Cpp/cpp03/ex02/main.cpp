#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ClapTrap	Anakin("Anakin");
	ClapTrap	Dark_Vador("Dark Vador");
	ScavTrap	R2("R2-D2");
	FragTrap	Chewbie("Chewbacca");
	std::cout << std::endl;

	Anakin.stats();
	Dark_Vador.stats();
	R2.stats();
	Chewbie.stats();
	std::cout << std::endl;

	Anakin.fight(Dark_Vador);
	Dark_Vador.fight(R2);
	R2.fight(Chewbie);
	Anakin.stats();
	Dark_Vador.stats();
	R2.stats();
	Chewbie.stats();
	std::cout << std::endl;

	Dark_Vador.fight(Anakin);
	Chewbie.fight(R2);
	Anakin.stats();
	Dark_Vador.stats();
	R2.stats();
	Chewbie.stats();
	Anakin.beRepaired(6);
	Anakin.stats();
	std::cout << std::endl;

	R2.fight(Dark_Vador);
	R2.guardGate();
	Chewbie.highFivesGuys();
	Anakin.stats();
	Dark_Vador.stats();
	R2.stats();
	Chewbie.stats();
	Dark_Vador.beRepaired(5);
	std::cout << std::endl;
}
