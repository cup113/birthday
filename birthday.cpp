#include "cake.hpp"

int main(int argc, char **argv) {
	int width = 28,
	height = 10,
	age = 18,
	status = 2;
	std::string name = "Joe";
	cake(width, height, age, status, name.c_str());
	system("pause");
	return 0;
}