## Iteration operators

### While loop
This is the simplest loop and its syntax is  

```c++
while(<condition>){
//statement
}
```
That is, the loop body will execute while <condition> is true, or as a flow-chart  

<img src="https://camo.githubusercontent.com/221385e64bc1420119e9fdee2aab9d59251fdbe0edd18a14e82e93fc5e0f8840/68747470733a2f2f692e6962622e636f2f3747674b52376b2f556e7469746c65642d4469616772616d2d312e706e67" width=20% height=20%>   

### Example
```c++
 int n;
 std::cin>>n;
 
  while(n>0){
  std::cout<<n<<" ";
  --n;
  }
```
### Example with Euclid's algorithm  

```c++
	n = 16, k = 24
	<24, 16> 24 % 16 = 8
	<16, 8> 16 % 8 = 0
	<8, 0> 
	=> gcd(16,24) = 8
```  
or as code

```c++

	int n, k;
	std::cin >> n >> k;
	// <n,k> 

	if (k > n) { //swap
		int temp = k;
		k = n;
		n = temp;
	}

	// n > k -> n = k*r + q
	while (k != 0) {
		int mod = n % k;
		n = k;
		k = mod;
	}

	std::cout << n;
```  

## Do-While loop
Analogous to the While loop with the only exception that the body is executed first and then checked, i.e. this ensures at least one body implementation  

```c++
do{
    //statement
}while(<condition>)  
```
  or as flow-chart  
  
 <img src="https://i0.wp.com/technobyte.org/wp-content/uploads/2019/08/do-while-loop-flowchart-in-C-explanation-simple-examples.png?ssl=1" width=40% height=40%>   
  
  
## For loop
  
```c++
for(initialization; condition; increase){
  //code to be executed
} 
```
As with while, the for loop repeats //statement until condition is true. In addition, the for loop provides specific locations that contain initialization and increment expressions that are executed before and after each iteration, respectively. It works as follows  
  1. Initialization is executed. Normally, a counter is defined here and assigned an initial value. This is executed only once, at the beginning of the loop;
  1. The condition is checked. If condition is true, the loop body is executed. Otherwise, the body is not executed and the loop is exited;
  1. The loop body is executed - as usual there may be a single expression, or a block of commands, enclosed by {};
  1. Execute increase and return at step 2;
 
For example  
```c++
for(int n=10; n>0; --n){
  std::cout<<n<<<", ";
} 
```

## Jump statements
These expressions allow you to change the flow of a program:  
  - break - exits/terminates the loop, even if condition is true (on loop);  
  - continue - forces skipping the subsequent part of the loop body, moving to the next iteration;
  - goto - offers to go to a completely different part of the program, the part is specified with label. This jump ignores the entire natural flow on which the program is built. Therefore, it is (advised not to) be used with great care. For example,  
  
```c++
int n;
mylabel:     
		
std::cin>> n;		
if(n == 3) goto mylabel; //jumps to mylabel if the value of n is equal to 3
		
std::cout<<n;

```
