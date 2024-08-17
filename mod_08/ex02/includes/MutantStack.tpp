#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::~MutantStack() {

}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other) {
	this->c = other.c;
	return *this;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other): std::stack<T>(other) {

}

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {

}

template<typename T>
void MutantStack<T>::addNumbers(const T *nums_arr, size_t size) {
	for (size_t i = 0; i < size; ++i) {
		this->push(nums_arr[i]);
	}
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return this->c.end();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}
