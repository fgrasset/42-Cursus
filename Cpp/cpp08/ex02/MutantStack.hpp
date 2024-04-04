#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &src);
		~MutantStack();

		MutantStack	&operator=(const MutantStack &src);

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin();
		iterator	end();
};

template<typename T>
MutantStack<T>::MutantStack()
{

}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
	*this = src;
}

template<typename T>
MutantStack<T>::~MutantStack()
{

}

template<typename T>
MutantStack<T>		&MutantStack<T>::operator=(const MutantStack &src)
{
	(void) src;
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

#endif
