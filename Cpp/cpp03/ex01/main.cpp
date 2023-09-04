#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	Anakin("Anakin");
	ClapTrap	Dark_Vador("Dark Vador");
	ScavTrap	R2("R2-D2");
	std::cout << std::endl;

	Anakin.stats();
	Dark_Vador.stats();
	R2.stats();
	std::cout << std::endl;

	Anakin.fight(Dark_Vador);
	Dark_Vador.fight(R2);
	Anakin.stats();
	Dark_Vador.stats();
	R2.stats();
	std::cout << std::endl;

	Dark_Vador.fight(Anakin);
	Anakin.stats();
	Dark_Vador.stats();
	Anakin.beRepaired(6);
	Anakin.stats();
	std::cout << std::endl;

	R2.fight(Dark_Vador);
	R2.guardGate();
	Anakin.stats();
	Dark_Vador.stats();
	R2.stats();
	Dark_Vador.beRepaired(5);
	std::cout << std::endl;
}
