//Classes
//A class is user type of variable.
//The user can create a type of variable that contains data and/or functions

//Private memebers 
//Public methods

    class Classe
    {
            type1 member1;
            type2 member2;
            ...
        public:
            void setMember1(type1 m1);
            void setMemeber2(type2 m2);
            ...
            type1 getMember1();
            type2 getMember2();
            ...
            void print();
    };

    void Class::setMember1(type1 m1)
    {
        member1=m1;
    }

    void Class::setMember2(type2 m2)
    {
        member2=m2;
    }

    ...

    type1 Class::getMember1()
    {
        return member1;
    }

    type2 Class::getMemeber2()
    {
        return memeber2;
    }

    ...

    void Class::print()
    {
        cout<<member1<<" "<<member2<<endl;
    }

//Usually the class declaration and definition are inserted in an header file.
//To use the class methods is used the "dot operator" (.). 
//Also the (->) operator is used. But when there are parameters passed by reference.

    int main()
    {
        Class class1;
        class1.setMember1(/*choise by type1*/);
        class1.getMember1();
        class1.print();
        
        Class class2;
        class2.setMember1(/*choise by type2*/);
        class2.getMember1();
        class2.print();

        return 0;
    }

//Constructor
/*It is a special function that is executed whenever we create a new instance of the class.
It is used to set initial values of data members of the class.
For example: in our Dogs class we may want to have an initial value for the license.
If we set initial values, we do not need to require the program or user set every value.
*/
    Class(); //DECLARATION for a constructor

    Class::Class()
    {
        member1=value;
        member2=value;
        ...
    }

//Destructor
/*In addition to constructors, C++ also has destructors.
It is special class function that is called whenever an object goes out of scope.
Just like a constructor, a destructor is called automatically.

NB: It cannot.
    -return a value;
    -accept parameters.
    It must have the same name as the class.
*/
    ~Class(); //DECLARATION for a destructor

    Class::~Class()
    {
        //tasks to be completed befor going out of scope
    }
//One of the more important tasks of a destructor is releasing memory that was allocated by the class constructor and member functions.
//Example:
    int main()
    {
        Dog d1(1234); //con il costruttore definito possiamo inizializzare direttamente license
        cout<<d1.getLicense()<<endl;
        return 0;
    }
    //Nell'header file:
     class Dog
     {
            int license;
        public:
            Dog();
            ...
            ~Dog();
     };

     Dog::Dog()
     {
        license=0;
     }

     Dog::~Dog(){}
/*
NB: Se non definisci né il costruttore né il distruttore in una classe C++, il compilatore fornirà delle implementazioni di default per entrambi.
Queste implementazioni di default svolgono compiti di base, ma potrebbero non essere sufficienti se la tua classe gestisce risorse dinamiche o richiede operazioni di inizializzazione o pulizia specifiche.
Ecco cosa succede in entrambi i casi:
-Costruttore: 
    -Costruttore di default: se non fornisci alcun costruttore, il compilatore genererà un costruttore di default.
    Questo costruttore esegue un'allocazione di memoria e inizializza le variabili membro (se presenti) in base alle regole di inizializzazione predefinite per i rispettivi tipi.
    -Costruttore di copia: se la tua classe non fornisce un costruttore di copia, il compilatore ne genererà uno di default.
    Questo costruttore di copia esegue una copia superficiale dei membri della classe.
-Distruttore:
    -Distruttore di default: se non fornisci un distruttore, il compilatore genererà un distruttore di default.
    Questo distruttore esegue la distruzione degli oggetti memebri e delle risorse allocate dalla classe.
    Tuttavia, se la classe gestisce risorse dinamiche (ad esmepio, memoria allocata con 'new'), il distruttore generato di default potrebbe non liberare correttamente queste risorse, causando perdite di memoria.
In molti casi, se una classe ha bisogno di gestire risorse dinamiche o eseguire operazioni di inizializzazione o pulizia particolari, è cosigliabile definire manualmente il costruttore e il distruttore.
In questo modo, hai il controllo completo su come vengono getite le risorse della classe.
*/

//Helper Functions in Classes
//Classes can have memeber functions that do more than just set or get data values.
//These helper functions can perform tasks that are often requested or are easier to permorm in the class itself.

//Pointer This
//'this' returns its own address.
//It is usefull for call an object of the same class in witch we are considering the call.
//es:
    #include <iostream>
 
    using namespace std;

    class Shape {
        public:
        // Constructor definition
        Shape(int l = 2, int w = 2) {
            length = l;
            width = w;
        }
		
        double Area() {
            return length * width;
        }
		
	    //Use 'this' to compare areas
        int compareWithThis(Shape shape) {
             return this->Area() > shape.Area();
        }

        //'this' is not necessary to compare shapes
        int compare(Shape shapeIn) {
             return Area() > shapeIn.Area();
        }
      
        private:
        int length;     // Length of a box
        int width;
    };

    int main(void) 
    {
        Shape sh1(4, 4);    // Declare shape1
        Shape sh2(2, 6);    // Declare shape2

        if(sh1.compare(sh2)) {
            cout << "\nShape2 is smaller than Shape1" <<endl;
        } 
        else 
        {
            cout << "\nShape2 is equal to or larger than Shape1" <<endl;
        }

        if(sh1.compareWithThis(sh2)) {
            cout << "\nShape2 is smaller than Shape1" <<endl;
        } 
        else 
        {
            cout << "Shape2 is equal to or larger than Shape1" <<endl;
        }
        
        return 0;
    }

//Constructors w Parameters
//C++ allows class constructors to accept parameters. These parameters will set the values of class members when the object is created.
//Let's look at an example of a Constructor with Parameters. (Like in the previouse example)
//es:
    class Patient{
        string name;

        public:
        Patient(string input);
        void setName(string input);
        string getNae();
    };

    Patient::Patient(string input){
        name=input; //when an object is created the name must be added as a parameter
    }
    
    void Patient::setName(string input){
        name=input;
    }

    string Patient::getName(){
        return name;
    }

//Overloading-----------------------------------------------------------------------------------------
//Considering this following example:
    #include<iostream>

    int findSmallerInt(int input1, int input2);
    float findSmallerFloat(float input1, float input2);
    char findSmallerChar(char input1, char input2);

    int main()
    {
        int a = 5; 
        int b = 4;
        float f1 = 5.43;
        float f2 = 6.32;
        char c1 = 'c';
        char c2 = 'z';
        std::cout<<findSmallerInt(a,b)<<" is the smaller of "<<a<<" and "<<b<<"\n";
        std::cout<<findSmallerFloat(f1,f2)<<" is the smaller of "<<f1<<" and "<<f2<<"\n";
        std::cout<<findSmallerChar(c1,c2)<<" is the smaller of "<<c1<<" and "<<c2<<"\n";
        
        return 0;
    }

    int findSmallerInt(int input1, int input2)
    {
        if(input1<input2)
            return input1;
        return input2;
    }
    float findSmallerFloat(float input1, float input2)
    {
        if(input1<input2)
            return input1;
        return input2;
    }

    char findSmallerChar(char input1, char input2)
    {
        if(input1<input2)
            return input1;
        return input2;
    }

//Wow, that was a pain. 
//The same code written three times with three different declarations and definitions!
/*
Function Overloading:
It will allow us to use the same function name for different functions.
As long as the argument list is different, the compiler will be able to choose the correct definition.
Different argument list means either the variable type is different and/or the number of arguments is different.
*/
    #include<iostream>

    //C++ allows us to 'overload' the same function name as long as
    //the variable types in the function inputs are different.
    int findSmaller(int input1, int input2);
    float findSmaller(float input1, float input2);
    char findSmaller(char input1, char input2);

    int main()
    {
        int a = 5; 
        int b = 4;
        float f1 = 5.43;
        float f2 = 6.32;
        char c1 = 'c';
        char c2 = 'z';
        std::cout<<findSmaller(a,b)<<" is the smaller of "<<a<<" and "<<b<<"\n";
        std::cout<<findSmaller(f1,f2)<<" is the smaller of "<<f1<<" and "<<f2<<"\n";
        std::cout<<findSmaller(c1,c2)<<" is the smaller of "<<c1<<" and "<<c2<<"\n";
        
        return 0;
    }

    int findSmaller(int input1, int input2)
    {
        if(input1<input2)
            return input1;
        return input2;
    }
    float findSmaller(float input1, float input2)
    {
        if(input1<input2)
            return input1;
        return input2;
    }

    char findSmaller(char input1, char input2)
    {
        if(input1<input2)
            return input1;
        return input2;
    }
//The same name for different functions. 
//They are differents from the number and the types of the parameters.
//--
//Overloading in a Class
    class Compare{
        public:
        int findSmaller(int input1, int input2);
        float findSmaller(float input1, float input2);
        char findSmaller(char input1, char input2);
    };

    int Compare::findSmaller(int input1, int input2){
        if(input1<input2)
            return input1;
        return input2;
    }

    float Compare::findSmaller(float input1, float input2){
        if(input1<input2)
            return input1;
        return input2;
    }

    char Compare::findSmaller(char input1, char input2){
        if(input1<input2)
            return input1;
        return input2;
    }

//Overloading Constructors
/*
We saw in the Classes lesson that we can have two kinds of constructors:
    -those that do not have input parameters
    -those that do have them.
There will be times when we would like to have both options in a class. Luckily, we can use Overloading to achieve it!
When create a class we can have two different constructors and the compiler will know which one we want.
The program below is an example of a class that has two kinds of constructors.
*/
//es:
    //main.cpp
    #include "main.hpp"

    int main(){
        Square s1;
        Square s2(4,3);
        cout<<"s1 dimensions are: "<<s1.getWidth()<<","<<s1.getLength();
        cout<<"\ns2 dimensions are: "<<s2.getWidth()<<","<<s2.getLength();
        return 0;
    }

    //main.hpp
    #include<iostream>
    #include<string>
    using namespace std;

    class Square
    {
        private:
            int length;
            int width;
        public:
            Square();
            Square(int lenIn, int widIn);
            int getLength();
            int getWidth();
    };

    Square::Square(){
        length = 0;
        width = 0;
    }

    Square::Square(int lenIn, int widIn){
        length = lenIn;
        width = widIn;
    }

    int Square::getLength(){
        return length;
    }

    int Square::getWidth(){
        return width;
    }

//Overloading Operators
//We can define Operators between specific methods of the class
//We can overload operators in C++. This is useful when using user defined objects.
//In the example below we will use operators to overload the '+' sign.
//Let's look at the example in detail.
//You can see in the code below, the function must specify a return type. Then it must use the keyword 'operator' followed by the '+' sign.
//es:

    #include <iostream>
    using namespace std;

    class Shape{
        private:
        int length;     // Length of a box
        int width;
        
        public:
        // Constructor definition
        Shape(int l = 2, int w = 2){
            length = l;
            width = w;
        }
            
        double Area(){
            return length * width;
        }
        
        int operator + (Shape shapeIn){ //Overloading Operators
            return Area() + shapeIn.Area();
        }
    };

    int main() {
        Shape sh1(4, 4);    // Declare shape1
        Shape sh2(2, 6);    // Declare shape2
        
        int total = sh1 + sh2;
        cout << "\nsh1.Area() = " << sh1.Area();
        cout << "\nsh2.Area() = " << sh2.Area();
        cout << "\nTotal = "<<total;
        return 0;
    }

//The function that overloads the '+' sign
    int operator + (Shape shapeIn){
        return Area() + shapeIn.Area();
    }
//To use the overloaded '+' sign, we just have to use it with our user defined objects.
//In this example:
    int total = sh1 + sh2;
//In this case the '+' will add the areas of the two shapes.

//Templates
//We saw how overloading can be used to create a function that is fairly generic.
//Unfortunately, we still have to write a function for each variable type. 
//Wouldn't it be nice ti just write a function once and use it over and over for different variable types.
//It is possible! In C++ we can use a generic function using 'templates'.
//es: we start with our function int
    int findSmallerInt(int input1, int input2){
        if(input1<input2)
            return input1;
        return input2;
    }
    //The function is can be make generic using template

    #include <iostream>
    using namespace std;

    template <typename T> //tell the compiler we are using a template
    T findSmaller(T input1, T input2);

    int main(){
        ...
    }

    template <typename T>//Va ripetuto anche sopra la funzione
    T findSmaller(T input1, T input2){
        if(input1<input2)
            return input1;
        return input2;
    }

//So in general we have:
    template <typename T>  //tell the compiler we are using a template
    T  functionName (T parameter1,T parameter2, ...); //T represents the variable type. Since we want it to be for any type, we use T
//The function definition:
    template <typename T>
    T functionName(T parameter1, T parameter2){
        function statements;
    }

//In general, if the types are different we have:
    template <typename T, typename U, typename V>
    T functionName(U parameter1, V parameter2, ...){
        function srtatements;
    }

//We can expand this concept to a Class. We can use generic Classes.
//In C++, we can create generic classes as well as functions.
//We use the same template type placeholder as we did for functions.
//Let's look at an example of a generic class.
    //template_class.cpp    &   multiplier.cpp

//NB: In una classe con array, utilizzare un costruttore con defaultInput
    template <class T>
    Class_name<T>::Class_name(T defaultInput){
        for(int i=0; i<SIZE; i++)
            array[i]=defaultInput;
    }

//___________________________________________________________________________________________________________________
//Inheritance
/*
In C++ we can derive a class from another class, called a base.
The derived class can access members and functions of the base class.
                
                .------------.
                | Base Class |
                .------------.
                      |
                      |
                .---------------.
                | Derived Class | The derived class has inherited from thw base class
                .---------------.   

Let's do a quick example to illustrate the concept of inheritance.    
*/
    class Student{                                      class GradStudent: public Student{
        private:                                            private:
            int id;                                             string degree;
        public:                                             public:
            void setId(int idIn);                               GradStudent();
            int getId();                                        void setDegree(string degreeIn);
            Student();                                          string getDegree();
    };                                                  };

    int main(){
        GradStudent gs1;
        gs1.setId(123456789); //Eredita i metodi di Student
        gs1.getId();

        gs1.setDegree("BSEE"); //Metodi di GradStudent

        return 0;
    }

/*NB:
-Public inheritance: class GradStudent: public Student
    means all public members of the base class are accessible to the derived class;
-Private inheritance: class GradStudent: private Student
    means all members of the base class are private to the derived class;
-Protected inheritance:  means all members of the base class are protected to the derived class.
It is very rare to have a protected or private inheritance, the vast majority of the time inheritance is public.

Let's look at an example of private inheritance:
*/
    class GrandStudent: private Student{
        private:
            string degree;
        public:
            GradStudent();
            void setDegree(string degreeIn);
            string getDegree();

            void setStudentId(int idIn); //need this to access Student::setId()
            int getStudentId(); //need this to access Student::getId()
    };
    //Now that we have a private inheritance, the Student member functions setId() and getId() are no longer available to the GradStudent vlass.
    //When we write the member functions, we must explictly refer to the Student Class.
    int GradStudent::getStudentId(){
        //We must access getId() as a private function
        return Student::getId();
    }

    void GradStudent::setStudentId(int idIn){
        //We must access setId() as a private function
        Stedent::setId(idIn);
    }

//rose.cpp inheritance

//Multiple Inheritance
//C++ classes can inherit from more than one class. This is known as "Multiple Inheritance". 
//The form for declaring multiple inheritance is:
    class DerivedClass: access BaseClass1, ..., acess BaseClassN{
        ...
    } 
//es:
    class TeachingAssociate: public Staff, public GradStudent{
        ...
    }
/*
       Staff            GradStudent
       |                |
       |                |
       Teaching Associate    //A grafical representation of multiple inheritance.
*/
//Let's look at an example of multiple inheritance.
    int main(){
        TA t1;
        t1.setSupervisor("Dr. Caohuu");
        t1.setId(55555);
        t1.setTitle("Adjunct Prof.");
        cout<<t1.getSupervisor()<<" "<<t1.getId()<<" "<<t1.getTitle();
        return 0;
    }

    class Staff{
        private:
            string title;
        public:
            Staff();
            void setTitle(string input);
            string getTitle();
    };
    ...

    class GradStudent{
        private:
            int studentId;
        public:
            GrandStudent();
            void setId(int input);
            int getId();
    };
    ...

    class TA: public Staff, public GradStudent{
        private:
            string supervisor;
        public:
            TA();
            void setSupervisor(string input);
            string getSupervisor();
    };
    ...

//_______________________________________________________________________________________________________
//PolyMorphism
//Limit of inheritance
    #include<iostream>
    #include<string>
    using namespace std;

    //Employee is a class for calculating the
    //pay for an hourly employee. 
    class Employee{
        private:
            float payRate;
            string name;
            int employeeNumber;
        public:
            void setPayRate(float rateIn);
            float getPayRate();
            float calcWeeklyPay();
    };
    void Employee::setPayRate(float rateIn){
        payRate = rateIn;
    }
    float Employee::getPayRate(){
        return payRate;
    }
    float Employee::calcWeeklyPay(){
        return 40 * payRate;
    }

    //The class manager inherits from Employee
    //The only difference... managers are salary
    //employees. So the pay is calculated differently.
    class Manager : public Employee{
        public:
            float calcWeeklyPay();
    };

    float Manager::calcWeeklyPay(){
        //weekly pay is based on the yearly salary
        //divided by 52 weeks
        return Employee::getPayRate() /52;
    }

//The weekly pay for an employee is calculated as: pay=PayRate*HoursWorked;
//For the manager weekly pay is calculated as: pay=Salary/52.

    int main()
    {
        Employee e1;
        e1.setPayRate(10.00);
        Manager m1;
        m1.setPayRate(12000.00);
        cout<<"e1 pay: $"<<e1.calcWeeklyPay();
        cout<<"\nm1 pay: $"<<m1.calcWeeklyPay();

        return 0;
    }
 //It would be nice if we didn't have to specify which type of employee when we instantiated an object.
 //It would be nice if we could just say employee, since both are employees.
 //So let's change the program to allow us to handle all employees the same way.

    int main(){
        const string status= "salary";
        string level;

        if (status != level){
            Employee e1;
            e1.setPaRate(10.00);
            cout<<"e1 pay: $"<<e1.calcWeeklyPay();
        }
        else{
            Manager e1;
            e1.setPayRate(12000.00);
            cout<<"e1 pay: $"<<e1.calcWeeklyPay();
        }
    }
//Weel, that worked, but we now we have to mantain a different branch for each employee type.

//Let's try something else.
//If we define a pointer of type Employee, we can reduce the amount of redundant code.
//the question is... does it work?

    int main(){
        const string status="salary";
        string level;
        level="hourly";
        Employee *e1; //e1 is now a pointer to Employee object

        if(status != level){
            e1=new Employee(); //we define ad hourly employee
        }
        else{
            e1=new Manager(); //we define a salaried employee
        }
        e1->setPayRate(12000.00);
        cout<<"This doesn't work. We get the wrong pay. \n"; //NON FUNZIONA
        cout<<"e1 pay: $"<<e1->calcWeeklyPay();
        cout<<"\nThe pay is calculated as an hourly employee.";

        delete e1;
        return 0;
    }
//We created a pointer to an employee object.
//Now we only have to define which type of employee.
//Then we can use the same code for all employees.
//NON FUNZIONA

//Il primo modo funziona ma complica il codice e appesantisce il programma dovendo scrivere codice diverso per le due tipologie.
//Il secondo non funziona, ma semplifica il codice alleggerendo il programma.
    /*
    Let's think about what we are doing here. We assign an Employee pointer at the start of the program.
    This allocates memory to an Employee object.
    Then later, we define that same memory location as a manager.
    This should now supersede the previous fìdefinition, but it doesn't.
    Another way to say this is:

    The term e1 is statically bound during compile. 
    We want it to be dynamically bound during execution.

    C++ allows dynamic binding throught the use of Virtual Functions!
    */
                            //|
                            //|
//Virtual Function:
/*
A virtual function is a member function that you expect to be redefined in derived classes.
When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class's version of the function.
*/
    class Employee
    {
        private:
            float payRate;
            string name;
            int employeeNumber;
        public:
            void setPayRate(float rateIn);
            float getPayRate();
            //This is now a virtual function
            virtual float calcWeeklyPay(); 
    };
    void Employee::setPayRate(float rateIn){
        payRate = rateIn;
    }
    float Employee::getPayRate(){
        return payRate;
    }
    float Employee::calcWeeklyPay(){
        return 40 * payRate;
    }

    //The class manager inherits from Employee
    //The only difference... managers are salary
    //employees. So the pay is calculated differently.
    class Manager : public Employee{
        public:
            float calcWeeklyPay();
    };

    float Manager::calcWeeklyPay(){
        //weekly pay is based on the yearly salary
        //divided by 52 weeks
        return Employee::getPayRate() /52;
    }
/*
NB:
We only had to add the keyword virtual in one location in the base class. 
Any class derived from Employee that has a function by the same name will inherit the same properties.
*/

//Pure Virtual Functions
//A pure virtual function is used when the base class has a function that will be defined in its derived class, but it has no meaningful definition in the base class.

    #include<iostream>
    #include<string>
    using namespace std;

    class Animal 
    {
        private:
            string name;
            float baseRate;
            string type;
        public:
            Animal(string nameIn, float baseRateIn, string typeIn);
            //this is our virtual function
            virtual float calcDailyRate();
            float getBaseRate();
    };

    Animal::Animal(string nameIn, float baseRateIn, string typeIn)
    {
        name = nameIn;
        baseRate = baseRateIn;
        type = typeIn;
    }

    //we would never actual calcualte a daily rate for 
    //an "animal" so we don't really need this function. 
    float Animal::calcDailyRate()
    {
        return baseRate * 1.0;
    }

    float Animal::getBaseRate()
    {
    return baseRate; 
    }

    class Cat: public Animal
    {
            public:
            Cat(string nameIn, float baseRateIn, string typeIn);
            float calcDailyRate();
    };

    Cat::Cat(string nameIn, float baseRateIn, string typeIn)
            :Animal(nameIn, baseRateIn, typeIn)
            {
                cout<<"\nin cat constructor";
            }

    float Cat::calcDailyRate()
    {
        return Animal::getBaseRate() * 1.5;
    }
    //=============
    class Dog: public Animal
    {
            public:
            Dog(string nameIn, float baseRateIn, string typeIn);
            float calcDailyRate();
    };

    Dog::Dog(string nameIn, float baseRateIn, string typeIn)
            :Animal(nameIn, baseRateIn, typeIn)
            {
                cout<<"\nin dog constructor";
            }

    float Dog::calcDailyRate()
    {
        return Animal::getBaseRate() * 2.0;
    }


    int main()
    {
        Cat c1("polly", 20.0, "cat");
        Dog d1("spot", 30.0, "dog");
        
        cout<<"\nPolly Rate: $"<<c1.calcDailyRate();
        cout<<"\nSpot Rate: $"<<d1.calcDailyRate();
    
        return 0;
    }



