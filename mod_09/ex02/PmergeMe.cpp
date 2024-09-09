#include "includes/PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv): _odd_member(-1), _el_time_vec(0), _el_time_deq(0) {
		int last = argc - 1;


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
			if (!pushValToContainers(argv[i])) {
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

	struct timeval vec_start, vec_stop;
	struct timeval deq_start, deq_stop;

	gettimeofday(&vec_start, NULL);
	_vec.push_back(intValue);
	gettimeofday(&vec_stop, NULL);

	gettimeofday(&deq_start, NULL);
	_deq.push_back(intValue);
	gettimeofday(&deq_stop, NULL);

	double vec_time = (vec_stop.tv_sec - vec_start.tv_sec) * 1000000.0 + (vec_stop.tv_usec - vec_start.tv_usec);
	vec_time = vec_time / 1000.0;
	this->_el_time_vec += vec_time;


	double deq_time = (deq_stop.tv_sec - deq_start.tv_sec) * 1000000.0 + (deq_stop.tv_usec - deq_start.tv_usec);
	deq_time = deq_time / 1000.0;
	this->_el_time_deq += deq_time;


	return (true);
}


std::vector<std::pair<int, int> >
	PmergeMe::createVecPairs(std::vector<int> &vec) {
	std::vector<std::pair<int, int> > vec_pairs;

	for(size_t i = 0; i + 1 < vec.size(); i += 2) {
		if (vec[i + 1] < vec[i]) {
			vec_pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		}
		else {
			vec_pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}
	}

	return (vec_pairs);
}


std::deque<std::pair<int, int> >
	PmergeMe::createDeqPairs(std::deque<int> &deq) {
	std::deque<std::pair<int, int> > deq_pairs;

	for(size_t i = 0; i + 1 < deq.size(); i += 2) {
		if (deq[i + 1] < deq[i]) {
			deq_pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
		}
		else {
			deq_pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		}
	}

	return (deq_pairs);
}



std::vector<int> PmergeMe::genJacobsthalVec(int n) {
	std::vector<int> seq;
	if (n == 0) return seq;

	seq.push_back(0);
	if (n == 1) return seq;

	seq.push_back(1);

	for (int i = 2; i < n; ++i) {
		long long next_value = seq[i - 1] + 2 * seq[i - 2];
		if (next_value >= n) {
			break;
		}
		seq.push_back(static_cast<int>(next_value));
	}

	std::cout << "Jacobshtal: ";
	for (size_t i = 0; i < seq.size(); ++i) {
		std::cout << seq[i] << " ";
	}
	std::cout << std::endl;

	return (seq);
}

std::vector<int> PmergeMe::mergeSortVec(std::vector<int> &vec) {

	if (vec.size() <= 1) {
		return (vec);
	}

	int mid = vec.size() / 2;
	std::vector<int> left(vec.begin(), vec.begin() + mid);
	std::vector<int> right(vec.begin() + mid, vec.end());

	left = mergeSortVec(left);
	right = mergeSortVec(right);

	return (mergeVectors(left, right));
}

std::vector<int>
PmergeMe::mergeVectors(std::vector<int> &left, std::vector<int> &right) {

	std::vector<int> vec;
	size_t  i = 0;
	size_t  j = 0;

	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j]) {
			vec.push_back(left[i]);
			i++;
		}
		else {
			vec.push_back(right[j]);
			j++;
		}
	}

	while (i < left.size()) {
		vec.push_back(left[i]);
		++i;
	}

	while (j < right.size()) {
		vec.push_back(right[j]);
		j++;
	}
	return (vec);
}



std::vector<int>
PmergeMe::mergeToVector(std::vector<std::pair<int, int> > &pairs) {
	std::vector<int> small_nums;
	std::vector<int> big_nums;
	std::vector<int> srt_small_nums;

	for (size_t i = 0; i < pairs.size(); ++i) {
		small_nums.push_back(pairs[i].first);
		big_nums.push_back(pairs[i].second);
	}

	srt_small_nums = mergeSortVec(small_nums);

	std::vector<int> jacobshtal_seq = genJacobsthalVec(big_nums.size());

	std::set<int> used_indices;

	for (size_t i = 0; i < big_nums.size(); ++i) {
		size_t idx = jacobshtal_seq[i];

		if (idx >= big_nums.size()) {
			continue;
		}

		if (used_indices.find(idx) != used_indices.end()) {
			continue;
		}

		std::vector<int>::iterator pos = getVecInsertPosition(srt_small_nums, big_nums[idx]);
		srt_small_nums.insert(pos, big_nums[idx]);

		used_indices.insert(idx);
	}

	for (size_t i = 0; i < big_nums.size(); ++i) {
		if (used_indices.find(i) == used_indices.end()) {
			std::vector<int>::iterator pos = getVecInsertPosition(srt_small_nums, big_nums[i]);
			srt_small_nums.insert(pos, big_nums[i]);
		}
	}

	if (_odd_member != -1) {
		std::vector<int>::iterator pos = getVecInsertPosition(srt_small_nums, _odd_member);
		srt_small_nums.insert(pos, _odd_member);
	}

	return (srt_small_nums);
}


const std::vector<int> PmergeMe::sortVector() {
	std::vector<int> vec;
	std::vector<std::pair<int, int> > pairs;

	struct timeval start, stop;
	gettimeofday(&start, NULL);

	pairs = createVecPairs(_vec);
	vec = mergeToVector(pairs);

	gettimeofday(&stop, NULL);

	double el_time_vec = (stop.tv_sec - start.tv_sec) * 1000000.0 + (stop.tv_usec - start.tv_usec);
	el_time_vec = el_time_vec / 1000.0;
	this->_el_time_vec += el_time_vec;


	return (vec);
}

void PmergeMe::printBefore(int inp_cnt, char **inp) {

	std::cout << "\n" << BG_BLUE BRIGHT_YELLOW "Before: " << RESET BRIGHT_YELLOW;
	for (int i = 1; i < inp_cnt; i++) {
		std::cout << inp[i] << " ";
	}
	std::cout << RESET << std::endl;

}


void PmergeMe::printAfter() {

	std::cout << "\n" << BG_BLUE BRIGHT_GREEN "After: " RESET BRIGHT_GREEN;
	for (size_t i = 0; i < sorted_vec.size(); ++i) {
		std::cout << sorted_vec[i] << " ";
	}
	std::cout << RESET << "\n" << std::endl;

	std::cout << "Time to process a range of " << BRIGHT_WHITE << sorted_vec.size() << RESET \
					" elements with " BRIGHT_MAGENTA "std::vector" RESET ": " << \
					std::fixed << std::setprecision(6) << BRIGHT_MAGENTA << \
					_el_time_vec << " ms" << RESET << std::endl;


	std::cout << "Time to process a range of " << BRIGHT_WHITE << _deq.size() << RESET \
					" elements with " BRIGHT_CYAN  "std::deque" RESET ": "  << \
					std::fixed << std::setprecision(6) << BRIGHT_CYAN << \
					_el_time_deq << " ms" << RESET << std::endl;

}



std::vector<int> PmergeMe::getVector() {
	return (_vec);
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


const std::deque<int> PmergeMe::sortDeque() {
	std::deque<int> deq;
	std::deque<std::pair<int, int> > pairs;

	struct timeval start, stop;
	gettimeofday(&start, NULL);

	pairs = createDeqPairs(_deq);
	deq = mergeToDeque(pairs);

	gettimeofday(&stop, NULL);

	double el_time_deq = (stop.tv_sec - start.tv_sec) * 1000000.0 + (stop.tv_usec - start.tv_usec) ;
	el_time_deq = el_time_deq / 1000.0;
	this->_el_time_deq += el_time_deq;

	return (deq);
}
