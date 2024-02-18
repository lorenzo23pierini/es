#include <iostream>

using namespace std;

class Particle
{
        string name;
        double mass;
        int charge;
        string type;
        float spin;

    public:
        void setName(string n);
        void setMass(double m);
        void setCharge(int c);
        void setType(string bf);
        void setSpin(float s);

        string getName();
        double getMass();
        int getCharge();
        string getType();
        float getSpin();

        void print();
};

void Particle::setName(string n)
{
    name=n;
}

void Particle::setMass(double m)
{
    mass=m;
}

void Particle::setCharge(int c)
{
    charge=c;
}

void Particle::setType(string bf)
{
    type=bf;
}

void Particle::setSpin(float s)
{
    spin=s;
}

string Particle::getName()
{
    return name;
}

double Particle::getMass()
{
    return mass;
}

int Particle::getCharge()
{
    return charge;
}

string Particle::getType()
{
    return type;
}

float Particle::getSpin()
{
    return spin;
}

void Particle::print()
{
    cout<<name<<"\t\t "<<mass<<"\t\t "<<charge<<"\t\t "<<type<<"\t\t "<<spin<<endl;
}

