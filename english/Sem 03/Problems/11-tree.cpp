//This prints something

#include<iostream>

using namespace std;


int main() {

	int n;

	std::cin >> n;

	while (!(n >= 2 && n <= 9)) {
		std::cout << "Please provide a valid input!\n";
		std::cin >> n;
	}

	for (int i = 1; i <= n; ++i) {

		for (int j = 1; j <= n - i; ++j)
			std::cout << " ";
		for (int j = 1; j <= i; ++j)
			std::cout << j;
		for (int j = i-1; j >= 1; --j)
			std::cout << j;
		for (int j = 1; j <= n - i; ++j)
			std::cout << " ";

		std::cout << std::endl;
	}

	for (int i = n - 1; i >= 1; --i) {

		for (int j = 1; j <= 2 * n - 1; ++j) {
			if (j == n)
				std::cout << i;
			else std::cout << " ";
		}
		std::cout << std::endl;

	}

	return 0;
}