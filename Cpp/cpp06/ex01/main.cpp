#include "Serializer.hpp"
#include <iostream>

void	initValue(Data *car)
{
	car->km = 34670;
	car->model = "Mercedes";
	car->color = "Blue";
}

void	showCar(Data *car)
{
	std::cout << "Km: " << car->km << std::endl;
	std::cout << "Model: " << car->model << std::endl;
	std::cout << "Color: " << car->color << std::endl;
}

int	main()
{
	Data	car;

	initValue(&car);

	std::cout << "----- Base values -----" << std::endl;
	showCar(&car);

	std::cout << std::endl << "----- Serializing the values -----" << std::endl;
	uintptr_t	serialized = Serializer::serialize(&car);
	std::cout << "Car value serialized: " << serialized << std::endl;
	Data	*newCar = Serializer::deserialize(serialized);

	std::cout << std::endl << "----- Deserialized values on a new car -----" << std::endl;
	showCar(newCar);

	return 0;
}
