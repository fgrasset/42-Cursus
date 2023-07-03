#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

#include "contactClass.hpp"

class PhoneBook
{
	int		_pos;

	public:
		Contact	_book[8];
		PhoneBook();
		~PhoneBook();

		void	addContact(void);
		void	search(int contact);
};

#endif
