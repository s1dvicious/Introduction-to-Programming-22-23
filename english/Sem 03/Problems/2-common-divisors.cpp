//Hello World program

#include<iostream>
using namespace std;
int main() {
	
	int n, k;
	std::cin >> n >> k;

	if (k > n) {
		int temp = n;
		n = k;
		k = temp;
	}

	for (int i = k; i >=2; --i) {
		if (k % i == 0 && n % i == 0) {
			std::cout << i << " ";
		}
	}

	return 0;
}