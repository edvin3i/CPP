#include "MutantStack.hpp"


void test_fw() {
	std::cout << "\n" << BG_BRIGHT_BLACK"1. My forward test:"RESET << std::endl;
	MutantStack<int> mstack;


	int arr[5] = {21, 4, 1, 7,42};
	mstack.addNumbers(arr, 5);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << GREEN"Print stack using forward iterator: "RESET << std::endl;
	while(it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

void test_rev() {
	std::cout << "\n" << BG_BRIGHT_BLACK"2. My reverse test:"RESET << std::endl;
	MutantStack<int> mstack;


	int arr[5] = {21, 4, 1, 7,42};
	mstack.addNumbers(arr, 5);

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << CYAN"Print stack using reverse iterator: "RESET << std::endl;
	while(rit != rite) {
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;
}


void test_subject() {
	std::cout << "\n" << BG_BRIGHT_BLACK"3. Standard test from the subject:"RESET << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

}

int main() {

	test_fw();

	test_rev();

	test_subject();

	return (0);
}