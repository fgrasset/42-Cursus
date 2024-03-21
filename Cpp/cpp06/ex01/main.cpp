#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data data1;
	std::cout << "Test 1: Default Constructor - Expected: 0 0 0, Actual: "
				<< data1.getX() << " " << data1.getY() << " " << data1.getZ() << std::endl;

	// Test 2: Parameterized Constructor
	Data data2(10, 20, 30);
	std::cout << "Test 2: Parameterized Constructor - Expected: 10 20 30, Actual: "
				<< data2.getX() << " " << data2.getY() << " " << data2.getZ() << std::endl;

	// Test 3: Copy Constructor
	Data data3(data2);
	std::cout << "Test 3: Copy Constructor - Expected: 10 20 30, Actual: "
				<< data3.getX() << " " << data3.getY() << " " << data3.getZ() << std::endl;

	// Test 4: Serialization and Deserialization
	uintptr_t serialized_data = Serializer::serialize(&data3);
	std::cout << "Test 4: Serialized data: " << serialized_data << std::endl;

	Data* deserialized_data = Serializer::deserialize(serialized_data);
	if (deserialized_data == nullptr) {
		std::cout << "Test 4: Deserialization failed!\n";
	} else {
		std::cout << "Test 4: Deserialized data - Expected: 10 20 30, Actual: "
					<< deserialized_data->getX() << " " << deserialized_data->getY() << " " << deserialized_data->getZ() << std::endl;
	}

	Data data(10, 20, 30);

	std::cout << "data->x = " << data.getX() << std::endl;
	std::cout << "data->y = " << data.getY() << std::endl;
	std::cout << "data->z = " << data.getZ() << std::endl;

	serialized_data = Serializer::serialize(&data);

	deserialized_data = Serializer::deserialize(serialized_data);

	std::cout << "serialized_data = " << serialized_data << std::endl;
	std::cout << "deserialized_data->x = " << deserialized_data->getX() << std::endl;
	std::cout << "deserialized_data->y = " << deserialized_data->getY() << std::endl;
	std::cout << "deserialized_data->z = " << deserialized_data->getZ() << std::endl;

	return 0;
}
