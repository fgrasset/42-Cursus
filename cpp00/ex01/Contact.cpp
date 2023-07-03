#include "contactClass.hpp"

Contact::Contact()
	{
		_phone = 0;
	}

Contact::~Contact()
	{
		// std::cout<< "Destructor called" << std::endl;
	}

void	Contact::addFirst(std::string str)
{
	_fName = str;
}

void	Contact::addLast(std::string str)
{
	_lName = str;
}

void	Contact::addNick(std::string str)
{
	_nName = str;
}

void	Contact::addSecret(std::string str)
{
	_secret = str;
}

void	Contact::addPhone(int nb)
{
	_phone = nb;
}

/* returns the value needed based on the index */
std::string	Contact::get(int index)
{
	if (index == FNAME)
		return (_fName);
	else if (index == LNAME)
		return (_lName);
	else if (index == NNAME)
		return (_nName);
	else if (index == SECRET)
		return (_secret);
	return (NULL);
}

/* returns the phone number */
int	Contact::getPhone(void)
{
	return (_phone);
}

void	Contact::addContact(void)
{
	int			phone;
	std::string	fName;
	std::string	lName;
	std::string	nName;
	std::string	secret;

	std::cout << "Enter the first name of the contact : ";
	std::cin >> fName;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "The first name must be a string, please enter it again : ";
		std::cin >>fName;
	}
	std::cout << "Enter the last name of the contact : ";
	std::cin >> lName;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "The last name must be a string, please enter it again : ";
		std::cin >>lName;
	}
	std::cout << "Enter the nickname of the contact : ";
	std::cin >> nName;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "The nickname must be a string, please enter it again : ";
		std::cin >>nName;
	}
	std::cout << "Enter the darkest secret of the contact : ";
	std::cin >> secret;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "The secret must be a string, please enter it again : ";
		std::cin >> secret;
	}
	std::cout << "Enter the phone number of the contact : ";
	std::cin >> phone;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "The phone number must only contain numbers, please enter it again : ";
		std::cin >>phone;
	}
	addFirst(fName);
	addLast(lName);
	addNick(nName);
	addPhone(phone);
	addSecret(secret);
}
