//Create a programm which is able to print the variable a from 0 to 2 and from 4 to 15 jumping 10

#include <iostream>

int main()
{
    int a=0;

    while(a<5)
    {
        a++;
        //we put the print command after the break
        if(a==3)
            break;
        std::cout<<a<<std::endl;
    }

    std::cout<<"Attentio! a=3 so the first while is stopped!"<<std::endl;

    while(a<15)
    {
        a++;
        if(a==10)
            continue;
        std::cout<<a<<std::endl;
    }
}