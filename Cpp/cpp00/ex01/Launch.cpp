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
		std::getline(std::cin, cmd);
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
	std::string	index;
	int			nb_i = 0;

	book->printContacts();
	do{
		std::cout << "Select the index of a contact to see their information: ";
		std::getline(std::cin, index);

		if (std::cin.eof() || index.empty())
			return;
		bool validInput = true;
		for (std::size_t i = 0; i < index.length(); ++i) {
			if (!std::isdigit(index[i])) {
				validInput = false;
				continue;
			}
		}
		if (!validInput) {
			continue;
		}
		nb_i = std::stoi(index);
	} while (nb_i < 1 || nb_i > book->size());
	book->selectContact(nb_i);
}

/* EXIT command */
void	exit(int *run)
{
	*run = 0;
}
