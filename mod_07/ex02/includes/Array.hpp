#ifndef ARRAY_HPP
#define ARRAY_HPP

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

#include <string>
#include <cstdlib>
#include <iostream>
#include <exception>

template <typename T = int>
class Array {
public:
	Array();
	explicit Array(unsigned int n);
	Array<T> &operator=(const Array<T> &other);
	Array(const Array<T> &other);
	~Array();

	size_t size() const;

	T &operator[](unsigned int i);
	const T &operator[](unsigned int i) const;

	class IndexIsOutOfBounds: public std::exception {
	public:
		const char *what() const throw();
	};

private:
	size_t _size;
	T *_elements;


};

#include "Array.tpp"

#endif
