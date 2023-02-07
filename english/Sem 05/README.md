## Arrays (fixed length)

An **array** is an ordered sequence of elements of the same type.
An individual array element is accessed by the array name followed by the sequence number (index) of the element in square brackets.

```c++
<type> <name>[<size>]
```
![array-example](https://simplesnippets.tech/wp-content/uploads/2018/03/array-diagram.jpg)

## Array initialization

```c++
int arr[5]; // Creates an array of 5 elements, each of which is an integer.
int arr2[] = {34, 21, 2, 66, 567}; // Creates an array of 5 elements.
int arr3[5] = {1,2,3}; // The remaining elements are filled with the default value. 
int arr4[]; //error
int arr5[4] = {1, 2, 3, 4, 5} // error
```

The size of the array must be a constant whose value is clear before the program is compiled.

```c++
int n;
cin >> n;
int arr[n]; //error!
```

```c++
const int SIZE = 4;
int arr[SIZE]; //ok!
```

## Достъп на елемент
В масивите имаме константен достъп до всеки един елемент. <br />
Достъпът става посредством индекси чрез оператора ```[]```. Индексацията започва от 0, т.к. по дефиниция за масив arr n-тия елемент се дефинира като елементът, който е на n елемента на брой разстояние от началния (който е arr[0], като &arr[0] = arr) . <br />

```c++
int arr[] = {1, 2, 400, 4, 5}

arr[3] = 44; //Присвоява на елементът на индекс 3 стойността 44.
             // [1, 2, 400, 44, 5]

std::cout << arr[2]; //Отпечатва на стандартния изход елементът на индекс 2 (400)
```

arr не е самият масив, а **указател към първия елемент**.
```c++
int arr[] = {1, 2, 400, 4, 5}

std::cout << arr; //ще се отпечата АДРЕСА на масива, но не и самия масив.
```

Достъпът до елемент става, чрез смятането адреса му.  <br />
Адресът на arr[i] е: arr + i * sizeof(type of array).  <br />
i е брой "отмествания" надясно.  <br />

## Подаване на масиви във функции
```c++
#include <iostream>

void Print(const int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void Increment(int arr[], unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		arr[i]++;
	}
}

int main()
{
	const int SIZE = 4;
	int arr[SIZE]{ 1, 2, 3, 4 };

	Increment(arr, SIZE);
	Print(arr, SIZE);

	return 0;
}
```

```c++
#include <iostream>

using namespace std;

void Print(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void Increment(int* arr, unsigned size)
{
	for (unsigned i = 0; i < size; i++)
	{
		arr[i]++;
	}
}


int main()
{
	const int SIZE = 4;
	int arr[SIZE]{ 1, 2, 3, 4 };

	Increment(arr, SIZE);
	Print(arr, SIZE);

	return 0;
}
```

Масивите се подават във функциите по адрес! <br />
Т.е промените, които се правят върху масива във функцията, ще се отразят върху подадения като параметър масив! <br />

## Задачи
- Отпечатване на масив.
- Обръщане на масив.

```c++
void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void reverseArray(int arr[], unsigned size) {
	for (int i = 0; i < size/2; ++i) {
		swap(arr[i], arr[size-1-i]);
	}
}

void printArray(const int arr[], unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
}

int main() {

	const unsigned size = 4;
	int arr[]={ 1,2,5,6 };

	printArray(arr, size);
	reverseArray(arr, size);
	std::cout << std::endl;
	printArray(arr, size);

	return 0;
}
```

- Linear array search.
- Binary (logarithmic) search - for sorted arrays.
```c++
bool linearSearch(int arr[], unsigned size, int element) {
	for (unsigned i = 0; i < size; ++i) {
		if (arr[i] == element) {
			return true;
		}
	}

	return false;
}

bool binarySearch(int arr[], unsigned size, int element) {
	unsigned fromIndex = 0,
		toIndex = size - 1;
	
	while (fromIndex <= toIndex) {

		unsigned middleIndex = fromIndex + (toIndex-fromIndex) / 2;

		if (arr[middleIndex] == element) {
			return true;
		}
		else if (arr[middleIndex] > element) {
			toIndex = middleIndex-1;
		}
		else {
			fromIndex = middleIndex+1;
		}

	}

	return false;
}
```
- Eratosthenes' solution.

```c++
void init(bool arr[], const unsigned size, bool value) {

	for (unsigned i = 0; i < size; ++i) {
		arr[i] = value;
	}
}

void sieveOfErathostenes(bool arr[], const unsigned size) {
	arr[0] = arr[1] = false;

	for (unsigned i = 2; i < size; ++i) {

		if (!arr[i]) {
			continue;
		}

		for (unsigned j = i + i; j < size; j += i) {
			arr[j] = false;
		}
	}
}

void printSieve(bool arr[], const unsigned num) {
	for (unsigned i = 0; i < num; ++i) {
		if (arr[i]) {
			std::cout << i<<" ";
		}
	}
}

int main()
{
	const unsigned MAX_SIZE = 200;
	bool arr[MAX_SIZE];

	int n;
	cin >> n;

	init(arr, n, true);
	sieveOfErathostenes(arr, n);
	printSieve(arr, n);
}
```