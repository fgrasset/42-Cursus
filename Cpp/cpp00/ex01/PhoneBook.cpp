#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_pos = 0;
	_number = 0;
}

PhoneBook::~PhoneBook()
{
	// std::cout << "Destructor called" << std::endl;
}

/* prints the list of all the contacts */
void	PhoneBook::printContacts(void)
{
	int			index = -1;

	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;

	while (++index < size())
	{
		std::cout << std::setw(10) << index + 1 << "|";
		if (_book[index].get(FNAME).length() > 9)
			std::cout << _book[index].get(FNAME).substr(0, 9) << "." << "|";
		else if (_book[index].get(FNAME).length() < 10)
			std::cout << std::setw(10) << _book[index].get(FNAME) << "|";
		if (_book[index].get(LNAME).length() > 9)
			std::cout << _book[index].get(LNAME).substr(0, 9) << "." << "|";
		else if (_book[index].get(LNAME).length() < 10)
			std::cout << std::setw(10) << _book[index].get(LNAME) << "|";
		if (_book[index].get(NNAME).length() > 9)
			std::cout << _book[index].get(NNAME).substr(0, 9) << "." << std::endl;
		else if (_book[index].get(NNAME).length() < 10)
			std::cout << std::setw(10) << _book[index].get(NNAME) << std::endl;
	}
}

/* adds a new contact the phonebook */
void	PhoneBook::addContact(void)
{
	static int	pos;

	if (_number < 8)
		_number++;
	_book[pos].addContact();
	if (++pos == 8)
		pos = 0;
}

/* priints the infos of the contact linked to the index */
void	PhoneBook::selectContact(int index)
{
	index --;
	std::cout << "First name : " << _book[index].get(FNAME) << std::endl;
	std::cout << "Last name : " << _book[index].get(LNAME) << std::endl;
	std::cout << "Nickname : " << _book[index].get(NNAME) << std::endl;
	std::cout << "Phone number : " << _book[index].get(PHONE) << std::endl;
	std::cout << "Darkest secret : " << _book[index].get(SECRET) << std::endl;
}

/* returns the number of contacts there is */
int		PhoneBook::size(void)
{
	return (_number);
}

