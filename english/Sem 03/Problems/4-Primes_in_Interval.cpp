#include<iostream>
using namespace std;
int main() {
	
	int a, b;
	std::cin >> a >> b;

	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}

	for (int i = a; i <= b; ++i) {
		// we need to check if i is prime - how do we do that?
		bool isPrime = true;
		for (int j = 2; j <= sqrt(i); ++j) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}

		if (isPrime) {
			std::cout << i << " ";
		}
	}


	return 0;
}