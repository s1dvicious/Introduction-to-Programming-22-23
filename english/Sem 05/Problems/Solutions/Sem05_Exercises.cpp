#include <iostream>

int gcd(int a, int b) {
	while (b != 0)
	{
		int temp = a;
		a = b;
		b = temp % b;
	}

	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int findLCM(int arr[], int length) {
	if (length == 0) {
		return 0;
	}

	int arrayLCM = arr[0];
	for (int i = 1; i < length; i++) {
		arrayLCM = lcm(arrayLCM, arr[i]);
	}

	return arrayLCM;
}

int findGCD(int arr[], int length) {
	if (length == 0) {
		return 0;
	}

	int arrayGCD = arr[0];
	for (int i = 1; i < length; i++) {
		arrayGCD = gcd(arrayGCD, arr[i]);
	}

	return arrayGCD;
}

bool isPalindrome(int arr[], int length) {
	for (int i = 0; i < length / 2; i++) {
		if (arr[i] != arr[length - 1 - i]) {
			return false;
		}
	}

	return true;
}

bool isPalindromeConcatenation(int arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		if (isPalindrome(arr, i) && isPalindrome(arr + i, length - i))
		{
			return true;
		}
	}

	return false;
}

void printArray(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;
}

void printMatrix(int arr[][3], int rows, int cols) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			std::cout << arr[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

bool isInBounds(int i, int j, int rows, int cols) {
	return i >= 0 && j >= 0 && i < rows && j < cols;
}

int accessElement(int arr[][3], int i, int j) {
	if (!isInBounds(i, j, 2, 3)){
		return -1; // not the best example
	}

	return arr[i][j];
}

int main()
{
	int arr[2][3] = { {0, 1, 2}, {3, 4, 5} };

	// 0 1
	// 0 1 2
	std::cout << accessElement(arr, 20, 4);
}