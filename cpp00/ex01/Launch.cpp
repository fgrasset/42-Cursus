#include "phonebookClass.hpp"

void	execute(std::string cmd, PhoneBook *book, int *run);
void	search(PhoneBook *book);
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
		execute(cmd, &book, &run);
	}
}

void	execute(std::string cmd, PhoneBook *book, int *run)
{
	if (cmd == "ADD")
		book->addContact();
	else if (cmd == "SEARCH")
		search(book);
	else if (cmd == "EXIT")
		exit(run);
}

/* prints the list of contact and wait for the user to select an index to show */
void	search(PhoneBook *book)
{
	int	index = 0;

	book->printContacts();
	do{
		std::cout << "select the index of a contact to see his informations : ";
		std::cin >> index;
	} while (index > 8 || index < 1);
	book->selectContact(index);
}

/* EXIT command */
void	exit(int *run)
{
	*run = 0;
}
