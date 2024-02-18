#include <iostream>

//void insert(double m1, double m2, char c);
void printEquation(double m1, double m2, double sum, char operation);
double sum(double m1, double m2);
double diff(double m1, double m2);
double prod(double m1, double m2);
double div(double m1, double m2);

//ATTENZIONE: le varibili rimangono dentro la funzione, una volta chiamata ed eseguiti i comandi i parametri non sono riutilizzabili nel main()!
//A meno che si restituiscono come output del return!
/*void insert(double m1, double m2, char operation)
{
    std::cout<<"Insert the first number: ";
    std::cin>>m1;

    std::cout<<"Insert the second number: ";
    std::cin>>m2;

    std::cout<<"Insert the operation: ";
    std::cin>>operation;

}
*/

void printEquation(double m1, double m2, double ris, char operation)
{
    std::cout<<m1<<" "<<operation<<" "<<m2<<" = "<<ris<<std::endl;
}


double sum(double m1, double m2)
{
    return m1+m2;
}

double diff(double m1, double m2)
{
    return m1-m2;
}

double prod(double m1, double m2)
{
    return m1*m2;
}

double div(double m1, double m2)
{
    return m1/m2;
}