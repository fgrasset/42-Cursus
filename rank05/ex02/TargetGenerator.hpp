#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	std::map<std::string, ATarget *> arr_target;

	TargetGenerator(const TargetGenerator &src);
	TargetGenerator	operator=(const TargetGenerator &src);
	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget *target);
		void	forgetTargetType(std::string const &target);
		ATarget	*createTarget(std::string const &target);
};
