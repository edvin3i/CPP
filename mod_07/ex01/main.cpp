#include "iter.hpp"

void	print_color(std::string c)
{
	std::cout << BRIGHT_GREEN << c << RESET << std::endl;
}

int main() {

	std::string arr[4] = {"Hello", "World", "Don't", "panic"};
	iter(arr, 4, print_color);

	return (0);
}