#include "cake.hpp"

int main(int argc, char **argv) {
	int width,
	height,
	age,
	status;
	char name[20];
	std::cout << "Width: ";
	std::cin >> width;
	std::cout << "Height: ";
	std::cin >> height;
	std::cout << "Age: ";
	std::cin >> age;
	std::cout << "Status: ";
	std::cin >> status;
	std::cout << "name: ";
	std::cin >> name;
	cake(42, 14, 14, 2, "Sandy");
	system("pause");
	return 0;
}