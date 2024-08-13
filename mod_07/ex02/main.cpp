#include <iostream>
#include <ctime>
#include <Array.hpp>
#include <iomanip>

#define MAX_VAL 10

int test_subject() {
	std::cout << BG_BRIGHT_BLACK"--=== Tests from the subject ===--"RESET << std::endl;

	Array<int> numbers(MAX_VAL);

	int* mirror = new int[MAX_VAL];

	srand(time(NULL));

// Fill out the arrays 'numbers' and 'mirror'
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

// Printing the values
	std::cout << GREEN" NUMBERS "RESET << "       "  <<  CYAN" MIRROR "RESET << std::endl;
	for (size_t i = 0; i < MAX_VAL; ++i) {
		if (i + 1 != MAX_VAL)
		{
			std::cout << GREEN << numbers[i] << RESET << "     ";
			std::cout << CYAN << mirror[i] << RESET;
			std::cout << std::endl;
			continue ;
		}
		std::cout << std::endl;
	}

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (i + 1 != MAX_VAL)
		{
			if (mirror[i] != numbers[i]) {
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
			else
			{
				std::cout << "Ok. ";
			}
			continue ;
		}
		std::cout << std::endl;
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	return (0);
}

void test_str() {
	std::cout << "\n" << BG_BRIGHT_BLACK"--=== More string type test ===--"RESET << std::endl;
	Array<std::string> words(5);
	words[0] = "Hello, ";
	words[1] = "world!\n";
	words[3] = "Don't ";
	words[4] = "panic!";

	for (size_t i = 0; i < words.size(); ++i) {
		std::cout << words[i];
	}
	std::cout << std::endl;
}


int main(int, char**)
{

	/* Tests from the subject */
	test_subject();

	/* My string test */
	test_str();

	return 0;
}