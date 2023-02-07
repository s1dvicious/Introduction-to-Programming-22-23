Consider the following piece of code  

```c++
//Prints "Hello World!" to the monitor

#include<iostream>
using namespace std;

int main(){

cout<< "Hello World!";

return 0;
}
```
We can think of this code as a set of instructions that we give the computer to execute. Consider each line (in turn):
First line - ```//Prints "Hello World!" to the monitor```. This is a comment - its purpose is entirely to assist those reading the code - ourselves included. Writing comments is considered a good practice when developing larger programs, in the form of a "reminder" or "help" information about some specific functionality (explaining briefly / or an idea more thoroughly what it does, why, etc). The computer doesn't deal with the comments at all - it ignores them entirely.  
The next line is a preprocessor directive (they start with #), instructing the computer to give access to all the functionality contained in the <iostream> library (input output stream), or the standard input and output library. In practice, #include grabs everything it finds in the appropriate directory and puts it in its place.  
  How does the computer know where to start, though? When the program executes, it finds a function called ***main*** and executes any instructions that are specified in it:
  ```c++
int main(){ //C++ programs start by executing the function main

// does something within the function body - explained below

return 0;   //indicates that the function has been executed successfully
}
  ```
  Every C++ program should have such a function so that it knows exactly where to start. A function is effectively a sequence of instructions that are executed by the computer, following the same routine by which they were written. Each function (we'll go into more detail on these later, for now we're taking things as they are) has 4 parts:
  - return type, here integer (or ***int***), of what type the result will be when the function is executed;
  - Name - in our case ***main***;
  - A sheet of parameters (inside at the round brackets), in our case it is empty (blank);
  - Body - surrounded by curly braces { } , and this is where the instructions to be executed are put.
```c++
cout << "Hello World!\n";
```
It is this line that brings "Hello World!" up on the screen. In C++, strings (literals) are surrounded by double ***"*** beaks, i.e. "Hello World!\n" is a sequence of characters. The symbol "\n" indicates a new line transition. The ***cout*** (Character OUTput stream) is a sequence of characters (bytes) that are "poured" from the program and "flowed" (literally) into the screen, more accurately it is called the standard output stream (the iostream library provides access to this stream, which is why we include it), the standard output being the console. The term "output stream" is not limited to our monitor - there are streams that we can use to write to text files, other programs, networks, the dishwasher, i.e. purely as a "means" for a program to communicate with external devices (with information coming out of the program). Along with ***cout***, the ***<<*** operator appears immediately, and we can think of it as a (binary) operator that grabs everything on the right and stuffs it into the left object, i.e. writes over the stream.

 ### Compilation 
  C++ is a compiled language, i.e. in order to execute a program it must first be translated from a form that is easily readable by humans to a form that a machine can understand. It is this translation that is done by the ***compiler***. The code we write is called source code, and what the computer executes is called executable code, object code, or machine code. It is common for program codes (those that are translated) to end with the suffix .cpp (or .h for headers, as these are not processed but used in .cpp's) , and object codes with .obj.  
  <img src="https://hackingcpp.com/cpp/slides/cpp_separate_compilation_03.svg" width=50% height=50%>  
  The compiler reads the code and looks to see if it is grammatically correct - if every word in it has a precisely defined meaning, and also if there is anything incorrect that can be detected before the program executes. 
  
  ## Linking
  A program usually consists of many different parts, which are quite often developed by different people. The different parts must be compiled and the resulting object codes must be linked together to form an executable program. The "device" that does this linking is called a linker. For example, when compiling the above code, ours is executed and creates a "source.obj" file and also an "ostream.obj" one, then the linker links them in and creates a "source.exe".
  Errors signaled by the compiler are called "compile-time errors", errors signaled by the linker are called "link-time errors", and errors that occur during program execution are called "run-time errors". Usually compile-time errors are the easiest to understand and therefore to fix than link-time errors.

## 3. Primitive data types
  
  OK de, the previous program does no more than write something on the screen - it reads nothing, accepts no input from the user. Real programs implement results on input, rather than doing the same thing every time.   
  To read something we need some piece of memory to store it in. We call such pieces objects. An object is just a piece of memory with a type that specifies what amount of information can be stored in its place. An object with a name is called a variable.  
  There are many variables (or as we call them, primitive data types) in C++. However, 4 of them are quite sufficient for writing a well working (at the moment) program. They are:
  - Integer or ***int*** - as their name suggests they hold integers, and they take up 4 bytes (or 32 bits) of memory;
  - Floating point numbers (double or double precision floating point) - these are used for numbers that are an "approximation" of real numbers. Such numbers are, for example, 2.552, 3.14159, etc. - 8 bytes in memory. In addition, analogous to ***double*** - ***float*** has the same meaning (floating point) with the difference that it occupies 4 bytes in memory, and hence a lower degree of accuracy in approximation;
  - Character variables (character) or ***char*** - these are variables that hold exactly one character, literal ones being surrounded by ' '. For example, 'a', 'X', '9', etc., - 1 byte;
  - Boolean or ***bool*** - for logical variables, as their possible values are two - 1 or 0 (true or false) - 1 byte in memory;  

sizeof operator - used to find the size (in bytes) that an object (expression/variable) occupies in memory. For example  
```c++
int n;
std::cout<< sizeof(n) << " "<<sizeof(int) // prints 4 4
         << sizeof(char) ;                // prints 1
``` 
### Modifiers in primitive data types
These are used for built-in data types, modifying the amount of memory they occupy and also constraining the values (positive/negative) that can be assigned to them.  
We know from last time that int-a can contain both positive and negative integers. Similarly for double-a. There are modifiers (another data type) that restrict this condition, i.e. occupy the same memory space, but only allow positive variables. This is done with the reserved word (which is used as a prefix) ***unsigned*** (i.e. no sign). We can also indicate that a variable accepts both positive and negative values by using ***signed*** (int, double,float, char are all signed by definition, so its use is not particularly relevant unless we explicitly want to indicate that we will work with negative values in a declaration).  
Other types of modifiers that can be used are:
- short
- long    
This is what memory modifiers are - short is for smaller variables, while long is for larger ones.
https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121347/ModifiersInC.png  
With these, we have that ``long~int, short int~short`` (i.e. whether we write one or the other doesn't matter). Also when declaring, omitting int by default declares ``short, long, long long ~ short int, long int, long long int`` etc.  
signed/unsigned is not supported by C++ for floating point numbers.

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121347/ModifiersInC.png" width=75% height=75%>   
  
   
  - Declaration - is an expression that tells the compiler about the existence of a variable, providing both its name and its type. The syntax for declaring (and initializing) a variable is  
  ```c++
<type> <name> = (<value>)  
  ```
  For example  
  ```c++
  int N = 50; //N is an integer variable with value 50
  double PI = 3.14159 //PI is a double variable with value 3.14159
  bool flag = 0; //flag is a boolean variable with value 0, i.e. false
  char symbol = 'x'; //symbol is a char variable with value 'x'
  ```
  An important thing about variable names is that they can only contain letters (upper/lower case), numbers and underscores, and they must start with a letter (or underscore). Reserved words (such as int, main, return, etc.) cannot be reused as variable names.  
  Okay, what if we want the user to assign them a value? In other words, is it possible that the value of a variable is not known when the program is executed, but is set later, i.e. at runtime? It is possible, and this is given by 
  Similar to the standard output stream, the standard input stream (Character INput stream) or ***cin*** makes a connection between the program and an external device, the difference being that in this case the information comes from the standard input, which is the keyboard by default. That is, in this case the direction the bytes are moving is from the external device to the program. The syntax is:  
  ```c++
  int N;
  cin >> N; //input from the keyboard is flown into cin and cin flows the bytes into N;
  ```
  That is, the >> operator catches the input stream and pours all the information into N. Importantly, it is type-sensitive, i.e. it expects input of a type corresponding to the type on the right. It completely ignores whitespaces in the console, i.e. it drives along the spans until it gets some data - it reads it until it gets the next whitespace (or newline).  
  We can also combine multiple reads in one use of the standard input, i.e. 
  ```c++
  int num1, num2, num3;
  std::cin >> num1 >> num2 >> num3; //Examplery input: 0 2.3 5; Then num1 = 0, num2 = 2, num3 = 5;
  ```
  
  ## Conversion between data types - safe & unsafe conversions
   C++ also offers implicit (hidden) conversions between data types when necessary. For example
  
  ```c++
  char symbol = 'x';
  int sInt = symbol; //following the ASCII table, 'x' is translated (converted) into an integer and then assignment is performed
  double sDouble = sInt; //the righthand side (sInt) is converted to double, and then the assignment is performed
  
  ```
  on compilation, we get ```x 120 120```, where 120 is the 'x' character in the ASCII table, and this is the simplest and safest way to get the integer value of a character (you may also need to convert directly/explicitly).  
   In this sense - values are always converted to equal ones (or for ***double***) to the best approximation of the value. The following conversions are safe (in the sense that no information is lost, since a "smaller" piece of memory is used to build a "larger" one, i.e. it is not cut):  
  ```
bool to char
bool to int
bool to double
char to int
char to double
int to double
  ```  
  i.e. from variables of smaller size to variables of larger size.  
  
  ```c++
  double d1 = 2.5;
  double d2 = d1 + 2; //Here 2 will be converted to 2.0 and added to 2.5, resulting in 4.5;
  ```
  
  ```c++
  char symbol = 'x';
  int n = 20 + symbol; // converts 'x' to 120 (following the ASCII table) and adds 20 to it
  ```
  
  # Unsafe conversions
  
  By unsafe conversions we mean conversions to a value that is not equal to the original value. For example
  
  ```c++
  int a = 2000;  
  char symbol = a;
  
  std::cout<<symbol; // trying to fit an int into a char - loss of information
  ```
  or
  
  ```c++
  double PI = 3.14159;
  int number = PI; //casts PI into an integer with rounded (to 0) value of 3
  
  std::cout<< number; //prints 3
  ```
  here number is rounded (to the smaller integer) to 3, i.e. we lose the decimal part.  
  Such unsafe roundings occur quite often, generally when we try to convert a larger variable to a smaller one. All of the conversions  
  ```
  double to int
double to char
double to bool
int to char
  int to bool
char to bool
  ```  
  are allowed by the compiler, even though they are unsafe (it still gives an indication of potential information loss).  
  
  ## Operations with primitive data types
There are two types of operators in C++:  
  - Unary (per argument)
  - Binary (on two arguments)  
  
They are characterized by 
  - Priority - in expressions with more than one operator, determine the order in which the operations will be performed;
  - Associativity - for expressions with operators of the same order, similarly define the sequence in which the operations will be performed;
  - Position of the operator with the pair argument - prefixed, infixed and suffixed  
  <img src="https://camo.githubusercontent.com/21f088fc65ef9dd29585506b247898551d077c37e547c8adf5dad6f164b78084/68747470733a2f2f692e737461636b2e696d6775722e636f6d2f75337132452e706e67" width=80% height=80%>  
  # Example 
  
  ```
  Consider the expression a~b~c~d~f. Let the binary operation ~ be:
- left associative. Then the expression takes the form (((a~b)~c)~d)~f)
- right associative. Then the expression takes the form (a~(b~(c~(d~f))))
  ```
 
  ## Arithmetic operators - +, -, *, /, %, ++, - -,
  
  The 5 arithmetic operators provided in C++ are  
   <img src="https://i.imgur.com/TdljFD7.jpg" width=20% height=20%>  
  With each one corresponding to its mathematical meaning. Only % can only be used with int's.  
  
  For example
  ```c++
  int a = 10,
      b = 3;
  
  std::cout << a%b;
  ```
  
  outputs 1 as the result, i.e. 10 is comparable to 1 modulo 3 (or 10 = 1 (mod 3) , which is equivalent to there being n such that 10 = 3*n + 1). Similarly
  
  ```c++
  int a = 10,
      b = 5;
  
  std::cout << a%b;
  ```
  Outputs 0, i.e. 10 is divisible by 5.  
  
  Division also conforms to its mathematical definition, in that if the remainder is not equal to 0 when dividing int's, the number is reduced to the smaller integer. For example  
  
  ```c++
  int a = 10,
      b = 3;
  
  std::cout << a/b;
  ```
  Outputs 3, or that n for which it is true that 10 = 3*n + 1.  
  
 The increment (++) and decrement (--) operators are nothing more than 
  ```c++
  int a = 5;
  a++; 
  //or equivalently
  a = a + 1;
  ```
  and for decrementing
  ```c++
  int a = 5;
  a--;
  //or equivalently
  a = a - 1;
  ```
  
  There is one important feature of these operators, namely that they can be used both as prefix and suffix operators, i.e. they can be used both before and after the variable itself. At first glance this is insignificant, but it makes a huge difference when evaluating expressions - whether it will be used as a prefix or a suffix:   
```c++
int x = 3;
int y = ++x; //the value of x is incremented by one, and then the expression is evaluated
	
std::cout<< y; //prints 4
```
while as a suffix we have  
```c++
int x = 3;
int y = x++; //the expression is first evaluated, and then the value of x is incremented
	
std::cout<< y; //prints 3	
```
  
  
## Compound arithmetic operators - =, +=, -=, /=, *=, %=, &=, |=
Each of these is nothing more than  
  
```c++
a+=b is equivalent to a = a + b
a-=b is equivalent to a = a - b
a/=b is equivalent to a = a / b
a*=b is equivalent to a = a * b
```
essential that they change the value of the variable (i.e. work on it)
  
  ## Comparison operators - ==, <, >, <=, >=, !=  
  Two expressions can be compared using these operators.   
  
 <img src="https://i.imgur.com/9L1bknN.jpg" width=20% height=20%>  
  
  For example, comparing two integers 
  ```c++
  int a = 5,
      b = 10;
  
  bool isGreater = b>a;
  
  std::cout<< isGreater;
  ```
  Outputs ***1***, i.e. 10>5. Similarly,  
  
  ```c++
  int a = 3;
  double	b = 3.5;
  bool res = b > a;
  std::cout << res;
  ```
  Here, to compare a and b - a is cast to double - becomes 3.0, then compared.  
  
  ## Logical operators &&, ||, !
  The ! operator represents the Boolean negation operation by reversing the Boolean variable to which it is applied. I.e., when reversed, false becomes true and vice versa. For example  
```c++
!(5 == 5) // evaluates to false because the expression at its right (5 == 5) is true
!(6 <= 4) // evaluates to true because (6 <= 4) would be false
!true // evaluates to false
!false // evaluates to true
```
As for the && and || operators (they are binary) - they are used when comparing two boolean variables and again return true/false. && corresponds to the boolean AND, while || corresponds to OR.  
<img src="https://i.imgur.com/MrkFGJY.jpg" width=20% height=20%> 
	while with OR we have 
<img src="https://i.imgur.com/5e7ENxn.jpg" width=20% height=20%>   
	
For example  
```c++
( (5 == 5) && (3 > 6) ) // evaluates to false ( true && false )
( (5 == 5) || (3 > 6) ) // evaluates to true ( true || false )
```
	
