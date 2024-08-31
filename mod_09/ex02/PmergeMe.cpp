#include "includes/PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		if (!pushValToContainers(argv[i])){
			throw std::invalid_argument("Exit.");
		}
	}
}

PmergeMe::~PmergeMe() {

}

std::vector<int>::iterator
PmergeMe::getVecInsertPosition(std::vector<int> &vec, int value) {
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

std::deque<int>::iterator
PmergeMe::getDeqInsertPosition(std::deque<int> &deq, int value) {
	int low = 0;
	int high = deq.size();

	while (low < high) {
		int mid = (low + high) / 2;

		if (deq[mid] < value) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return (deq.begin() + low);
}


std::list<int>::iterator
PmergeMe::getLstInsertPosition(std::list<int> &lst, int value) {
	int low = 0;
	int high = lst.size();

	while (low < high) {
		int mid = (low + high) / 2;

		if (std::lower_bound(lst.begin(), lst.end(), mid) < value) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}

	return (lst.begin() + low);
}



bool PmergeMe::pushValToContainers(const char *argv) {

	char *end;
	long value = std::strtol(argv, &end, 10);

	if (*end != '\0' || end == argv) {
		std::cerr << BRIGHT_RED "Error: Wrong number: " << argv << "!" RESET << std::endl;
		return (false);
	}
	if (value < 0 || value > INT_MAX) {
		std::cerr << BRIGHT_RED "Error: Number " << argv << " out of range!" RESET << std::endl;
		return (false);
	}

	int intValue = static_cast<int>(value);
	_vec.push_back(intValue);
	_deq.push_back(intValue);
	_lst.push_back(intValue);

	return (true);
}

void PmergeMe::printVector() {

	std::cout << "Vector: ";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque() {

	std::cout << "Deque: ";
	for (size_t i = 0; i < _deq.size(); ++i) {
		std::cout << _deq[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList() {
	std::cout << "List: ";
	for (size_t i = 0; i < _vec.size(); ++i) {
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}


