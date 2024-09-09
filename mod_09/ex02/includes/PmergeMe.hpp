#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define BRIGHT_BLACK   "\033[90m"
#define BRIGHT_RED     "\033[91m"
#define BRIGHT_GREEN   "\033[92m"
#define BRIGHT_YELLOW  "\033[93m"
#define BRIGHT_BLUE    "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN    "\033[96m"
#define BRIGHT_WHITE   "\033[97m"
#define BG_BRIGHT_BLACK   "\033[100m"
#define BG_BLUE "\033[44m"
#define BG_YELLOW "\033[43m"
#define BG_BRIGHT_RED "\033[101m"
#define BG_BRIGHT_YELLOW "\033[103m"
#define BG_BRIGHT_GREEN "\033[102m"

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <iomanip>
#include <sys/time.h>
#include <cstdlib>
#include <climits>
#include <deque>
#include <set>
#include <vector>


class PmergeMe {
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();

	std::vector<int> getVector();
	void printBefore(int inp_cnt, char **inp);
	void printAfter();


	const std::vector<int> sortVector();
	const std::deque<int> sortDeque();

	std::vector<int> sorted_vec;
	std::deque<int> sorted_deq;

private:
	int _odd_member;

	std::vector<int> _vec;
	std::deque<int> _deq;

	double _el_time_vec;
	double _el_time_deq;

	std::vector<int> genJacobsthalVec(int n);
	std::vector<int> mergeVectors(std::vector<int> &left, std::vector<int> &right);
	std::vector<int> mergeSortVec(std::vector<int> &vec);


	bool pushValToContainers(const char *argv);
	std::vector<int>::iterator getVecInsertPosition(std::vector<int> &vec, int value);
	std::deque<int>::iterator getDeqInsertPosition(std::deque<int> &deq, int value);

	std::vector<std::pair<int, int> > createVecPairs(std::vector<int> &vec);
	std::deque<std::pair<int, int> > createDeqPairs(std::deque<int> &deq);

	std::vector<int> mergeToVector(std::vector<std::pair<int, int> > &pairs);
	std::deque<int> mergeToDeque(std::deque<std::pair<int, int> > &pairs);


};


#endif
