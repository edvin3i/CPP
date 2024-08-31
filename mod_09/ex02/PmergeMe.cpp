#include "includes/PmergeMe.hpp"

std::vector<int>::iterator
PmergeMe::getIsertPosition(std::vector<int> &vec, int value) {
	int low = 0;
	int high = vec.size();

	while (low < high) {
		int mid = (low + high) / 2;

		if (vec[mid] < value) {
			 low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return (vec.begin() + low);
}

bool PmergeMe::pushValToContainers(const char *argv, std::vector<int> &vec,
								   std::list<int> *lst) {

	char *end;
	long value = std::strtol(argv, &end, 10);

	if (end != 0 || end == argv) {
		std::cout << BRIGHT_RED "Error: Wrong number in argument!" RESET << std::endl;
		return (false);
	}
	if (value < INT_MIN || value > INT_MAX) {
		std::cout << BRIGHT_RED "Error: Number " << argv << " out of range!" RESET << std::endl;
		return (false);
	}

	int intValue = static_cast<int>(value);
	vec.push_back(intValue);
	lst->push_back(intValue);

	return (true);
}

