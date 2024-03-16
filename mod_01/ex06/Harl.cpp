#include "includes/Harl.hpp"
#include <iomanip>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::complain(std::string level) {

	std::string complain_types[4] =
			{"DEBUG",
			 "INFO",
			 "WARNING",
			 "ERROR"
			};
	void (Harl::*complain_funcs[4]) (void) =
			{
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
			};

	int level_index = 4;
	for (int i = 0; i < 4; ++i)
	{
		if (complain_types[i] == level) {
			level_index = i;
			std::cout << "[ " << level << " ]" << std::endl;
			break ;
		}
	}

	switch (level_index)
	{
		case 0:
			(this->*complain_funcs[0])();
		case 1:
			(this->*complain_funcs[1])();
		case 2:
			(this->*complain_funcs[2])();
		case 3:
			(this->*complain_funcs[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

	}
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
