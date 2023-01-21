#include <iostream>
using namespace std;

void countLower(const char* str, int* arr, size_t& sortedSize) {

	while (*str != '\0') {

		if (isLower(*str)) {
			++arr[*str-'a'];
			++sortedSize;
		}

		++str;
   }
}

char* sortLowerCases(const char* str) {

	int lowerCount[alphabet_size] = { 0 };

	size_t sortedSize = 0;
	countLower(str, lowerCount, sortedSize);

	char* sortedCases = new char[sortedSize+1];

	size_t sortedIndex = 0;
	for (size_t i = 0; i < alphabet_size; ++i) {

		while (lowerCount[i] > 0) {
			sortedCases[sortedIndex++] = 'a' + i;
			--lowerCount[i];
		}

	}
	sortedCases[sortedIndex] = '\0';

	return sortedCases;
}
