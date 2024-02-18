#include<iostream>
using namespace std;

//DECLARATIONs
float add(float m1, float m2);
float sub(float m1, float m2);
float mult(float m1, float m2);
float div(float m1, float m2);

int main()
{
    float m1 = 4.0;
    float m2 = 3.5;
    float answer;

    //CALLINGs 
    answer = add(m1, m2);
    cout<<m1<<"+"<<m2<<" = "<<answer<<"\n";
    
    cout<<m1<<"-"<<m2<<" = "<<sub(m1,m2)<<"\n"; //Essendo uno variabile float la funzione può essere utilizzata direttamente come variabile
    cout<<m1<<"*"<<m2<<" = "<<mult(m1,m2)<<"\n";
    cout<<m1<<"/"<<m2<<" = "<<div(m1,m2)<<"\n";
    return 0;
}

//DEFINITIONs
float add(float m1, float m2)
{
    return m1 + m2;
}

float sub(float m1, float m2)
{
    return m1 - m2;
}

float mult(float m1, float m2)
{
    return m1 * m2;
}

float div(float m1, float m2)
{
    return m1 / m2;
}
