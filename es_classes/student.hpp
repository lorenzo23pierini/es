#include <iostream>

using namespace std;

class Student
{
        string name;
        int id;
        int gradDate;

    public:
        void setName(string nameIn); //set the private members
        void setId(int idIn);
        void setGradDate(int dateIn);

        string getName(); //get the private memebers
        int getId();
        int getGradDate();
        void print();
}; //SEMI-COLON

void Student::setName(string nameIn)
{
    name=nameIn;
}

void Student::setId(int idIn)
{
    id=idIn;
}

void Student::setGradDate(int gradDateIn)
{
    gradDate=gradDateIn;
}

void Student::print()
{
    cout<<name<<" "<<id<<" "<<gradDate;
}

string Student::getName()
{
    return name;
}

int Student::getId()
{
    return id;
}

int Student::getGradDate()
{
    return gradDate;
}
