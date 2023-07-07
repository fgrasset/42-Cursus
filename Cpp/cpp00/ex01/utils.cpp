#include "phonebookClass.hpp"

/* returns true if the given str is a word */
bool	isWord(std::string str)
{
	if (str.empty()) {
		return false;
	}

	for (char c : str) {
		if (!std::isalpha(c)) {
			return false;
		}
	}
	return true;
}
