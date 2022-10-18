//Hello World program

#include<iostream>
using namespace std;
int main() {
	
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int k = n - i; k >= 1; --k) {
			std::cout << " ";
		}
		for (int k = i; k >= 1; --k) {
			std::cout << k;
		}
		std::cout << std::endl;
	}
	for (int i = n-1; i >=1; --i) {
		for (int k = n - i; k >= 1; --k) {
			std::cout << " ";
		}
		for (int k = i; k >= 1; --k) {
			std::cout << k;
		}
		std::cout << std::endl;
	}

	return 0;
}