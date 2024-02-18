//Scrivere da file un array
//Invertire l'ordine degli elementi
//Ordinare i termini (sorting)
/*
Bubble Sort
metodo di ordinamento a bolle (Bubble Sort) implementato in linguaggio C++.
Questo algoritmo di ordinamento confronta coppie di elementi adiacenti e scambia i loro valori se sono fuori ordine.
L'iterazione continua fino a quando l'intero array è ordinato.
Utilizza due cicli for annidati per attraversare l'array e confrontare gli elementi adiacenti, effettuando gli scambi quando necessario.
*/

#include <iostream>

int main()
{
    int a[40];

    //Input
    for(int i=0;i<40;i++)
    {
        std::cin>>a[i];
    }

    //Print
    for(int i=0;i<40;i++)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;

    //Reverse
    for(int i=39;i>=0;i--)//inverto l'andamento dell'indice
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;

    //Sorting->Bubble Sort
    for(int i=0; i<40;i++)
    {
        for(int j=0;j<39-i;j++) //39-i altrimenti andrei oltre la fine dell'array
        {
            if(a[j]>a[j+1])
            {
                int temp; //temporary variable used to change the elements when they are out of sort
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for(int i=0;i<40;i++)
    {
        std::cout<<a[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}