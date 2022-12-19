#include<iostream>

int main() {

	int n;
	std::cin >> n;

	for (int i = 1; i <= n+2; ++i) {
		std::cout << "#";
	}
	std::cout << std::endl;
	for (int i = 1; i <= n; ++i) {

		std::cout << "#";
		for (int j = i; j <= n; ++j)
			std::cout << j;
		for (int j = 1; j < i; ++j)
			std::cout << j;

		std::cout <<"#"<< std::endl;
	}
	std::cout << "#";  // (n-1)/2 && (n+1)/2
	if (n % 2 == 0) {  // 1 2 3 4 5 6 7 8
		for (int i = 1; i <= n; ++i) {
			if (i == n / 2 || i == n/2+1)
				std::cout << "X";
			else std::cout << " ";
		}
	}
	else {
		for (int i = 1; i <= n; ++i) {
			if (i == (n + 1) / 2)
				std::cout << "X";
			else std::cout << " ";
		}

	}
	std::cout << "#"<<std::endl;
	for (int i = n; i >= 1; --i) {

		std::cout << "#";
		for (int j = i; j <= n; ++j)
			std::cout << j;
		for (int j = 1; j < i; ++j)
			std::cout << j;

		std::cout << "#" << std::endl;
	}
	for (int i = 1; i <= n + 2; ++i) {
		std::cout << "#";
	}
	std::cout << "\n";

	return 0;
}