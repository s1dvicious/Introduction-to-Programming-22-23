# Бройни системи и побитови операции
Бройните системи представят начин за представяне на числата чрез краен брой такива. Определяме естествено число b>1, което наричаме база/основа на бройната система, откъдето и b на брой числа - {0,1,...,b-1} = beta. Идеята е, че всяко число сега ще се представи като степенен ред по b с коефициенти от beta. Най-общо, числата се представят като  
```(an,an-1,...,a1,a0,.,c0,c1,...)(b)=SUM(a_k b^k)+Sum(c_k b^(-k))```

| Десетична (decimal) | Двоична (binary) | осмична (octal) | Шестнайсетична (hexadecimal) |
|---------------------|------------------|-----------------|------------------------------|
| 00                  | 00000            | 00              | 00                           |
| 01                  | 00001            | 01              | 01                           |
| 02                  | 00010            | 02              | 02                           |
| 03                  | 00011            | 03              | 03                           | 
| 04                  | 00100            | 04              | 04                           | 
| 05                  | 00101            | 05              | 05                           |
| 06                  | 00110            | 06              | 06                           | 
| 07                  | 00111            | 07              | 07                           |
| 08                  | 01000            | 10              | 08                           | 
| 09                  | 01001            | 11              | 09                           |
| 10                  | 01010            | 12              | 0A                           |
| 11                  | 01011            | 13              | 0B                           |
| 12                  | 01100            | 14              | 0C                           |
| 13                  | 01101            | 15              | 0D                           |

#### Преобразуване между бройни системи

Примери:

 - Алгоритъм за преобразуване от десетична бройна система в двоична бройна система
 - Алгоритъм за преобразуване от двоична бройна система в десетична бройна система
 
 ```c++
 unsigned fromBinary(unsigned n) {

	unsigned res = 0;
	int mult = 1;

	while (n != 0) {

		res += ((n % 2) * mult);

		mult *= 2;
		n /= 10;
	}

	return res;
}

unsigned long long toBinary(unsigned n) {

	int result = 0;
	int mult = 1;
	while (n != 0)
	{
		if (n % 2 == 1)
			result += mult;
		mult *= 10;
		n /= 2;
	}
	return result;
}
 ```

 - Алгоритъм за преобразуване от произволна бройна система в дестична бройна система и обратно
```c++
const unsigned MAX_SIZE = 32;

void initBuffer(char buff[], const unsigned start) {

	for (unsigned i = start; i < MAX_SIZE; ++i) {
		buff[i] = ' ';
	}

}

char getSymbolByIndex(unsigned index) {

	//the number can be from 0 to 9, from 10 to 35 (we return a letter A to Z) or 

	if (index <= 9) {
		return '0' + index;
	}
	else if (index>=10 && index<=35) {
		return 'A' + (index-10);
	}
	else {
		return 'a' + (index - 10);
	}

}

void swap(char& a, char& b) {
	char temp = a;
	a = b;
	b = temp;
}

void convertFromDecimal(char buff[], unsigned number, unsigned base) {

	unsigned result = 0;
	unsigned mult = 1;

	unsigned index = 0;
	while (number > 0) {

		buff[index++] = getSymbolByIndex(number % base);

		number /= base;
	}
	//now we need to invert the array

	for (unsigned i = 0; i < index / 2; ++i) {
		swap(buff[i], buff[index - 1 - i]);
	}
}

void printArray(char buff[]) {
	for (unsigned i = 0; i < MAX_SIZE; ++i) {
		std::cout << buff[i];
	}
	std::cout << std::endl;
}

unsigned getNumberByChar(char symbol) {

	if (symbol >= '0' && symbol <= '9') {
		return symbol - '0';
	}
	else if (symbol >= 'A' && symbol <= 'Z') {
		return 10 + symbol - 'A';
	}
	else {
		return 61 + symbol - 'a';
	}

}

unsigned convertToDecimal(const char arr[], const unsigned size, const unsigned base) {

	unsigned result = 0;
	unsigned mult = 1;

	for (int i = size - 1; i >= 0; i--) {

		result += getNumberByChar(arr[i]) * mult;

		mult *= base;
	}

	return result;
}

int main() {
	
	{
		//from dec to any
		unsigned number;
		std::cin >> number;

		char buffer[MAX_SIZE];

		initBuffer(buffer, 0);
		convertFromDecimal(buffer, number, 16);

		printArray(buffer);
	}

	{
		//from any to dec

		char buffer[MAX_SIZE] = { 'A','3','F','8','0','B' };
		initBuffer(buffer, 7);

		unsigned result = convertToDecimal(buffer, 6, 16);

		std::cout << result;
	}

	return 0;
}
```

## Представяния на примитивните типове в паметта  

#### Представяния на положителни и отрицателни (числа)  

Всяко число се държи в паметта в двоичното си представяне, като при signed типовете старшият бит (най-левият) индикира знакът на числото - дали е отрицателно или положително. Нека за секунда се абстрахираме от този детайл и да разгледаме как се представя едно отрицателно число в паметта  
  <img src="https://www.log2base2.com/images/storage/negative-integer-storage.png" width=80% height=80%>   
  По този начин се гарантира, че, спазвайки правилата за събиране на двоични числа, като съберем едно число с отрицателното му ще получим 0 и тази 0 е единствена сама по себе си. Начинът, по който едно положително число се конвертира в положителното такова е илюстрирано по-горе (two's complement) - обръщаме битовете и добавяме 1ца накрая. При достъп на числото се прави проверка - положително ли е - ако не, то знакът се капсулира, взима се two's complement и накрая се образува окончателното число.  
  Числата с плаваща запетая се запаметяват по начин, аналогичен на горния, като 

#### Представяния на числата с плаваща запетая - аналогично на горното за отрицателните

Числата с плаваща запетая (floating point numbers) имат следното представяне - ```(-1)^s * b^(exp) * m```, където s индикира знака на числото, exp - експонентата, а m - мантисата (в нормализиран вид). В зависимост от precision-a (единична или двойна) еднозначно се определят и допустимите стойности за exp и m, например при float-овете имаме 1 бит за знака, 8 за експонентата и 23 за мантисата,т.е.  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/Single-Precision-IEEE-754-Floating-Point-Standard.jpg" width=80% height=80%>  
докато при числата с двойна точност (double precision) или double имаме 1 бит за знака, 11 за експонентата и 53 за мантисата, т.е.  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/Double-Precision-IEEE-754-Floating-Point-Standard-1024x266.jpg" width=80% height=80%>    
 
 #### Пример:
 ```
 85.25 (10) = 85(10) + 0.25(10) = 1010101(2)+ .01(2) = 1010101.01(2) = 1.01010101 * 2^6
 85 = 1010101(2)
 0.25 = 1.2^(-2) = .01 
 ```  
 а в паметта се представя като  
 ```
 0 10000101 01010100100000000000000
 ```  
 като забележете водещата 1-чка при експонентата служи за онази водеща 1ца, която имаме при мантисата.  
 
## Побитови операции
прилагат се върху един бит или набор от повече отделни битове на двоични числа. 

 - Побитово И (**&**)
 - Побитово ИЛИ  (**|**)
 - Побитово ИЗКЛЮЧВАЩО ИЛИ  (**^**)
 - Побитово отместване  (**<<** )     ( **>>**)
 - Побитово НЕ (**~**) - обръща всички нули в единици и обратно в двоичното представяне на числото.

|        |           |
|--------|-----------|
| a      | 101010100 |
| b      | 100101110 |
| a&b    | 100000100 |
| a \| b | 101111110 |
| a^b    | 001111010 |
| a << 2 | 101010000 |
| a >> 2 | 001010101 |
| ~a     | 010101011 |

Например  

```c++
int main(){

// a = 101  b = 10110
unsigned a = 5, b = 22;

// 00101 & 10110 = 00100 = 4(10)
std::cout<< (a & b);

// 00101 | 10110 = 10111 = 23
std::cout<< (a | b);

// 00101 ^ 10110 =  10011 = 19(10)
std::cout<< (a ^ b);

// 0101<<2 = 10100 = 20(10)
std::cout<< (a << 2);

// 0101>>1 = 1 = 1(10)
std::cout<< (a >> 2);

// ~ 101 = 1111...010, като единиците до първата нула отляво надясно са 29 на брой
std::cout<< (~a);
}
```

Примери:

 - Функция, която с побитови операции проверява дали число е четно  
```c++
void isOddOrEven(int num) {
	if (num & 1) {
		//last digit in the binary representation is 1, so the number is odd
		std::cout << "The number is odd.";
	}
	else {
		std::cout << "The number is even.";
	}
}
```
 - Функция, която с побитови операции намира по-голямото от две числа  
Имаме, че водещият бит (при signed числата) винаги индикира какъв ще е знакът - 1 за положителен, 0 за отрицателен. Тогава  

```c++
int findMax(int a, int b){

int z = a - b;  //now z can be positive or negative!

	// shift 31 bits to the right, i.e. translate the number to XXX...X k, where k = 1 or 0 , the X's are not of any value
  // since only the MSB is what we need
	// if k = 1 -> a is greater, else b is greater
	int ind = (z >> 31) & 1;

	int res = a - (z * ind);


	return res;
}
```
- Функция, която с побитови операции повдига 2 на степен k.
```c++
unsigned twoToThePowerOf(unsigned n) {
	
	unsigned res = 1;

	res <<= n;

	return res;
}
```
 - Функция, която с побитови операции проверява дали едно число N е степен на двойката  

```c++
bool isPowerOfTwo(unsigned num) {
  
	return (num && !(num & (num - 1)));
  
}
```
 - Функция, която с побитови операции умножава две числа  
```
Нека са зададени две числа - a и b. Имаме, че 
a*b = ((a*2)*(b/2)) ,ако b е четно, като a*2 е равносилно на a<<1 и b/2 е равносилно на b>>1
a*b = ((a*2)*(b/2) + a) ,ако b е нечетно, т.к. ако b = b0+1 за някое четно b0, то ((a*2)*(b/2)) = ((a*2)*((b0+1)/2)) = ((a*2)*(b0/2) + a)  

хващаме а1 = а*2, b1 = b1*2 и повтаряме горната процедура, като в крайна сметка  получаваме bi = 0, а в останалата част от събираемите - търсеното число
```
```c++
unsigned multiply(unsigned int a, unsigned int b) {

	// we will multiply a by b

	int res = 0;

	while (b > 0) {
		// if b is odd
		if (b & 1) {
			res += a;
		}
		a <<= 1; // same as a*=2
		b >>= 1; // same as b/=2
	}

	return res;
}
```
 - Функция, която с побитови операции намира корен квадратен на цяло число - **ако числото не е точен квадрат да се върне най-малкото цяло число**

<h3>Задачи</h3>

**Задача 1:** Напишете функция, която приема число от в произволна бройна система и преобразува **директно** (без да минава през десетична) числото в друга произволна бройна система.

**Задача 2** Да се напише функция, която приема масив, в който всяко число се среща 2 пъти с изключение на едно число, което се среща веднъж.
Напишете функция, която приема такъв масив и връща кое е това число.
(Подсказка: използвайте побитови операции, за да постигнете линейно решение)

*Вход: [9 18 9 12 18 15 12], Изход: 15*


**Задача 3** Напишете функция, която приема цяло число и връща броя на 1-ците в двоичния му запис.

*Вход: 189,  Изход: 6*

**Задача 4 :** Напишете функция, която приема цяло число и обръща най-десният бит в него, който е единица.

*Вход: 12, Изход: 8*

*Вход: 15, Изход: 14*

**Задача 5 :** Напишете функция, която приема цели числа n и k и обръща бита на k-та позиция в n (считаме, че индексацията започва от 1).

*Вход: 12, Изход: 8*

*Вход: 15, Изход: 14*

**Задача 6:** Напишете функция, която по подадено цяло число n и цяло число k и връща числото, което е "закодирано" в последните k бита на n.

*Вход: 15 2, Изход: 3*

*Вход: 189 3, Изход: 5*

*Вход: 189 4, Изход: 13*

**Задача 7:** Напишете функция, която приема цяло число n и цяло число k и връща дали k в двоичен запис (разглеждайки го без водещите 0-ли) е част от двоичния запис на n.

*Вход: 15 3, Изход: true*

*Вход: 13 5 Изход: true*

*Вход: 13 7, Изход: false*

**Задача 8:** Напишете функция, която приема масив(разглеждаме го като множество) и отпечатва всички негови подмножества.

*Вход: [1, 2, 3], Изход: [], [1], [2], [3], [1,2], [2,3], [1,3], [1,2,3]*

*Вход: 13 5 Изход: true*

*Вход: 13 7, Изход: false*

