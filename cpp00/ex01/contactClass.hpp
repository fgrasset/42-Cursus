#ifndef CONTACTCLASS_HPP
# define CONTACTCLASS_HPP

#include <string>
#include <iostream>
#include <cctype>

#define FNAME	0
#define LNAME	1
#define NNAME	2
#define SECRET	3
#define PHONE	4

class Contact
{
	std::string	_phone;
	std::string	_fName;
	std::string	_lName;
	std::string	_nName;
	std::string	_secret;

	public:
		Contact();
		~Contact();

		void			addFirst(std::string str);
		void			addLast(std::string str);
		void			addNick(std::string str);
		void			addSecret(std::string str);
		void			addPhone(std::string nb);
		std::string		get(int index);
		void			addContact(void);

};

bool	isWord(std::string str);


#endif
