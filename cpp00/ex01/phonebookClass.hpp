#ifndef PHONEBOOKCLASS_HPP
# define PHONEBOOKCLASS_HPP

#include "contactClass.hpp"
#include <iomanip>

class PhoneBook
{
	int		_pos;
	int		_number;
	Contact	_book[8];

	public:
		PhoneBook();
		~PhoneBook();

		int		size(void);
		void	addContact(void);
		void	printContacts(void);
		void	selectContact(int index);
};

#endif
