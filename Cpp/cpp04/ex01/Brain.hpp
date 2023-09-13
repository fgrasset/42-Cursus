#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	std::string _ideas[100];
	public:
		Brain();
		Brain(const Brain &src);
		~Brain();
		Brain &operator=(const Brain &src);

		std::string	getIdea(int i) const;
		void		setIdea(int i, std::string const &str);
};

#endif
