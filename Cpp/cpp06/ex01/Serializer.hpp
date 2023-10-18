#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer
{
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &src);
};

#endif
