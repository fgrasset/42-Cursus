#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Anakin("Anakin");
	ClapTrap Dark_Vador("Dark Vador");
	std::cout << std::endl;

	Anakin.stats();
	Dark_Vador.stats();
	std::cout << std::endl;

	Anakin.fight(Dark_Vador);
	Anakin.stats();
	Dark_Vador.stats();
	std::cout << std::endl;

	Dark_Vador.fight(Anakin);
	Anakin.stats();
	Dark_Vador.stats();
	Anakin.beRepaired(6);
	Anakin.stats();
	std::cout << std::endl;

	Anakin.fight(Dark_Vador);
	Anakin.stats();
	Dark_Vador.stats();
	Dark_Vador.beRepaired(5);
	std::cout << std::endl;
}
