#include "main.hpp"

int main()
{
    double n1,n2;
    char c;
    double calc;
    
    //insert(n1,n2,c); ATTENZIONE: le variabili non escono dalla funzione!!!
    //Quindi conviene inserirle da tastiera direttamente nel main()
    std::cout<<"Insert the first number: ";
    std::cin>>n1;

    std::cout<<"Insert the second number: ";
    std::cin>>n2;

    std::cout<<"Insert the operation: ";
    std::cin>>c;

    if(c=='+'||c=='-'||c=='*')
    {
        switch(c)
        {
            case('+'): calc=sum(n1,n2);
            break;
            
            case('-'): calc=diff(n1,n2);
            break;
            
            case('*'): calc=prod(n1,n2);
            break;
        }
        printEquation(n1,n2,calc,c);
    }
    else if(c=='/')
    {
        if(n2!=0)
        {
            calc=div(n1,n2);
            printEquation(n1,n2,calc,c);
        }
        else
            std::cout<<"The second number can't be equal to 0! Try again. \n";
    }
    else
        std::cout<<"Please insert one of this operations: +,-,* or /. Try again. \n";

    return 0;
}