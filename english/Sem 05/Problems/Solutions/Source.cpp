#include <iostream>
using namespace std;


//1 задача - Да се напише функция, която приема масив и връща дали е палиндром
//Вход: [1 2 3 2 1], Изход: true

bool isPalindrome(const int arr[], const unsigned size) {

	for (int i = 0; i < size / 2; ++i) {
		if (arr[i] != arr[size - 1 - i]) {
			return false;
		}
	}

	return true;
}

//Задача 2. Да се напише функция, която приема масив и връща най-големият общ делител на числата в масива
int _gcd(int n, int k) {

	//presume that n>k
	if (k > n) {
		// swap their values
		int temp = n;
		n = k;
		k = temp;
	}

	while (k != 0) {
		int remainder = n % k;
		n = k;
		k = remainder;
	}

	return n;
}

int arrayGCD(const int arr[], const unsigned size) {

	int gcd = arr[0];
	for (unsigned i = 1; i < size; ++i) {
		gcd = _gcd(gcd, arr[i]);
	}

	return gcd;
}

//Задача 3. Да се напише функция, която приема масив и връща най-малкото общо кратно на числата в масива

int arrayLCM(const int arr[], const unsigned size) {

	int _lcm = arr[0];

	for (unsigned i = 1; i < size; ++i) {
		_lcm = _lcm * arr[i] / _gcd(_lcm, arr[i]);
	}

	return _lcm;
}

//Задача 4. Да се напише функция, която приема масив и връща дали е конкатенация на два масива, които са палиндроми

bool isPalindromeRange(const int arr[], unsigned from, unsigned to) {


	for (int i = from; i <= (to+from) / 2; ++i) {

		if (arr[i] != arr[to+from - i]) {
			return false;
		}
	}

	return true;
}
bool isConcatenatedByPalindromes(const int arr[], const unsigned size) {

	for (int i = 0; i < size - 1; ++i) {

		if (isPalindromeRange(arr, 0, i) && isPalindromeRange(arr, i + 1, size-1)) {
			return true;
		}

	}
	return false;
}

//Задача 5.Въвежда се число N (N <= 1000) и N цели числа (елементи на масив). Да се отпечатат броя на инверсиите в масива.
// Инверсия ще наричаме двойка индекси (i,j), където i < j и arr[i] > arr[j]

unsigned findInversions(const int arr[], const unsigned size) {

	unsigned inversionsCount = 0;

	for (unsigned i = 0; i < size - 1; ++i) {
		for (unsigned j = i + 1; j < size; ++j) {

			if (arr[i] > arr[j]) {
				++inversionsCount;
			}

		}
	}

	return inversionsCount;
}

int main()
{
	
}