//Inheritance

#include <iostream>
using namespace std;

class Animal{
    public:
        bool alive=true;
    void eat(){
        cout<<"This animal is eating\n";
    }
};

class Dog : public Animal{
    public:

    void bark(){
        cout<<"The dog goes woof!\n";
    }
};

class Cat : public Animal{
    public:

    void meow(){
        cout<<"The cat goes meow!\n";
    }
};

int main(){
    Dog dog;
    cout<<(dog.alive ? "Alive" : "Dead")<<"\n";
    dog.eat();
    dog.bark();

    cout<<endl;

    Cat cat;
    cout<<(cat.alive ? "Alive" : "Dead")<<"\n";
    cat.eat();
    cat.meow();

}