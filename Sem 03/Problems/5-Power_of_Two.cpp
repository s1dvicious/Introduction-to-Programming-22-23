//Hello World program

#include<iostream>
using namespace std;
int main() {
	
	int number;
	std::cin >> number;

	bool isTwoPower = true;
	while (number > 1) {
		if (number % 2 != 0) {
			isTwoPower = false;
			break;
		}

		number /= 2;
	}

	if (isTwoPower) {
		std::cout << "The number is a power of two";
	}
	else {
		std::cout << "The number is not a power of two";
	}

	return 0;
}