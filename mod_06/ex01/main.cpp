#include "Serializer.hpp"


int main() {

	struct Data {
		int num;
		std::string str;
	};

	Data data = {42, "Don't panic!"};
	Data *data_ptr = &data;

	uintptr_t serialized = Serializer::serialize(data_ptr);
}