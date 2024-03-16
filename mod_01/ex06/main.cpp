#include "includes/Harl.hpp"

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Wrong number of args\n";
		std::cerr << "Usage: " << argv[0] << " <LEVEL>" << std::endl;
		return 1;
	}

	std::string input = argv[1];

	Harl harl;
	harl.complain(input);

	return 0;
}
