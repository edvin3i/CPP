#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

std::string myReplace(std::string input_str, const std::string &old_str, const std::string &new_str) {
	size_t pos = 0;

	while ((pos = input_str.find(old_str, pos)) != std::string::npos)
	{
		input_str = input_str.substr(0, pos) + new_str + input_str.substr(pos + old_str.length());
		pos += new_str.length();
	}
	return input_str;

}

int main(int argc, char **argv) {

	if (argc == 1)
	{
		std::cerr << "Pass as an arguments a filename and two strings" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename> <old_str> <new_str>" << std::endl;
		return 1;
	}
	else if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}
	std::string filename(argv[1]);
	std::string old_str(argv[2]);
	std::string new_str(argv[3]);

	std::ifstream in_file(filename.c_str(), std::ifstream::in);
	if (!in_file.is_open()) {
		std::cerr << "Error opening file: " << filename << "!" << std::endl;
		return 1;
	}

	std::stringstream buffer;
	buffer << in_file.rdbuf();
	std::string content = buffer.str();
	in_file.close();

	std::string replaced_content = myReplace(content, old_str, new_str);

	std::ofstream out_file(filename.append(".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!out_file.is_open()) {
		std::cerr << "Error creating file: " << filename.append(".replace") << "!" << std::endl;
		return 1;
	}
	out_file << replaced_content;
	out_file.close();

	return 0;
}