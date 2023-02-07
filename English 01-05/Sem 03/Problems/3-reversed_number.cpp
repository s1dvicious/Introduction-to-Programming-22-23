//Hello World program

#include<iostream>
using namespace std;
int main() {
	
	int number;
	std::cin >> number;

	int reversed=0;

	while (number != 0) {
		int lastDigit = number % 10;
		(reversed *= 10) += lastDigit;
		number /= 10;
	}

	++reversed;

	std::cout << reversed;

	return 0;
}