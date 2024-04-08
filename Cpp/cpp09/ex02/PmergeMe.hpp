#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

class PmergeMe
{
	std::list<int>	_list;
	std::deque<int>	_deque;
	double			_timeList;
	double			_timeDeque;

	public:
		PmergeMe(std::list<int> unsortedList, std::deque<int> unsortedDeque);
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &src);
		void		sortDescending(std::list<int> &inputList, std::list<int> &sortedSubList);
		void		sortDescending(std::deque<int> &inputDeque, std::deque<int> &sortedSubDeque);
		void		insertElement(std::list<int> &soretedSubList, int elment);
		void		insertElement(std::deque<int> &sortedSubDeque, int element);
		void		fordJohnsonSort(std::list<int> &inputList);
		void		fordJohnsonSort(std::deque<int> &inputDeque);
		void		display();
};

#endif
