Да разгледаме следното парче код  

```c++
//Prints "Hello World!" to the monitor

#include<iostream>
using namespace std;

int main(){

cout<< "Hello World!";

return 0;
}
```

Можем да си мислим за този код като множество инструкции, които даваме на компютъра да изпълни. Да разгледаме всеки един ред (последователно):   
Първия ред - ```//Prints "Hello World!" to the monitor```. Това е коментар - неговото предназначение изцяло е да подпомага тези, които четат кода - самите нас включително. Писането на коментари се счита за добра практика при разработка на по-мащабни програми, под формата на "reminder" или "помощна" информация за някаква конкретна функционалност (обяснява накратко / или една идея по-обстойно какво прави, защо и т.н.). Компютърът изобщо не се занимава с коментарите - игнорира ги изцяло.  
Следващия ред представлява предпроцесорна директива (те започват с #), като тя инструктира компютъра да даде достъп до всичките функционалности, които се съдържат в библиотеката <iostream> (input output stream), или стандартната библиотека за вход и изход. На практика #include хваща всичко, което намери в съответната директория и го слага на своето място.  
  Как знае компютърът откъде да започне обаче? При изпълнение на програмата той намира функция наречена ***main*** и изпълнява всички инструкции, които се указват в нея:  
  ```c++
int main(){ //C++ programs start by executing the function main

// does something within the function body - explained below

return 0;   //indicates that the function has been executed successfully
}
  ```
  Всяка С++ програма трябва да има такава функция, за да знае откъде точно да започне. Функция на е практика последователност от инструкции, които се изпълняват от компютъра, следвайки същата наредба, по която са написани. Всяка функция (по-нататък ще се спрем по-подробно върху тях, засега приемаме нещата както са) има 4 части:
  - return type, тук целочислена (или ***int***), от какъв тип ще е резултатът при изпълнение на функцията;
  - Име - в нашия случай ***main***;
  - Лист от параметри (вътре при кръглите скоби), като при нас той е пуст (празен);
  - Тяло - огражда се с къдрави скобки { } , като именно там се слагат инструкциите, които трябва да се изпълнят.  
 
```c++
cout << "Hello World!\n";
```
Именно този ред изкарва "Hello World!" на екрана. В С++ символните низове (литералните) се ограждат с двойни човки ***"***, т.е. "Hello World!\n" е последователност от символи. Символът "\n" индикира преминаване на нов ред. ***cout*** (Character OUTput stream) e последователност от символи (байтове), които се "изливат" от програмата и "вливат" (буквално) в екрана, като по-точно той се нарича поток за стандартен изход (iostream библиотеката дава достъп до този поток, затова и я включваме), като стандартният изход е именно конзлата. Терминът "поток за изход" не се ограничава до нашия монитор - съществуват потоци, с помощта на които можем да пишем в текстови файлове, в други програми, мрежи, миялна машина, т.е. изцяло като "средство" за комуникация на една програма с външни устройства (като информацията излиза от програмата). Заедно с ***cout*** се появява непосредствено и операторът ***<<***, като за него можем да си мислим като за оператор (бинарен), който хваща всичко отдясно и го пълни в левия обект, т.е. пише върху потока.

 ### Компилация 
  С++ е компилиран език, т.е. за да се изпълни една програма тя трябва първо да се преведе от форма, която се чете лесно от човека, във форма, която машината може да разбере. Именно този превод се осъществава от ***компилатора***. Кодът, който пишем се нарича програмен код (source code), а това, което компюътърът изпълнява - изпълним код (executable code), обектен код (object code) или машинен код (machine code). Обичайно програмните кодове (тези, които се превеждат) завършват със суфикс .cpp (или .h за header-и, като те не се обработват, а използват при .cpp-тата) , а обектните - с .obj.  
  <img src="https://hackingcpp.com/cpp/slides/cpp_separate_compilation_03.svg" width=50% height=50%>  
  Компилаторът чете кода и гледа дали е граматически коректен - ако всяка дума в него има точно дефинирано значение, а също и дали има нещо некоректно, което може да бъде открито преди изпълнение на програмата. 
  
  ## Линкване
  Една програма обичайно се състои от много различни части, които доста често се разработват от различни хора. Различните части трябва да се компилират и получените обектни кодове трябва да се свържат заедно, за да формират една изпълнима програма (executable program). "Устройството", което се занимава с това свързване (linking) се нарича линкер (linker). Например при компилация на горния код се изпълнява нашата и създава "source.obj" файл, а също и "ostream.obj" такъв, след което линкерът ги свързва в и създава "source.exe".
  Грешки, сигнализирани от компилатора се наричат "compile-time errors", а от линкера - "link-time errors", а такива, които се появяват в хода на изпълнение на програмата - "run-time errors". Обикновено грешките при компилация са най-лесни за разбиране и съответно за оправяне от тези при свързване.

## 3. Примитивни типове данни
  
  Добре де, предишната програма не прави повече от това да пише нещо върху екрана - не чете нищо, не приема никакъв вход от потребителя. Истинските програми реализират резултати при подаден вход, вместо да правят едно и също нещо всеки път.   
  За да прочетем нещо ни е необходимо някакво парче в паметта, където да го запазим. Такива парчета наричаме обекти. Обект е точно парче от памет с тип, който указва какво количество информация може да се складира на негово място. Обект с име се нарича променлива.  
  Съществуват множество променливи (или както ги наричаме - примитивни типове данни) при С++. Обаче, 4 от тях са напълно достатъчни за напис на една добре работеща (към момента) програма. Те са:
  - Целочислени (integer) или ***int*** - както и името им подсказва в тях се държат цели числа, като те заемат 4 байта (или 32 бита) в паметта;
  - Числа с плаваща запетая (double или double precision floating point) - те се използват за числа, които представляват "апроксимация" на реалните числа. Такива числа са например 2.552, 3.14159 и т.н. - 8 байта в паметта. В допълнение, аналогично на ***double*** - ***float*** носи същото значение (с плаваща запетая) с разликата, че заема 4 байта в паметта, а оттам идва и по-ниска степен на точност при апроксимация;
  - Символни променливи (character) или ***char*** - това са променливи, които държат точно един символ, като литералните такива биват ограждани с ' '. Например 'a', 'X', '9' и т.н., - 1 байт;
  - Булеви (boolean) или ***bool*** - за логически променливи, както техните възможни стойности са две - 1 или 0 (true или false) - 1 байт в паметта;  

sizeof оператор - използва се за намиране на размера (в байтове), който даден обект (израз/променлива) окупира в паметта. Например  
```c++
int n;
std::cout<< sizeof(n) << " "<<sizeof(int) // prints 4 4
         << sizeof(char) ;                // prints 1
``` 
### Модификатори при примитивните типове данни
Те се ползват за вградените типове данни, като модифицират количеството памет, което те заемат, а също и ограничения по отношение на стойностите (положителни/отрицателни), които могат да им се задават.  
От миналия път знаем, че int-a може да съдържа както положителни, така и отрицателни целочислени числа. Аналогично и при double-a. Съществуват модификатори (друг тип типове данни), които ограничават това условие, т.е. окупират същото място в паметта, но допускат единствено положителни променливи. Това става със запазената дума (която се ползва като префиксна) ***unsigned*** (т.е. няма знак). Също можем и да индикираме, че дадена променлива допуска както положителни, така и отрицателни стойности, като това става с ***signed*** (int, double,float, char по дефиниция са signed, затова ползването й не е от особена релевантност, освен ако изрични при декларация не искаме да укажем, че ще работим и с отрицателни стойности).  
Друг тип модификатори, които могат да се ползват са:
- short
- long  
Като именно това са модификаторите за памет - short е за по-малки променливи, докато long - за по-големи.
https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121347/ModifiersInC.png  
При тях имаме, че ```long~int, short int~short``` (т.е. дали ще пишем едното или другото - няма значение). Също при декларация, изпускайки int по презумпция се декларират ```short, long, long long ~ short int, long int, long long int``` и т.н.  
signed/unsigned не се поддържа от С++ при числата с плаваща запетая.

<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121347/ModifiersInC.png" width=75% height=75%>   
  
   
  - Декларация - представлява израз, който указва на компилатора за съществуването на дадена променлива, като осигурява както името й, така и типа и. Синтаксисът за декларация (и инициализация) на променлива е  
  ```c++
<тип> <име> = (<стойност>)  
  ```
  Например  
  ```c++
  int N = 50;          //N is an integer variable with value 50
  double PI = 3.14159  //PI is a double variable with value 3.14159
  bool flag = 0;       //flag is a boolean variable with value 0, i.e. false
  char symbol = 'x';   //symbol is a char variable with value 'x'
  ```
  Важно при наименованията на променливите е, че те могат да съдържат единствено букви (малки/главни), цифри и долни черти, като обезателно започват с буква (или долна черта). Запазени думи (такива като int, main, return и т.н.) не могат да се преизползват като имена на променливи.  
  Добре, а ако искаме потребителят да им зададе стойност? С други думи, възможно ли е стойността на променлива да не е известна при изпълнение на програмата, а да се задава в последствие, т.е. при изпълнение? Възможно е, като това се дава с помощта на 
  По подобие на потока за стандартен изход, потокът за стандартен вход (Character INput stream) или ***cin*** осъществява връзка между програмата и външно устройство, с разликата, че в този случай информацията идва от стандартния вход, който по подразбиране е клавиатурата. Т.е. в този случай посоката, по която се движат байтовете е от външното устройство към програмата. Синтаксисът е:  
  ```c++
  int N;
  cin >> N; //input from the keyboard is flown into cin and cin flows the bytes into N;
  ```
  Т.е. операторът >> хваща потока за вход и налива всичката информация в N. Важно е, че той е type-sensitive, т.е. очаква вход от тип, съответстващ на типа, който стои отдясно. Той игнорира напълно whitespace-ове в конзолата, т.е. кара наред по спейсовете докато не стигне някакви данни - чете ги, докато не стигне следващия whitespace (или нов ред).  
  Можем да комбинираме и няколко прочитания при едно ползване на стандартния вход, т.е. 
  ```c++
  int num1, num2, num3;
  std::cin >> num1 >> num2 >> num3;   //Examplery input:   0    2.3       5; Then num1 = 0, num2 = 2, num3 = 5;
  ```
  
  ## Преобразуване между типове данни - safe & unsafe conversions
   С++ предлага и скрито (имплицитно) преобразование между различните типове данни, когато това е необходимо. Например
  
  ```c++
  char symbol = 'x';
  int sInt = symbol;        //following the ASCII table, 'x' is translated (converted) into an integer and then assignment is performed
  double sDouble = sInt;    //the righthand side (sInt) is converted to double, and then the assignment is performed
  
  ```
  при компилация получаваме ```x 120 120```, като 120 е символът 'x' в ASCII таблицата, като това е най-простият и безопасен начин за получаване на целочислената стойност на един символ (може и директно/експлицитно да се наложи конвертиране).  
   В този смисъл - стойностите винаги се конвертират до равни такива (или за ***double***) до най-добрата апроксимация на стойността. Следните преобразования са безопасни (в смисъла, че не се губи информация, т.к. от "по-малко" парче памет се изгражда "по-голямо", т.е. не се реже):  
  ```
bool to char
bool to int
bool to double
char to int
char to double
int to double
  ```  
  т.е. от променливи с по-малък размер до променливи с по-голям размер.  
  
  ```c++
  double d1 = 2.5;
  double d2 = d1 + 2;   //Here 2 will be converted to 2.0 and added to 2.5, resulting in 4.5;
  ```
  
  ```c++
  char symbol = 'x';
  int n = 20 + symbol;  // converts 'x' to 120 (following the ASCII table) and adds 20 to it
  ```
  
  # Unsafe conversions
  
  Под небезопасно преобразуване имаме в предвид преобразувания в стойност, която не е равна на първоначалната. Например
  
  ```c++
  int a = 2000;  
  char symbol = a;
  
  std::cout<<symbol;  // trying to fit an int into a char - loss of information
  ```
  или
  
  ```c++
  double PI = 3.14159;
  int number = PI;     //casts PI into an integer with rounded (to 0) value of 3
  
  std::cout<< number;  //prints 3
  ```
  тук number се закръгля (до по-малкото целочислено число) до 3, т.е. губим частта след десетичната запетая.  
  Такива небезопасни закръгляния се получават доста често, в общия случай когато се опитаме да преобразуваме една по-голяма по размер променлива до по-малко такава. Всички от преобразуванията  
  ```
  double to int
double to char
double to bool
int to char
  int to bool
char to bool
  ```  
  се допускат от компилатора, макар и да са небезопасни (той все пак дава и индикация за потенциална загуба на информация).  
  
  ## Операции с примитивни типове данни
В С++ има два типа оператори:  
  - Унарни (на един аргумент)
  - Бинарни (на два аргумента)  
  
Те се характеризират с 
  - Приоритет - при изрази с повече от един на брой оператора, определят последователността, в която ще бъдат извършени операциите;
  - Асоциативност - при изрази с оператори от еднакъв порядък, аналогично дефинират последователността, в която ще бъдат извършени операциите;
  - Позиция на оператора спярмо аргумента - префиксен, инфиксен и суфиксен  
  <img src="https://camo.githubusercontent.com/21f088fc65ef9dd29585506b247898551d077c37e547c8adf5dad6f164b78084/68747470733a2f2f692e737461636b2e696d6775722e636f6d2f75337132452e706e67" width=80% height=80%>  
  # Пример 
  
  ```
  Разглеждаме израза a~b~c~d~f. Нека бинарната операция ~ е:
- ляво асоциативна. Тогава израза приема вида (((a~b)~c)~d)~f)
- дясно асоциативна. Тогава израза приема вида (a~(b~(c~(d~f))))
  ```
 
  ## Аритметични оператори - +, -, *, /, %, ++, - -,
  
  5те аритметични оператора, които се предоставят в С++ са  
   <img src="https://i.imgur.com/TdljFD7.jpg" width=20% height=20%>  
  Като всяка една от тях съответства на математическото си значение. Единствено % може да се използва само при int-ове.  
  
  Например
  ```c++
  int a = 10,
      b = 3;
  
  std::cout << a%b;
  ```
  
  изкарва като резултат 1, т.к. 10 е сравнимо с 1 по модул 3 (или 10 = 1 (mod 3) , което е еквивалентно на това, че съществува n, такова че 10 = 3*n + 1). Аналогично
  
  ```c++
  int a = 10,
      b = 5;
  
  std::cout << a%b;
  ```
  Изкарва 0, т.к. 10 се дели на 5.  
  
  Делението също съответства на математическата си дефиниция, като ако при деление на int-ове остатъкът не е равен на 0, то числото се свежда до по-малкото цяло такова. Например  
  
  ```c++
  int a = 10,
      b = 3;
  
  std::cout << a/b;
  ```
  Изкарва 3, или онова n, за което е вярно, че 10 = 3*n + 1.  
  
 Операторите за инкрементиране (++) и декрементиране (--) не са нищо повече от 
  ```c++
  int a = 5;
  a++; 
  //or equivalently
  a = a + 1;
  ```
  и за декрементиране
  ```c++
  int a = 5;
  a--;
  //or equivalently
  a = a - 1;
  ```
  
  Има една важна особеност при тези оператори, а именно, че те могат да се използват както като префиксни, така и като суфиксни, т.е. те могат да се използват както преди, така и след самата променлива. На пръв поглед това е незначително, но има огромно значение при пресмятане на изрази - дали ще се използва като префикс или суфикс:   
```c++
int x = 3;
int y = ++x;    //the value of x is incremented by one, and then the expression is evaluated
	
std::cout<< y;  //prints 4
```
докато като суфикс имаме  
```c++
int x = 3;
int y = x++;    //the expression is first evaluated, and then the value of x is incremented
	
std::cout<< y;  //prints 3	
```
  
  
## Съставни аритметични оператори - =, +=, -=, /=, *=, %=, &=, |=
Всеки един от тях не е нищо повече от  
  
```c++
a+=b is equivalent to a = a + b
a-=b is equivalent to a = a - b
a/=b is equivalent to a = a / b
a*=b is equivalent to a = a * b
```
като от съществено значение е, че те променят стойността на променливата (т.е. работят върху нея)
  
  ## Оператори за сравнение - ==, <, >, <=, >=, !=  
  Два израза могат да се сравняват, като се използват тези оператори.   
  
 <img src="https://i.imgur.com/9L1bknN.jpg" width=20% height=20%>  
  
  Например, сравнявайки две цели числа 
  ```c++
  int a = 5,
      b = 10;
  
  bool isGreater = b>a;
  
  std::cout<< isGreater;
  ```
  Изкарва ***1***, т.к. 10>5. Аналогично,  
  
  ```c++
  int a = 3;
  double	b = 3.5;
  bool res = b > a;
  std::cout << res;
  ```
  Тук, за да се сравнят а и b - а се каства в double - става 3.0, след което се сравняват.  
  
  ## Логически оператори  &&, ||, !
  Операторът ! представлява булевата операция отрицание, като обръща булевата променлива, върху която е приложена. Т.е. при обръщане false става true и обратно. Например  
```c++
!(5 == 5)   // evaluates to false because the expression at its right (5 == 5) is true
!(6 <= 4)   // evaluates to true because (6 <= 4) would be false
!true       // evaluates to false
!false      // evaluates to true
```
Колкото до операторите && и || (те са бинарни) - те се използват при сравняване на две булеви променливи и отново връщат true/false. && отговаря на булевото И, докато || - на ИЛИ.  
<img src="https://i.imgur.com/MrkFGJY.jpg" width=20% height=20%> 
	докато при ИЛИ имаме 
<img src="https://i.imgur.com/5e7ENxn.jpg" width=20% height=20%>   
	
Например  
```c++
( (5 == 5) && (3 > 6) )  // evaluates to false ( true && false )
( (5 == 5) || (3 > 6) )  // evaluates to true ( true || false )
```
	
