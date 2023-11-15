#pragma once

#include <iostream>

class Warlock
{
	std::string _name;
	std::string _title;
	Warlock();
	Warlock(const Warlock &src);
	Warlock	&operator=(const Warlock &src);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const	&getName() const;
		std::string const	&getTitle() const;
		void				setTitle(std::string const &title);
		void				introduce() const;
};
