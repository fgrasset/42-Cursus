#pragma once

#include "ATarget.hpp"
#include <map>
#include <iostream>

class TargetGenerator
{
	std::map<std::string, ATarget *>	arr_target;
	TargetGenerator(const TargetGenerator &src);
	TargetGenerator	&operator=(const TargetGenerator &src);

	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget *targetPtr);
		void	forgetTargetType(std::string const &target_ref);
		ATarget*	createTarget(std::string const &target_ref);
};
