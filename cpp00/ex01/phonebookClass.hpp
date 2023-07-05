#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

#include "contactClass.hpp"
#include <iomanip>

class PhoneBook
{
	int		_pos;
	int		_number;

	int		_size(void);
	public:
		Contact	_book[8];
		PhoneBook();
		~PhoneBook();

		void	addContact(void);
		void	printContacts(void);
		void	selectContact(int index);
};

#endif
