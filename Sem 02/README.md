<h2 id="">1. Const изрази</h2>  

Програмите на практика използват множество константи. Например, за една програма, извършваща геометрични пресмятания би ни било необходимо числото pi = 3.14159 (апроксимация до 5тото число след плаващата запетая). В тази програма ние не бихме искали да позволяваме промяна на този израз (константен), т.к. в последствие може да се промени значението му. C++ въвежда понятието за символични константи, т.е. обект с име, на когото не може да се присвояват нови стойности след инициализация. Например  
```c++
const double pi = 3.14159; 
double radius = 5;
pi = 7;                     //error:assignment to const
int per = 2*pi*radius;      //ok, we just read pi, we don't try to change it
```
 Такива константи са полезни за четимост на кода - вместо да се въвеждат магически константи (т.е. неочевидни литерали) те се връзват за константни изрази и тяхната стойност се свързва с името на променливата. 

## 2. Условни конструкции

<h3 id="">if - else</h3>
Това е най-простата конструкция, която можем да ползваме и нейната семантика е  

```c++
if(<condition>)
{
		//изпълнява се, ако условието е истина. 
}
else //не е задължителен компонент
{
		//изпълнява се, ако условието е лъжа. 
}
```

като flowchart това графично може и да се изобрази като  
<img src="https://codeforwin.org/wp-content/uploads/2017/08/if-else-statement-flow-chart.png" width=50% height=50%>   

<h3 id="">if - else if -else</h3>
Възниква и else if(<condition>) израза, който е "вързан" за if израз :  
	
```c++
if(<condition1>)
{
	//изпълнява се, ако <condition1> е истина. 
}
else if(<condition2>)
{
	//изпълнява се, ако <condition1> е лъжа и <condition2> е истина. . 
}
.
.
.
else if(<conditionK>)
{
		//изпълнява се, ако <condition1>..<conditionK-1> са лъжа и <conditionК> е истина. . 
}
else //не е задължителен компонент
{
		//изпълнява се, ако всички горни условия са лъжа. 
}
```
и отново като flowchart  
	
<img src="https://codeforwin.org/wp-content/uploads/2017/08/ladder-if...else_...if-statement-flow-chart.png" width=35% height=35%>   
	
<h2 id="">Switch statement</h2>
	
Използва се за изпълняване на парче код, като изборът се извършва измежду множество алтернативи.
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
break индикира да се терминира "цикъла" - използването му не е задължително, но ако липсва - директно нахлува в блоковете, съответстващи на следващите case-ове (т.е. без да прави проверка) и ги изпълнява, докато не стигне до break  
<img src="https://cdn.programiz.com/sites/tutorial2program/files/flowchart-switch-statement.jpg" width=35% height=35%>     

<h3 id="">Тернарен оператор</h3>
Тернарния оператор (или shorthand if-else) е израз, който в общи линии наследява функционалността на if-else-а, неговата семантика е
	
```c++
<условие> ? <израз1> : <израз2>
```

Ако условието е истина, се връща оценката на израз1.
Ако е лъжа, то се връща оценката на израз2.
