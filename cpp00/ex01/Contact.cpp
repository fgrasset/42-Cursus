#include "contactClass.hpp"

Contact::Contact()
	{

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

void	Contact::addPhone(std::string nb)
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
	else if (index == PHONE)
		return (_phone);
	return (NULL);
}

void	Contact::addContact(void)
{
	std::string	phone;
	std::string	fName;
	std::string	lName;
	std::string	nName;
	std::string	secret;

	std::cin.clear();
	do{
		std::cout << "Enter the first name of the contact : ";
		std::getline(std::cin, fName);
	} while (fName.empty());
	do{
		std::cout << "Enter the last name of the contact : ";
		std::getline(std::cin, lName);
	} while (lName.empty());
	do{
		std::cout << "Enter the nickname of the contact : ";
		std::getline(std::cin, nName);
	} while (nName.empty());
	do{
		std::cout << "Enter the darkest secret of the contact : ";
		std::getline(std::cin, secret);
	} while (secret.empty());
	do{
		std::cout << "Enter the phone number of the contact : ";
		std::getline(std::cin, phone);
	} while (phone.empty());
	addFirst(fName);
	addLast(lName);
	addNick(nName);
	addPhone(phone);
	addSecret(secret);
}
