#include <iostream>
using namespace std;

class Patient{
    private:
        int idNumber;
    public:
        void setIdNumber(int idIn);
        int getIdNumber();
};

void Patient::setIdNumber(int idIn){
    idNumber=idIn;
}

int Patient::getIdNumber(){
    return idNumber;
}

class Dog{
    private:
        string breed;
    public:
        void setBreed(string breddIn);
        string getBreed();
};

void Dog::setBreed(string breedIn){
    breed=breedIn;
}

string Dog::getBreed(){
    return breed;
}

class Pet: public Patient, public Dog{
    private:
        string name;
    public:
        void setName(string nameIn);
        string getName();
};

void Pet::setName(string nameIn){
    name=nameIn;
}

string Pet::getName(){
    return name;
}

int main(){
    Pet pet1;
    pet1.setName("Toby");
    pet1.setBreed("Shiba");
    pet1.setIdNumber(1002034);

    cout<<pet1.getIdNumber()<<" "<<pet1.getBreed()<<" "<<pet1.getName()<<endl;

    return 0;
}