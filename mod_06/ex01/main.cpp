#include "Serializer.hpp"


int main() {

	Data data = {42, "Don't panic!"};
	Data *data_ptr = &data;

	uintptr_t serialized = Serializer::serialize(data_ptr);
	Data *deserialized = Serializer::deserialize(serialized);

	if (data_ptr == deserialized) {
		std::cout << "Test output of structure 'Data': " << std::endl;
		std::cout << "Number: " << deserialized->num << std::endl;
		std::cout << "String: " << deserialized->str << std::endl;
	}
	else {
		std::cout << "Something went wrong!" << std::endl;
	}

	return (0);
}