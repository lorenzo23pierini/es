/*Write a program that asks a user for five numbers.
**Print out the sum and average of the five numbers.
*/
#include <iostream>

int main()
{
    double num=0;
    double sum=0;
    double average=0;
    std::cout<<"Inserire 5 numeri: \n";
    
    for(int i=0; i<5; i++)
    {
        std::cin>>num;
        sum+=num;
    }
    average=sum/5;
    

    std::cout<<"Somma: "<<sum<<std::endl;
    std::cout<<"Media: "<<average<<std::endl;
}
