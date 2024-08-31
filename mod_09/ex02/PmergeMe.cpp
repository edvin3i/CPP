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
