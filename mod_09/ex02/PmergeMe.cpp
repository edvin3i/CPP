#include "includes/PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv): _odd_member(-1) {
		int last = argc - 1;

		std::cout << "Before: ";

		if ((argc - 1) % 2 != 0){
			if (!pushValToContainers(argv[last])) {
				throw std::invalid_argument("Exit.");
			}
			_odd_member = _vec.back();
			_vec.pop_back();
			_deq.pop_back();
			last--;
		}



		for (int i = 1; i <= last; ++i) {
			if (!pushValToContainers(argv[i]))	{
				throw std::invalid_argument("Exit.");
			}
			std::cout << _vec.back() << std::endl;
		}
		if (_odd_member != -1) {
			std::cout << _odd_member << std::endl;
		}
		else {
			std::cout << std::endl;
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

	if (_odd_member != intValue && _odd_member != -1) {
		std::cout << intValue << " ";
	}
	else if (_odd_member == intValue && _vec.size() > 0) {
		std::cout << intValue << " ";
	}

	return (true);
}

void PmergeMe::printVector(const std::vector<int> &vec) {

	std::cout << "Vector: ";
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}


void PmergeMe::printDeque(const std::deque<int> &deq) {

	std::cout << "Deque: ";
	for (size_t i = 0; i < deq.size(); ++i) {
		std::cout << deq[i] << " ";
	}
	std::cout << std::endl;
}


std::vector<std::pair<int, int> >
	PmergeMe::createVecPairs(std::vector<int> &vec) {
	std::vector<std::pair<int, int> > vec_pairs;

	for(size_t i = 0; i < vec.size(); i += 2) {
		if (vec[i + 1] < vec[i]) {
			vec_pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		}
		else {
			vec_pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}
	}

	return (vec_pairs);
}


std::deque<std::pair<int, int> > PmergeMe::createDeqPairs(std::deque<int> &deq) {
	std::deque<std::pair<int, int> > deq_pairs;

	for(size_t i = 0; i < deq.size(); i += 2) {
		if (deq[i + 1] < deq[i]) {
			deq_pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
		}
		else {
			deq_pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		}
	}

	return (deq_pairs);
}


std::vector<int>
PmergeMe::mergeToVector(std::vector<std::pair<int, int> > &pairs) {
	std::vector<int> small_nums;
	std::vector<int> big_nums;

	for (size_t i = 0; i < pairs.size(); ++i) {
		small_nums.push_back(pairs[i].first);
		big_nums.push_back(pairs[i].second);
	}

	std::sort(small_nums.begin(), small_nums.end());

	for (size_t i = 0; i < big_nums.size(); ++i) {
		std::vector<int>::iterator pos = getVecInsertPosition(small_nums, big_nums[i]);
		small_nums.insert(pos, big_nums[i]);
	}

	if (_odd_member != -1) {
		std::vector<int>::iterator pos = getVecInsertPosition(small_nums, _odd_member);
		small_nums.insert(pos, _odd_member);
	}

	return (small_nums);
}

std::deque<int> PmergeMe::mergeToDeque(std::deque<std::pair<int, int> > &pairs) {
	std::deque<int> small_nums;
	std::deque<int> big_nums;

	for (size_t i = 0; i < pairs.size(); ++i) {
		small_nums.push_back(pairs[i].first);
		big_nums.push_back(pairs[i].second);
	}

	std::sort(small_nums.begin(), small_nums.end());

	for (size_t i = 0; i < big_nums.size(); ++i) {
		std::deque<int>::iterator pos = getDeqInsertPosition(small_nums, big_nums[i]);
		small_nums.insert(pos, big_nums[i]);
	}

	if (_odd_member != -1) {
		std::deque<int>::iterator pos = getDeqInsertPosition(small_nums, _odd_member);
		small_nums.insert(pos, _odd_member);
	}

	return (small_nums);
}

const std::vector<int> PmergeMe::sortVector() {
	std::vector<int> vec;
	std::vector<std::pair<int, int> > pairs;

	struct timeval start, stop;
	gettimeofday(&start, NULL);

	pairs = createVecPairs(_vec);
	vec = mergeToVector(pairs);

	gettimeofday(&stop, NULL);

	double elapsed_time = (stop.tv_sec - stop.tv_sec) * 1000000.0 + (stop.tv_usec - start.tv_usec);
	elapsed_time = elapsed_time / 1000.0;

	std::cout << "Time to process a range of " << vec.size() << \
					" elements with std::vector: " << \
					std::fixed << std::setprecision(6) << \
					elapsed_time << " ms" << std::endl;
	return (vec);
}

const std::deque<int> PmergeMe::sortDeque() {
	std::deque<int> deq;
	std::deque<std::pair<int, int> > pairs;

	struct timeval start, stop;
	gettimeofday(&start, NULL);

	pairs = createDeqPairs(_deq);
	deq = mergeToDeque(pairs);

	gettimeofday(&stop, NULL);

	double elapsed_time = (stop.tv_sec - stop.tv_sec) * 1000000.0 + (stop.tv_usec - start.tv_usec) ;
	elapsed_time = elapsed_time / 1000.0;

	std::cout << "Time to process a range of " << deq.size() << \
					" elements with std::deque: " << \
					std::fixed << std::setprecision(6) << \
					elapsed_time << " ms" << std::endl;
	return (deq);
}

