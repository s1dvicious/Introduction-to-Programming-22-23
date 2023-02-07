//Hello World program

#include<iostream>
using namespace std;
int main() {
	
	int a, b, c, d, e;
	std::cin >> a >> b >> c >> d >> e;

	for (int i = -100; i <= 100; ++i) {
		int expression = a * i * i * i * i + b * i * i * i + c * i * i + d * i + e;
		
		if (expression >= 0) std::cout << i << " ";
	}

	return 0;
}