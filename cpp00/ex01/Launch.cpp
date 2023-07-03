#include "phonebookClass.hpp"

void	execute(std::string cmd, PhoneBook book, int *run);
void	selectContact(PhoneBook book, int index);
void	search(PhoneBook book);
void	printContacts(PhoneBook book);
void	addContact(PhoneBook book);
void	exit(int *run);


int	main(void)
{
	int			run = 1;
	std::string	cmd;
	PhoneBook	book;

	while (run)
	{
		std::cout << "Enter your input : ";
		std::cin >> cmd;
		execute(cmd, book, &run);
	}
}

void	execute(std::string cmd, PhoneBook book, int *run)
{
	if (cmd == "ADD")
		addContact(book);
	else if (cmd == "SEARCH")
		search(book);
	else if (cmd == "EXIT")
		exit(run);
}

/* prints the list of contact and wait for the user to select an index to show */
void	search(PhoneBook book)
{
	int	index = 0;

	printContacts(book);
	std::cout << "select the index of a contact to see his informations : ";
	std::cin >> index;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cout << "The index is incorrect, please enter it again : ";
		std::cin >> index;
	}
	selectContact(book, index);
}

/* priints the infos of the contact linked to the index */
void	selectContact(PhoneBook book, int index)
{
	index --;
	std::cout << "First name : " << book._book[index].get(FNAME) << std::endl;
	std::cout << "Last name : " << book._book[index].get(LNAME) << std::endl;
	std::cout << "Nickname : " << book._book[index].get(NNAME) << std::endl;
	std::cout << "Phone number : " << book._book[index].getPhone() << std::endl;
	std::cout << "Darkest secret : " << book._book[index].get(SECRET) << std::endl;
}

/* prints the list of all the contacts */
void	printContacts(PhoneBook book)
{
	int			index = -1;

	while (++index < 8)
	{
		std::cout << "    " << index + 1 << "     ";
		std::cout << " | ";
		std::cout << book._book[index].get(FNAME).substr(0, 10);		//might be the issue where the data is not taken in
		std::cout << " | ";
		std::cout << book._book[index].get(LNAME).substr(0, 10);
		std::cout << " | ";
		std::cout << book._book[index].get(NNAME).substr(0, 10);
		std::cout << std::endl;
	}
}

/* adds a new contact the phonebook */
void	addContact(PhoneBook book)
{
	static int	pos;

	book._book[pos].addContact();
	if (++pos == 9)
		pos = 0;
}

/* EXIT command */
void	exit(int *run)
{
	*run = 0;
}
