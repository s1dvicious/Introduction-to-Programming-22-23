Consider the following problem:   

**Problem 1:** Enter a non-negative number n. Print all pairs of prime numbers that are of the form 6k-1 and 6k+1, and are less than n.  

Solve the problem as follows:  

```c++
int main()
{
	int n;
	cin >> n;
	
	for (int i = 6; i < n; i += 6)
	{
		int firstToCheck = i - 1;
		int secondToCheck = i + 1;

		//prime check
		bool isFirstPrime = true;
		double temp = sqrt(firstToCheck);
		for (int j = 2; j <= temp; j++)
		{
			if (firstToCheck % j == 0)
				isFirstPrime = false;
		}

		if (!isFirstPrime)
			continue;

		//prime check
		bool isSecondPrime = true;
		double temp2 = sqrt(secondToCheck);
		for (int j = 2; j <= temp2; j++)
		{
			if (secondToCheck % j == 0)
				isSecondPrime = false;
		}

		if (isSecondPrime)
			cout << firstToCheck << " " << secondToCheck << endl;
	}
}
```
Notice that the following piece of code
```c++
//prime check
		bool isFirstPrime = true;
		double temp = sqrt(firstToCheck);
		for (int j = 2; j <= temp; j++)
		{
			if (firstToCheck % j == 0)
				isFirstPrime = false;
		}

		if (!isFirstPrime)
			continue;
```
is repeated twice, both in the context of two different numbers, but the logic is duplicated, which is a standard programming situation that we aim to eliminate as much as possible. So, the question is - isn't it possible to collect these instructions by naming them, and instead of copy/paste-ing each time we need that particular functionality - just call the name of that group? The answer is yes and it is given by

## Functions

A function is a set of instructions that has a name and can be called from anywhere in the program. The syntax for declaring (and defining) a function is  

```c++
<data-type> name(<parameter-1>, <parameter-2>,...,<parameter-n>){
   //statements  
   
  }
```
where:  
- ***data-type*** is the type (e.g. char, float, int etc.) of the value we would get as a result of executing the function (on return);
- ***name*** - the name or identifier by which the function is called - the same naming rules apply here as with variables;
- ***parameters*** - each parameter consists of ***type*** and ***identifier***, with each two parameters separated by a comma. They represent nothing more than a declaration of a (function-local) variable. Their purpose is to allow arguments to be passed to the function from the location at which it is called;

### Example:
```c++
int max(int n, int k){
return n > k? n: k;
}
```
and at main we have:

```c++
int main(){
int x = 5,
    y = 10;
    
int z = max(x,y);

return 0;
}
```
Here, when the max function is called, the values of the variables x and y are taken and then set to the local variables for max - n and k. The result is checked and the value of the larger of the two numbers is returned. Note that we can also do the following
```c++
z = max(5, 10);
```
and here similarly the literals 5 and 10 are set to n and k, the order in which this happens corresponding to the order of the parameters.  
At the time of the call to the main function, control of the program is given entirely to the max function: execution of main stops and resumes only when execution of max finishes. 

For example, in the above problem, the functionality that we can encapsulate in a function is the check for whether (hence return type is bool) a number is prime, namely:  

```c++
bool isPrime(unsigned int k) {

	if (k <= 1) return false;

	double squareRoot = sqrt(k);

	for (size_t i = 2; i <= squareRoot; ++i) {
		if (k % i == 0) {
			return false;
		}
	}

	return true;
}
```
Here return-type-a is obviously boolean - the number passed as a parameter (positive, hence unsigned) is either prime or it is not. As for the //statement part of this function - the logic is completely inherited from the original solution to the problem. Another important thing is that all variables that are declared in the body are local to it and are deleted (from memory) when the function finishes executing, i.e. they cannot be accessed outside this scope.  
Now in main things look much cleaner and simpler:  
```c++
int main() {

	unsigned n;
	std::cin >> n;

	for (size_t k = 6; k < n; k += 6) {

		if (isPrime(k - 1) && isPrime(k + 1))
			std::cout << k - 1 << " " << k + 1 << std::endl;

	}

	return 0;
}
```
Here the important thing is also that in both function calls above what happens is that the value that is passed as a parameter is taken and it is set to the local (for isPrime) variable - k, i.e. this way the value is copied and reused locally.

### Examples:

**Problem 1:** A non-negative number n is entered. Print all pairs of prime numbers that are of the form 6k-1 and 6k+1.

-solved without functions and solved with functions.

**Problem 2:** Write a function that takes a non-negative number n and returns the number inverted

*Input: 288, Output: 882*

**Problem 3:** Write a function that takes a non-negative number and returns whether the number is a palindrome.

*Input: 2882 Output: true*

**Problem 4:** Write a function that accepts nonnegative numbers n and k and returns whether k is a suffix of n.

*Input: 288, 88, Output: true*

**Problem 5:** Write a function that accepts non-negative numbers n and k and returns whether k is a prefix of n.

*Input: 288, 28, Output: true*

**Problem 6:** Write a function that accepts nonnegative numbers n and k and returns whether k is an infix in n.

*Input: 2831, 83, Output: true*

**Problem 7:** Write a function that accepts a non-negative number and returns whether its digits are sorted (in ascending or descending order).

*Input: 122239, Output: true*

**Problem 8:** Write a function that takes a non-negative number and returns whether its digits are the same.

*Input: 111111, Output: true*

**Problem 9:** Write a function that takes a non-negative number n and k returns n^k

*Input: 3 4, Output: 81*

**Problem 10:** Write a function that takes non-negative numbers n and k returns log_k(n) (rounded down)

*Input: 90 3 Output: 4*


## Functions without return type - void
The above syntax requires specifying a particular type that the function returns. However, it is possible for the function to return nothing, in which case the <data-type> of the function is void, which is a special type that indicates no value. For example, the following function, which only prints to the console

```c++
void printHello(){

std::cout<<"Hello!\n";

}
```


## Passing parameters by value and reference

Consider the following piece of code
```c++
void increment(int n){
++n;
}
	
int main(){
int n = 5;
increment(n);
std::cout<<n; //prints 5, i.e. the value is not incremented
	
return 0;
}
```
where the purpose of the increment function is to increment its argument by 1s. The reason why the value of n is not changed after the function is passed is that its value is copied and passed to the increment local variable. However, another kind of passing is possible, namely to the variable itself (not just its value) and this is done by so-called references (aliases):
	
```c++
void increment(int& n){
++n;
}
	
int main(){
int n = 5;
increment(n);
std::cout<<n; //prints 6
	
return 0;
}
```
That is, instead of copying the value when we pass n as a parameter - we pass the real variable.  
Basically, references are variables that serve as aliases for other variables. The syntax for declaring a reference is
```c++
int n = 5;
	
int& nRef = n; // read from right to left - nRef is a reference to int
++nRef;
	
std::cout<<< n; //prints 6, since n's value was incremented through a reference to n, namely through nRef
```
An important detail about these is that they must be initialized (bound to another object) when declared. After initialization, the reference cannot be directed to another variable.  

## Call stack  
First of all, every declared function is stored in memory (translated into machine code), and there it contains information about all its components - declared local variables, parameters, temporary objects, etc. 
In stack memory, calls are based (as the name implies) on the LIFO (Last In First Out) principle, or the stack data structure principle. This gives rise to the equivalent term ***stack grid*** for function calls. At its simplest, each call to a function allocates memory, which is held in a special place called the function's stack frame (or just a record for simplicity) - for its parameters, and also for all the local variables it declares (including the return variable). The sequence in which the variables are declared is - first the parameters, then the local variables and finally the return variable.  
Consider the following example  
```c++
void bar() {
}

void foo() {
  bar();
}

int main() {
  foo();
}
```
When executing the program, the ``main()`` function is always called first, and the call is recorded and put on top of the stack. The ``main()`` function calls ``foo()``, and this call writes ``foo()`` to the top of the stack. It then calls ``bar()`` and puts it on top of the stack. When the execution of ```bar()`` is complete, its call is removed from the stack. Then ``foo()`` is removed, similarly ``main()`` at the end of its execution.  
The following figure shows the state of the stack after each invocation  
<img src="https://i.imgur.com/IUGxJPF.jpg" width=100% height=100%>  
Consider the following an idea more complex program  
```c++
int plus_one(int x) {
  return x + 1;
}

int plus_two(int x) {
  return plus_one(x + 1);
}

int main() {
  int result = 0;
  result = plus_one(0);
  result = plus_two(result);
  std::cout << result; // prints 3
}	
```
At the beginning of the program, ``main()`` is called first, then a record is made that holds a single local variable ``result``. After its declaration, it is initialized with the value 0, and then ``plus_one(0)`` is called. This creates an entry for ``plus_one()`` that contains the parameter ``x``. The program sets the ```0``` value of the ``x`` parameter and executes the body of the function. The body calculates the value of ``(x+1)`` by taking the value of ``x`` and adding 1 to it, returning 1 as the result. The returned value 1 replaces the original call to ``plus_one(0)``, after which the entry for ``plus_one()`` is deleted from the stack. The value 1 (returned by the function) of the ``result`` variable is then set.  
The following figure illustrates the states of the stack in the course of the above executions.	
<img src="https://i.imgur.com/w7M2vEr.jpg" width=100% height=100%> 
Then proceed to the call to ``plus_two(result)``. Initially, result is set to 1 (from the previous call). An entry for ``plus_two()`` is then created, allocating memory for the ```x`` parameter. This entry is located in the same location as the last entry for the ``plus_one(0)`` call, and this location is reused. After the entry, the ```x``` parameter is initialized with the value 1. The body of ``plus_two()`` is then executed.  
The body of ``plus_two()`` calls ``plus_one(x+1)``. The value of x + 1 = 2 is computed, then an entry is created for ``plus_one()``, allocating space for the parameter ``x``` and setting its value to 2 in the new entry, and then the body of ``plus_one()`` is executed.
<img src="https://i.imgur.com/iKoSa9u.jpg" width=100% height=100%>  
The newly created record for ``plus_one()`` is different from the previous one - each call creates its own one, and the variables declared there are local to itself. 
	
## Static and global variables 
Static variables are variables that do not lose their value (hold it) once they go out of the scope they are declared in. Therefore, static variables retain their previous value and are not re-initialized the next time they are called. For example  
```c++	
void returnSomething() {
	int x = 0;

	std::cout << (x++)<<"\t";

}

int main() {

	for (int i = 0; i < 5; ++i) {
		returnSomething();
	}

	return 0;
}
```
we get the output  
```0 0 0 0 0```  
while if we declare x to be static, i.e. with the declaration ``static int x = 0`` we get the output  
```0 1 2 3 4```  
i.e. its value is preserved between calls to returnSomething().  
We call global variables variables that are not local, i.e. not declared in functions (or any other scope). For example  
```c++
#include<iostream>
	
int b = 5;

int& increment() {
	return (++b);
}

int main() {

	for (int i = 0; i < 5; ++i) {
		std::cout << increment()<<" ";
	}

	return 0;
}			  
```  
outputs ``6 7 8 9 10``.  

## Default parameter values

A parameter with a default value in a function declaration is a parameter that is automatically assigned a value by the compiler if the function call does not provide one. In the event that one is provided - the default value is replaced with the one the function was called with. For example  
```c++
int sum(int x, int y, int z = 0, int w = 0) //assigning default values to z,w as 0
{
    return (x + y + z + w);
}
 

int main()
{
    // Statement 1
    cout << sum(10, 15) << endl;
   
    // Statement 2
    cout << sum(10, 15, 25) << endl;
   
    // Statement 3
    cout << sum(10, 15, 25, 30) << endl;
    return 0;
}
```
and we get the output  
```
25
50
80
```
It is also possible to have multiple functions with the same: ***return type*** and name, but a different set of parameters. The choice of exactly which function to execute happens at compile-time (compile-time polymorphism), and exactly which one is called depends entirely on the parameters passed. For example  

```c++
void printSum(int x, int y) {
	std::cout << x + y << std::endl;
}

void printSum(double x, double y) {

	std::cout << x + y << std::endl;
}
int main()
{
	printSum(2, 3); //
	printSum(20.5, 3.2);

		return 0;
}
```