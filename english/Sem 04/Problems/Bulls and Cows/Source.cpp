#include <iostream>
using namespace std;

const int digits_count = 4;


//an input is valid if it contains digits_count amount of digits
//and all are distinct
int getLength(int n) {
	if (n == 0) {
		return 1;
	}
	int count = 0;

	while (n != 0) {
		++count;
		n /= 10;
	}

	return count;
}

bool containsDigit(int number, int digit) {
	if (digit < 0 || digit>9) {
		//Invalid input
		return false;
	}
	while (number != 0) {
		int lastDigit = number % 10;
		if (lastDigit == digit) {
			return true;
		}
		number /= 10;
	}

	return false;
}

bool areDigitsDistinct(int number) {
	while (number != 0) {

		int lastDigit = number % 10;
		int remainder = number / 10;

		if (containsDigit(remainder, lastDigit)) {
			return false;
		}

		number = remainder;
	}

	return true;
}
bool isValid(int input) {
	return (getLength(input) == digits_count && areDigitsDistinct(input));
}
void userInput(int& input) {

	do {

		std::cin >> input;

	} while (!isValid(input));

}

int getBullsCount(int toGuess, int guess) {

	int bullsCount = 0;

	while (toGuess != 0) {
		if (toGuess % 10 == guess % 10) {
			++bullsCount;
		}
		toGuess /= 10;
		guess /= 10;
	}

	return bullsCount;
}
//Cows count is - N(amount of coinciding digits) - bullsCount;
unsigned getBullsCowsSum(int toGuess, int guess) {

	int count = 0;

	while (guess != 0) {

		int lastDigit = guess % 10;

		if (containsDigit(toGuess, lastDigit)) {
			++count;
		}
		guess /= 10;
	}

	return count;
}

void calculateBullsAndCows(int toGuess, int myGuess, unsigned& bullsCount, unsigned& cowsCount) {
	bullsCount = getBullsCount(toGuess, myGuess);
	cowsCount = getBullsCowsSum(toGuess, myGuess) - bullsCount;
}

int main()
{
	int numberToGuess;
	//User input function where a validation is to be made
	userInput(numberToGuess);
	std::cout << "Successful input. Guess the number now." << std::endl;

	unsigned bullsCount = 0,
		cowsCount = 0;

	while (bullsCount != digits_count) {

		int guessedNumber;
		userInput(guessedNumber);

		calculateBullsAndCows(numberToGuess, guessedNumber, bullsCount, cowsCount);

		std::cout << "Bulls - " << bullsCount << ", cows - " << cowsCount<<std::endl;
	}
	std::cout << "Success! The number has been deciphered!";

		return 0;
}