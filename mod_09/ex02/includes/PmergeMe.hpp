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
#include <ctime>
#include <cstdlib>
#include <climits>
#include <deque>
#include <list>
#include <vector>


class PmergeMe {
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();

	void printVector(const std::vector<int> &vec);
	void printDeque();


	const std::vector<int> getVector();

private:
	int _odd_member;
	std::vector<int> _vec;
	std::deque<int> _deq;


	bool pushValToContainers(const char *argv);
	std::vector<int>::iterator getVecInsertPosition(std::vector<int> &vec, int value);
	std::deque<int>::iterator getDeqInsertPosition(std::deque<int> &deq, int value);

	std::vector<std::pair<int, int> > createVecPairs(std::vector<int> &vec);
	std::deque<std::pair<int, int> > createDeqPairs(std::deque<int> &deq);

	std::vector<int> mergeToVector(std::vector<std::pair<int, int> > &pairs);
	std::deque<int> mergeToDeque(std::vector<std::pair<int, int> > &pair);


};


#endif
