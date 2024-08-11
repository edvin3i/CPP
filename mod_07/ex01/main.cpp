#include "iter.hpp"

void	print_colored_label(std::string c)
{
	std::cout << BG_BLUE << BRIGHT_GREEN"--=== "BRIGHT_CYAN << c << BRIGHT_GREEN" ===--" RESET << std::endl;
}

void	str_pow_two(std::string num) {
	char *end;

	long long_num = std::strtol(num.c_str(), &end, 10);
	std::cout << long_num << "^2 = " << long_num * long_num << std::endl;
}

void	int_pow_two(int num) {

	std::cout << num << "^2 = " << num * num << std::endl;
}

int main() {
	std::cout << BG_BRIGHT_BLACK"1. Test withs strings array:"RESET << "\n" << std::endl;
	std::string arr[4] = {"Hello", "World", "Don't", "panic"};
	iter(arr, 4, print_colored_label);
	std::cout << "\n" << std::endl;

	std::cout << BG_BRIGHT_BLACK"2. Test withs ints array:"RESET << "\n" << std::endl;
	int int_nums[3] = {13, 42, 6};
	iter(int_nums, 3, int_pow_two);
	std::cout << "\n" << std::endl;

	std::cout << BG_BRIGHT_BLACK"3. Test withs array of stringed int nums:"RESET << "\n" << std::endl;
	std::string str_nums[4] = {"5", "12", "32", "7"};
	iter(str_nums, 4, str_pow_two);
	std::cout << "\n" << std::endl;


	return (0);
}