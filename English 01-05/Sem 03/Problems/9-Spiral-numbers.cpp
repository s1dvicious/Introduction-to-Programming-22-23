//Hello World program

#include<iostream>
using namespace std;
int main() {
	
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {

			if (j % 2 == 0) {
				std::cout << j * n + i;
			}
			else {
				std::cout << (j + 1) * n - (i-1);
			}

		}
		std::cout << std::endl;
	}

	return 0;
}