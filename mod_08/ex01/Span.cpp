#include "includes/Span.hpp"

Span::Span(unsigned int N): _max_size(N) {
	_numbers.reserve(N);
}

void Span::addNumber(int number) {

	if (_numbers.size() >= _max_size) {
		throw std::out_of_range("Adding numbers is impossible, span is full!");
	}
	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to calculate a span!");
	}

	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int min_span = std::numeric_limits<int>::max();

	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < min_span) {
			min_span = span;
		}
	}

	return (min_span);
}

int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw std::logic_error("Not enough numbers to calculate a span!");
	}

	int max_num = *std::max_element(_numbers.begin(), _numbers.end());
	int min_num = *std::min_element(_numbers.begin(), _numbers.end());

	return (max_num - min_num);
}

template<typename T>
void Span::addNumbers(T begin, T end) {
	if (std::distance(begin, end) > _max_size - _numbers.size()) {
		throw std::out_of_range("Range exceeds max capacity of span!");
	}
	_numbers.insert(_numbers.end(), begin, end);
}




