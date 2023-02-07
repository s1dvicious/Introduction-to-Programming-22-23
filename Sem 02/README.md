<h2 id="">1. Const expressions</h2>  

Programs actually use multiple constants. For example, for a program performing geometric calculations we would need the number pi = 3.14159 (approximation to the 5th floating point number). In this program, we would not want to allow this expression (constant) to change, since its meaning might change later. C++ introduces the concept of symbolic constants, i.e. an object with a name to which no new values can be assigned after initialization. For example  
```c++
double const pi = 3.14159; 
double radius = 5;
pi = 7; //error:assignment to const
int per = 2*pi*radius; //ok, we just read pi, we don't try to change it
```
 Such constants are useful for code readability - instead of introducing magic constants (i.e. non-obvious literals) they are bound to constant expressions and their value is bound to the variable name. 

## 2. Conditional statements

<h3 id="">if - else</h3>
This is the simplest statement we can use and its semantics is  

```c++
if(<condition>)
{
		//executes if the condition is true. 
}
else //not a required component
{
		//executes if the condition is false. 
}
```

as a flowchart this can graphically be displayed as  
<img src="https://codeforwin.org/wp-content/uploads/2017/08/if-else-statement-flow-chart.png" width=50% height=50%>   

<h3 id="">if - else if -else</h3>
The else if(<condition>) expression also occurs, which is "bound" for the if expression :  
	
```c++
if(<condition1>)
{
	//executes if <condition1> is true. 
}
else if(<condition2>)
{
	//executes if <condition1> is false and <condition2> is true. . 
}
.
.
.
else if(<conditionK>)
{
		//executes if <condition1>..<conditionK-1> are false and <conditionK> is true. . 
}
else //not a required component
{
		//executes if all of the above conditions are false. 
}
```
and again as flowchart  
	
<img src="https://codeforwin.org/wp-content/uploads/2017/08/ladder-if...else_...if-statement-flow-chart.png" width=35% height=35%>   
	
<h2 id="">Switch statement</h2>
	
It is used to execute a piece of code, choosing from multiple alternatives.
```c++	
switch(<expression>)
{
	case const-expression-1:
	//code block to const-expression-1.. 
	break; //optional - if we
	case const-expression-2:
	//code block to const-expression-2.. 
	break; //optional
	...
	case const-expression-n: 
	//code block to const-expression-n.. 
	break; //optional

	default:
	//code block to the default case
	break; //optional.
}
```
break indicates to terminate the "loop" - its use is optional, but if it is missing - it directly invades the blocks corresponding to the next case (i.e. without checking) and executes them until it reaches break  
<img src="https://cdn.programiz.com/sites/tutorial2program/files/flowchart-switch-statement.jpg" width=35% height=35%>     

<h3 id="">Ternary operator</h3>
The ternary operator (or shorthand if-else) is an expression that basically inherits the functionality of if-else, its semantics is
	
```c++
<condition> ? <expression1> : <expression2>
```

If the condition is true, the evaluation of expression1 is returned.
If false, the evaluation of expression2 is returned.
