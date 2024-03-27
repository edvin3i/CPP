#include "includes/Harl.hpp"


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

	for (int i = 0; i < 4; ++i)
	{
		if (complain_types[i] == level) {
			(this->*complain_funcs[i])();
			return ;
		}
	}
	std::cout << "The level of complaint is not recognised." << std::endl;

}

void Harl::debug() {
	std::cout << std::setw(10) << "DEBUG: ";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
	std::cout << std::setw(10) << "INFO: ";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
	std::cout << std::setw(10) << "WARNING: ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
	std::cout << std::setw(10) << "ERROR: ";
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
