/*Instructions for C++ programming language
(Udacity course for programmers)*/
//C example:
    #include <stdio.h>

    int main() 
    {
        int intero;
        float virgolaMobile;
        char carattere;

        printf("Inserisci un intero, un numero a virgola mobile e un carattere: ");
        scanf("%d %f %c", &intero, &virgolaMobile, &carattere);

        printf("Hai inserito: %d, %.2f, %c\n", intero, virgolaMobile, carattere);

        return 0;
    }

//Size of a variable type
    sizeof(variable type) //(ie: sizeof(int);)
    sizeof(array)/sizeof(array[0])

//Constants
    const int x=5; //Crea una variabile che non può cambiare valore nel corso del programma;
    enum type_neme{
        value1, value2, value3, ...
    } //Crea un nuovo tipo di variabile che può assumere determinati valori costanti predefiniti;

//Output format
    #include <iomanip> // \n-newline e \t-tab
    std::cout<<"\nThe text without any formating\n";
    std::cout<<"Ints"<<"Floats"<<"Doubles"<< "\n";
    std::cout<<"\nThe text with setw(15)\n";
    std::cout<<"Ints"<<std::setw(15)<<"Floats"<<std::setw(15)<<"Doubles"<< "\n";
    std::cout<<"\n\nThe text with tabs\n";
    std::cout<<"Ints\t"<<"Floats\t"<<"Doubles"<< "\n";
//std::setw(15) permette di regolare la distanza di formattazione

//File IO
    #include <fstream>
    std::ofstream f("nome_file.txt", std::ios::app) //crea un file sul quale è possibile scrivere (output dal programma inseriamo <<)
    std::ifstream f("nome_file.txt") //legge il file nome_file.txt, input perche da fuori portiamo informazioni al programma
    string line;
    while(getline(f,line))
    {
        std::cout<<line<<std::endl;
    }
    f.colse() //chiude il file dopo che tutto ciò che conteneva è stato letto e salvato in line con il ciclo while

//Namespace
//If there is name conflit for more variables we can define differente namespace for the same x
//es:
    #include <iostream>
    using namespace std;
    //define outside the main
    namespace first{
        int x=1;
    }

    namespace second{
        int x=2;
    }

    int main(){
        int x=0;
        cout<<x<<endl; //output is '0'
        cout<<first::x<<endl; //output is '1'
        cout<<second::x<<endl; //output is '2'
        return 0;
    }

//Typedef alias
//Before main, we can define an alias for a data type that is long to rewrite more times.
//es:
    #include <iostream>
    #include <vector>

    //typedef std::vector<std::pair<std::string,int>> pairlinst_t;
    typedef std::string text_t;

    int main(){
        //pairlist_t pairlist;
        text_t Nome= "Bro"; //It is equal to-> std::string Nome="Bro";
        return 0;
    }

/*Header Files
We can include additional libraries in C++, but also our own libraries-> Header files ".hpp"
Esempio:*/
    //main.hpp->"How" the program does a task goes in this file
    #include <iostream>
    using namespace std;
    //main.cpp->"What" the program does goes in this file
    #include "main.hpp" //No use the angle brackets for the header file
    int main()
    {
        cout<<"Hello, I use header files!";
        return 0;
    }

//Type conversion
/*Conversion a value of one data type to another
-implicit=automatic
-explicit=precede value with new data type (int)
*/
//implicit:
    int x = 3.14; //output is 3, because impliciting it converts 3.14 in int
//explicit:
    double x = (int) 3.14;

//User Input
    std::cout //for writing to the console
    std::cin //for reading from the console
    std::cin.ignore() //permette di saltare un assegnazione di comando
//Se lavoro da terminale e voglio dare gli input direttamente da un file: 
    g++ -o main.out main.cpp
    ./main.out < input.txt //or use: stdin=open("input.txt", "r") give bash error
    std::getline(std::cin,variableName) //method to enter strings
//std::getline("file",line) //esempio di utilizzo di getline

//String inputs
    #include <sstream> //Stringsteam library
//It is possible to convert a string variable to a float variable!!
    std::string stringVariable="";
    float numericVariable=0;
    std::stringstream(stringVariable)>>numericVariable
//Si possono così fare operazioni con la variabile float appena convertita.
/*
Anche altre tipologie di variabile non solo float. 
esempio: int funziona ma se ho delle stringhe con la virgola ovviamente la variabile int è intera e tralascia la parte decimale.
*/

//Structure of a C++ program
    main.cpp //Put your code here
    main.hpp //The Header file for main.cpp (include the library and using namespace std)
    mainFunctions.cpp //Functions can go here if you like
    input.txt //This file can be used to input user responses

/*
Compiling 
Just in time compiling (Python, JavaScript)
*/

/*
Terminale Linux
Unix folder and file names work best if there are no spaces in the name
*/



























//Operator
//We can operate with the introduced variables and constants by using operators
//Assignment operator
    =
//Arithmetic operators
    +,-,*,/,% //(modulo)
//Compound assignment operators
    y+=x -> y=y+x
    y-=x -> y=y-x
    y/=x -> y=y/x
    y*=x -> y=y*x
    %=
    >>=
    <<=
    &=
    ^=
    |=
//Increment and decrement 
    ++ //Increase operator-> increase by one the valued stored in a variable +=1
    -- //Decrease operator-> reduce by one the values stored in a variable -=1
    //NB x++ != ++x in alcuni casi, mentre in altri non c'è differenza.
    //esempio_1: nel ciclo for per i NON c'è differenza
    /*esempio_2:
    Prefix:                        Postfix:
    increment the value of x, then   creat a copy of the variable
    return the reference to the x.   and increments the value of x.
                                     Then it returns a copy from BEFORE the increment!*/ 
        x=3                         | x=3
        y=++x                       | y=x++
                                    |
        x contains 4, y contains 4  | x contains 4, y contains 3
//Relation and comparison operators
    == //Equal to
    != //Not equal to
    < //Less than
    > //Greater than
    <= //Less than or equal to
    >= //Greater than or equal to
    //Logical operators
    ! //Boolean NOT
    && //Boolean AND
    || //Boolean OR
    //esempio: 
        !true = false

//Conditional ternary operator
//Replace to an if/else statement
    ?
    condition ? result1 : result2
    If condition is true, the entire expression evaluates to result1, and otherwise to result2
//es:
    grade>=60 ? cout<<"You pass!" : cout<<"You fail!";
    cout<<(grade>=60 ? cout<<"You pass!" : cout<<"You fail!")<<endl; //si può anche scrivere direttamente nel output
//Comma operator
    ,
//It's used to separate two or more expressions thsat are included where only one expression is expected
    a=(b=3,b+2)
    a=5 while b=3
/*
From greatest to smallest priority, C++ operators are evaluated in the following order:
    1	Scope	::	//scope qualifier	Left-to-right
    2	Postfix (unary)	
        ++ --	//postfix increment/decrement Left-to-right
        ()	//functional forms Left-to-right
        [] subscript Left-to-right
        . -> //member access Left-to-right
    3	Prefix (unary)	
        ++ -- //prefix increment / decrement Right-to-left
        ~ !	//bitwise NOT / logical NOT Right-to-left
        + -	//unary prefix Right-to-left
        & *	//reference / dereference Right-to-left
        new delete	//allocation / deallocation Right-to-left
        sizeof	//parameter pack Right-to-left
        (type)	//C-style type-casting Right-to-left
    4	Pointer-to-member .* ->* //access pointer Left-to-right
    5	Arithmetic: scaling	* / % //multiply, divide, modulo	Left-to-right
    6	Arithmetic: addition + - //addition, subtraction	Left-to-right
    7	Bitwise shift << >>	//shift left, shift right	Left-to-right
    8	Relational < > <= >=	//comparison operators	Left-to-right
    9	Equality == !=	//equality / inequality	Left-to-right
    10	And	&	//bitwise AND	Left-to-right
    11	Exclusive or ^ //bitwise XOR	Left-to-right
    12	Inclusive or | //bitwise OR	Left-to-right
    13	Conjunction	&& //logical AND	Left-to-right
    14	Disjunction	|| //logical OR	Left-to-right
    15	Assignment-level expressions	
        = *= /= %= += -= >>= <<= &= ^= |=	//assignment / compound assignment	Right-to-left
        ?:	//conditional operator Right-to-left
    16	Sequencing	,	//comma separator	Left-to-right*/
//Useful math related functions
    #include <iostream>
        std::max(x,y);
        std::min(x,y);
    #include <cmath>
        std::pow(base,exponent) //is equal to base^exponent
        sqrt(x);
        abs(x);
        round(x);
        ceil(x);
        floor(x);
        ... //read the site of the library
        M_PI //è pi greco
    #include <iomanip>
        std::setprecision(2) //put the precision of teh following variable, bank es put two zero after the dop for the cents
        std::fixed
//Variable types
Tipi di dati primitivi:
Intero:
    int: Tipo di dati intero.
    short: Tipo di dati intero breve.
    long: Tipo di dati intero lungo.
    long long: Tipo di dati intero lungo lungo.
Carattere:
    char: Tipo di dati carattere. //NB Non utilizzare "" come per le stringhe ma ''
Virgola mobile:
    float: Tipo di dati virgola mobile a precisione singola.
    double: Tipo di dati virgola mobile a precisione doppia.
    long double: Tipo di dati virgola mobile a precisione estesa.
Booleano:
    bool: Tipo di dati booleano.

Tipi di dati composti:
Array: int array[5].
Stringa: std::string.
Struttura: struct - Definizione di un nuovo tipo di dati con membri diversi.
Unione: union - Tipo di dati che può contenere un solo membro alla volta.

Puntatori:
int*: Puntatore a un intero.
char*: Puntatore a un carattere.
void*: Puntatore a dati di tipo sconosciuto.

Tipi di dati enumerativi:
enum: Definisce un tipo di dati enumerativo.

Tipi di dati definiti dall'utente:
class: Definisce una classe.
struct: Definisce una struttura.
union: Definisce un'unione.
enum class: Definisce un tipo di dati enumerativo con ambito specifico.

Tipi di dati standard:
std::string: Stringa di caratteri di lunghezza variabile.
std::vector: Array dinamico.
std::map, std::set: Strutture dati associative.

Tipi di dati specifici per la libreria standard:
std::ifstream, std::ofstream: Stream di input/output per operazioni di file.

Tipi di dati booleani:
true e false: Valori booleani.

//Questi sono solo alcuni esempi di tipi di dati in C++. La lingua offre molte altre opzioni e possibilità di definire tipi di dati personalizzati attraverso classi e strutture.
//In byte di memoria:
int: Generalmente 4 byte.
short: Generalmente 2 byte.
long: Generalmente 4 byte.
long long: Generalmente 8 byte.

char: Generalmente 1 byte.

float: Generalmente 4 byte.
double: Generalmente 8 byte.
long double: La dimensione può variare, spesso è di 10 o 12 byte.

bool: Solitamente 1 byte, ma potrebbe variare.

int*, char*: Generalmente 4 byte su sistemi a 32 bit e 8 byte su sistemi a 64 bit.
void*: Dimensione dipende dall'architettura, spesso 4 byte su sistemi a 32 bit e 8 byte su sistemi a 64 bit.

std::string: La dimensione può variare, ma di solito è un piccolo oggetto che contiene un puntatore e una dimensione.
std::vector, std::map, std::set: La dimensione dipende dalla dimensione e dal tipo degli elementi contenuti.

std::ifstream, std::ofstream: La dimensione può variare, ma di solito sono oggetti piuttosto complessi che contengono buffer e altre informazioni.
//Ricorda che queste dimensioni sono approssimative e possono variare. Puoi utilizzare l'operatore sizeof.
//Control Flow
/*
if-else statements and else if
for loops
while loops
switch statements
*/
//If else and else if easy
//switch
    switch(expression) //NB expression is also a single variable (only its name), and in the folllowing cases there are the values of the variable condsidered
    {
        case constant-expression : statements;
                                   break; //(this is optional) Without break command the programme run all the case under the char insert by the user
        case constant-expression : statements;
                                   break; //(this is optional);
        ...

        default : //optional
            statements;
    }

//For
    for ( declaration : range ) statement;
    for (initialization; condition; increase) statement; //Ricordarsi i punti e virgola all'interno del for()

    #include <cstddef>
    for(size_t i=0; i<5; i++)
    //"size_t" può variare a seconda del sistema operativo e dell'architettura della CPU.
    /*Solitamente è definito come un tipo onterno senza segno della dimensione del maggior tipo di dato intero senza segno supportato dal compilatore per una data piattaforma.
    Ad esempio su sitemi a 32 bit, sarà generalmente di 4 byte, mentre su sitemi a 64 bit sarà di 8 byte.*/
    //E' utilizzato in contesti in cui è necessario rappresentare la dimensione di un oggetto o l'indice di un array.
    //Nei cicli for appunto

//while loop
    while(condition){statements;}
//if the condition is true, the statements within the curly brackets are executed. if the condition is false, the statements are not executed
//Fino a quando la condizione è vera si mantiene attivo il loop!
//esempio:
    #include <iostream>
    int main()
    {
        int entry=0;
        //with this while loop the condition is true
        //so the statements are executed
        while(entry<=5)
        {
            std::cout<<"incrementing entry= "<<entry<<"\n";
            entry++;
        }
        //with this while loop the condition is false
        //so the statements are not executed
        while(entry<5)
        {
            std::cout<<"decrementing entry="<<entry<<"\n";
            entry--;
        }
        return 0;
    }
//do while
    do
    {
        //statements;
    } while (/* condition */);
//la differenza con il while è che qua almeno una volta lo statement viene eseguito anche se la condizione non è verificata
//esempio:
    int otherCount = 6; 
    //This do..while loop will execute once. Even though
    //otherCount > 5
    do
    {
        std::cout<<"othercount = "<<otherCount<<"\n";
        otherCount++;
    }
    while(otherCount < 5);

//Random number generator
    #include <time.h> //added for the number generator seed
    #include <cstdlib> //added to use the rand() function
    
    srand(time(NULL)); //set the seed for the random number generator
    int x=rand() %100 + 1; //generate the random number da 1 a 100
                     //si assegna alla variabile x la funzione rand()


//Infinite loop
    for( ; ;) { std::cout<<"This for loop will run forever\n"; }
    while(1) { std::cout<<"This while loop will run forever\n"; }

//Exiting Loops
    break; //end the loop and begin executing the first statement that comes AFTER the end of the loop
    continue; //force the next iteration to be executed
//esempio:
    #include<iostream>
    
    int main()
    {
        int a = 0;
        while(a < 5)
        {
            std::cout<<"a = "<<a<<"\n";       
            a++;
            if(a == 3)
                break;
        }
        std::cout<<"The first statement after the first while loop\n\n";
        
        
        while(a < 15)
        {
            a++;
            if(a == 10)
            {
                std::cout<<"\tWhen a=10, go back to the top of the loop";
                std::cout<<"\n\tThis means a=10 is skipped.\n";
                continue;
            }
            std::cout<<"After continue a = "<<a<<"\n";           
        }
        return 0;
    }





















































//Pass to value and to reference
//In the functions we must pass the parameters by references if we want modify the value of the parameter in the main function.
    &a
    
//Pointers
/*Are the variables that contains the addresses of the other standard types variables, that can be accessed in C++. 
They can be used to manipulate easier and directly the memory, with high level of flexibility and control.
In the following example we can see:*/
//variable called 'a' -> have a location in the memory identified by address (shape)
//54 is the value stored in the location reserved to the variable called 'a'(content)
    int a=54;
    int* b; //pointer by int
    b=&a; //assign pointer to variable a

    int a;
    std::cout<<&a<<std::endl; //print directly the LOCATION of 'a'
//output:
&a=0x7fff7c43af24 //esadecimale
Decimali | Binari  | Esadecimali
--------------------------------
   0      |   0     |      0
   1      |   1     |      1
   2      |  10     |      2
   3      |  11     |      3
   4      | 100     |      4
   5      | 101     |      5
   6      | 110     |      6
   7      | 111     |      7
   8      |1000     |      8
   9      |1001     |      9
  10      |1010     |      A
  11      |1011     |      B
  12      |1100     |      C
  13      |1101     |      D
  14      |1110     |      E
  15      |1111     |      F
Per rappresentare i numeri esadecimali in C++, si antepone "0x" al numero. Ad esempio, 15 in esadecimale è rappresentato come 0xF.
//If I know the adress before (dangerous!)
    int* mioPuntatore;
    //Assegnazione dell'indirizzo specifico al puntatore
    mioPuntatore = reinterpret_cast<int*>(0x7fff7c43af24);
/*
Dereferencing Pointers
But what if we have a pointer and want to access the value stored in that address? 
That process is called dereferencing, and it is indicated by adding the operator */ * /* before the variable's name. 
This same operator should be used to declare a variable that is meant to store a pointer.
*/
    int a=54;
    int* pointerToA=&a;
    *pointerToA // è come lavorare con a

    std::cout<<*pointerToA<<std::endl; 
    std::cout<<a<<std::endl; //uguale al comando nella riga precedente
 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
|int a;     | se lavoro solo con la variabile: a   &a | //NB basta definire solo una delle due non serve definirli tutti e due
|int* p=&a; | se lavoro solo con il puntatore: *p  p  | //Nel caso del puntatore si deve definire anche la variabile prima
 - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Null pointers
    int *pointer = nullptr //come se fosse nessuna assegnazione
//Array
    variabletype name[]={1,2,3,...,elements};
    variabletype name[N]; //where N is the dimension of the array
//NB: array dimensions must be known at compile time!

//MultiDimensional Arrays
    variabletype name[N][M] //N*M array-> N righe M colonne
//esempio:
    #include<iostream>
    int main()
    {
        int array2Dim[2][3] = {0,1,2,3,4,5};
        for(int i=0; i<2;i++)
        {
            for(int j=0;j<3;j++)
                std::cout<<"array2Dim["<<i<<"]["<<j<<"] = " << array2Dim[i][j]<<"\t";

            std::cout<<std::endl;
        }
        return 0;
    }





//Functions
//DECLARATION
    returnVariableType functionName(parameter1, parameter2,..., parameterN); //This is the statement of how the function is to be called 
                                                                             //(Note the '; semi-colon' at the end of the statement.)
                                                                             //Usually before main()                                                                            
//DEFINITION
    returnVariableType functionName(parameter1, parameter2,..., parameterN) //This is the statement(s) of the task the function performs when called
    {                                                                       //Usually after main()
        statement(s); 
        return VariableType;
    }
/*
NB: DECLARATION and DEFINITION put into the header file usually, to make main program look cleaner
The function declaration can be omitted in the header file. As long as the function is defined before it is used, the declaration is optional.
It is often considered good practice to list the declarations at the top of the header file.
*/
//CALLING
    int main()
    {
        ...
        functionName(parameter1,parameter2,...,parameterN); //Functions are called using their function name with any parameters specified in the declaration definition
        ...
    }
/*
C++ functions can:
-Accept parameters, but they are not required;
-Return values, but a return value is not required;
-can modify parameters, if given explicit direction to do.
*/

//Functions No Return, No Parameters
    void function()
    {
        statement(s); //This function accepts no parameters and returns no value. When it is called in a program, it will execute the statement.
    }

//Functions with Return Values
//Functions with return values require the declaration and definition state the variable type of the return.
    returnVariableType functionName(parameter1, parameter2, ..., parameterN)
    {
         returnVariableType y; 
         statement(s);
         return y;
    }   
//example:
    int calculateSum(int m1, int m2)        /*or in a shorter form*/    int calculateSum(int m1, int m2)    
    {                                                                   {
         int sum;                                                           return m1 + m2;                                 
         sum = m1 + m2;                                                 }
         return sum;
    }


//Function Altering Parameters
/*Changes to a variable that are made in a function will not effect the variable in the main part of the program. 
(Like we can see in the func_operations.cpp/ in function insert()!)

There are two methods to rectify this situation:

-Return the altered variable;                             -Pass the variable as a reference.*/
 #include <iostream>                                      #include <iostream>
 int increment(int input);                                void increment(int &input); //Note the addition of '&'
 int main(){                                              int main(){
    int a = 34;                                              int a = 34;
    std::cout<<"Before the function call a = "<<a<<"\n";     std::cout<<"Before the function call a = "<<a<<"\n";
    a=increment(a);                                          increment(a);
    std::cout<<"After the function call a = "<<a<<"\n";      std::cout<<"After the function call a = "<<a<<"\n";
    return 0;                                                return 0;
 }                                                        }                                                                                                                   
                                                                                                                    
 int increment(int input){                                void increment(int &input){ //Note the addition of '&'
     input++;                       			          input++; //**Note the LACK OF THE addition of '&'**
     std::cout<<"In the function call a = "<<input<<"\n";     std::cout<<"In the function call a = "<<input<<"\n";
     return input;                                        }
 }








//Pass the array throw the functions
/*Goal: Learn to pass arrays to functions*/

    #include<iostream>
    #include<iomanip>

    //Pass the array as a pointer
    void arrayAsPointer(int *array, int size);
    //Pass the array as a sized array
    void arraySized(int array[3], int size);
    //Pass the array as an unsized array
    void arrayUnSized(int array[], int size);

    int main()
    {
        const int size = 3;
        int array[size] = {33,66,99};
        //We are passing a pointer or reference to the array
        //so we will not know the size of the array
        //We have to pass the size to the function as well
        arrayAsPointer(array, size);
        arraySized(array, size);
        arrayUnSized(array, size);
        return 0;
    }

    void arrayAsPointer(int *array, int size)
    {
        std::cout<<std::setw(5);
        for(int i=0; i<size; i++) 
            std::cout<<array[i]<<" ";
        std::cout<<"\n";
    }

    void arraySized(int array[3], int size)
    {
        std::cout<<std::setw(5);
        for(int i=0; i<size; i++)
            std::cout<<array[i]<<" ";
        std::cout<<"\n";  
    }

    void arrayUnSized(int array[], int size)
    {
        std::cout<<std::setw(5);
        for(int i=0; i<size; i++)
            std::cout<<array[i]<<" ";
        std::cout<<"\n";  
    }

//NB se un parametro non si vuole modificare è bene passarlo come una costante
//es: input isn't modified;
    int doubleInput(const int input){
        int h = input *2; 
        return h;
    }
//es: input is modified-> but the code will not compile;
    int doubleInput(const int input){
        input++;
        int h = input *2;
        return h;
    }

//Fine parte pre-classi

//classes.cpp
