#include <iostream>

using namespace std;

class Dog
{
        string name;
        int license;

    public:
        void setName(string nameDog);
        void setLicense(int licenseDog);
        string getName();
        int getLicense();
        void print();
};

void Dog::setName(string nameDog)
{
    name=nameDog;
}

void Dog::setLicense(int licenseDog)
{
    license=licenseDog;
}

string Dog::getName()
{
    return name;
}

int Dog::getLicense()
{
    return license;
}

void Dog::print()
{
    cout<<name<<" "<<license<<endl;
}