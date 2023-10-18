#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data data(10, 20, 30);

	std::cout << "data->x = " << data.getX() << std::endl;
	std::cout << "data->y = " << data.getY() << std::endl;
	std::cout << "data->z = " << data.getZ() << std::endl;

	uintptr_t serialized_data = Serializer::serialize(&data);

	Data* deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << "serialized_data = " << serialized_data << std::endl;
	std::cout << "deserialized_data->x = " << deserialized_data->getX() << std::endl;
	std::cout << "deserialized_data->y = " << deserialized_data->getY() << std::endl;
	std::cout << "deserialized_data->z = " << deserialized_data->getZ() << std::endl;

	return 0;
}
