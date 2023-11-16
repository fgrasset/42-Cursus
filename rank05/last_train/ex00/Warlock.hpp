#pragma once

#include <iostream>

class Warlock
{
	std::string name;
	std::string title;
	Warlock();
	Warlock(const Warlock &src);
	Warlock	&operator=(const Warlock &src);

	public:
		Warlock(std::string const &name, std::string const &title);
		~Warlock();

		std::string const	&getName() const;
		std::string const	&getTitle() const;
		void	setTitle(std::string const &newtitle);
		void	introduce() const;
};
