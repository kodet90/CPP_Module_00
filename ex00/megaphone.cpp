#include <iostream>

static void put_uppercase(char c) {
	std::cout << static_cast<char>(std::toupper(c));
}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < argc; i++) {
		std::string str = argv[i];
		std::for_each(str.begin(), str.end(), put_uppercase);
	}
	std::cout << std::endl;
	return 0;
}
