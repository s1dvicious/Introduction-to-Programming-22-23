//This prints something

#include<iostream>

using namespace std;

//Задача 4
//Да се напише функция, която приема три естествени числа a и b и k отпечатва всички числа в интервата [a...b], които имат точно k различни прости делители. 

//*Вход: 19 32 3, Изход: 20 30* 
//*Вход: 19 32 1, Изход: 19 23 29 31*

bool isPrime(int n)
{
	double rootOfN = sqrt(n);
	for (int i = 2; i <= rootOfN; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int countOfUniqueSimpleDivisors(int n)
{
	int divisorsCount = 0;
	for (int i = 2; i <= n && n != 1; i++)
	{
		if (n % i == 0 && isPrime(i))
		{
			n /= i;
			divisorsCount++;

			if (n == 1)
				return divisorsCount;
		}
	}
	return -1; // Some divisors repeat themselves, so we can't have a proper count
}

void kCountOfSimpleDivisorsBetween(int a, int b, int k)
{
	for (int i = a; i <= b; i++)
	{
		if (countOfUniqueSimpleDivisors(i) == k)
			cout << i << " ";
	}
	cout << endl;
}

//Задача 5
//Да се напише функция, която приема естествено число n и отпечатва всички двойки , такива че a и b са прости и a + b = n <-> a = n - b 
void printPrimeNumberPairs(int n)
{
	for (int i = 2; i <= n / 2; i++)
	{
		if (isPrime(i) && isPrime(n - i))
			cout << i << ", " << n - i << endl;
	}
}

//Задача 6
//Да се напише функция, която приема две естествени числа a и b и отпечава всички числа k и интервала [a,b], такива че k = x^y (за някои ест. числа x и y) 
//*Вход: 15 30, Изход: 16 25 27* , защото (4^2, 5^2, 3^3)

bool isPowerOfSomething(int n)
{
	double rootOfN = sqrt(n);
	for (int i = 2; i <= rootOfN; i++)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;

			return n == 1;
		}
	}
	return false; // Obligatory default case
}

void powerNumbersBetween(int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		if (isPowerOfSomething(i))
			cout << i << " ";
	}
	cout << endl;
}


int main()
{
	cout << containOnlyOneDigit(444) << endl;
}

