#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

struct Data {
	int num;
	std::string str;
};

class Serializer {
public:
	~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
};


#endif
