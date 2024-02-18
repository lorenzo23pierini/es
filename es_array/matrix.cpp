/*Goal: practice using multidimensional arrays.
**Write a program that will accept values for a 4x4 array 
**and a vector of size 4. 
**Use the dot product to multiply the array by the vector. 
**Print the resulting vector. 
*/

#include<iostream>

int main()
{
    //NB: array dimensions must be known at compile time
    /*
    int row;
    int col;
    std::cout<<"Insert the dimension of the row: ";
    std::cin>>row;
    std::cout<<"Insert the dimension of the column: ";
    std::cin>>col;
    DA ERRORE ovviamente
    */
    const int row=4;
    const int col=4;

    int matrix[row][col];
    int vector[row],prod[row];
    int sum=0;

    //scrivi matrice
    std::cout<<"Insert the matrix elements: \n";
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
         {
            std::cout<<"matrix["<<i<<"]["<<j<<"] = \n";
            std::cin>>matrix[i][j];
            //std::cout<<"matrix["<<i<<"]["<<j<<"] ="<<matrix[i][j]<<"\n";
        }

    //scrivi vettore
    std::cout<<"Insert the vector elements: \n";
    for(int i=0;i<row;i++)
    {
        std::cout<<"vector["<<i<<"] = \n";
        std::cin>>vector[i];
    }

    //stampa matrice
    std::cout<<"Matrix: \n";
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            std::cout<<matrix[i][j]<<"\t";

        std::cout << std::endl; // Vai a capo dopo ogni riga
    }
    //stampa vettore
    std::cout<<"Vector: \n";
    for(int j=0;j<col;j++)
        std::cout<<vector[j]<<"\n";
    
    //Prodotto
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            sum=(matrix[i][j]*vector[j])+sum;

        prod[i]=sum;
        sum=0; //ad ogni riga la somma viene riazzerata;
    }
        
    //Stampa prodotto
    std::cout<<"Product: \n";
    for(int i=0;i<row;i++)
            std::cout<<prod[i]<<"\n";

    return 0;
}