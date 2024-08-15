template<typename T>
typename T::const_iterator easyfind(T &cont, int val) {
	typename T::const_iterator iter;
	iter = std::find(cont.begin(), cont.end(), val);
	if (iter == cont.end()) {
		throw std::out_of_range("Element not found in container!");
	}
	return iter;
}
