/*Now I would like you to do a switch statement with breaks
**between the cases. Create a program that asks the user for
**two float numbers. Then asks the user if they would like to:
**add the numbers, subtract the numbers, multiply the numbers, 
**divide the numbers.
**The program should then print the numbers with the chosen
**operation and the solution. 
*/

#include <iostream>

int main()
{
    float in1, in2;
    float ris=0;
    char op;
    std::cout<<"Enter two numbers:\n";
    std::cin>>in1;
    std::cin>>in2;
    std::cout<<"Enter the operation '+','-','*','/':\n";
    std::cin>>op;
    
    switch(op)
    {
        case('+'): 
                {
                    ris=in1+in2; 
                    std::cout<<"You choose '+': "<<in1<<"+"<<in2<<"="<<ris<<std::endl;
                }
                   break;
        case('-'): 
                 {
                    ris=in1-in2;
                    std::cout<<"You choose '+': "<<in1<<"-"<<in2<<"="<<ris<<std::endl;
                }
                   break;
        case('*'): 
                {
                    ris=in1*in2;
                    std::cout<<"You choose '+': "<<in1<<"*"<<in2<<"="<<ris<<std::endl;
                }
                   break;
        case('/'): 
                {
                    ris=in1/in2;
                    std::cout<<"You choose '+': "<<in1<<"/"<<in2<<"="<<ris<<std::endl;
                }
                   break;
        default: std::cout<<"Please selected a correct operator from +,-,* and /. Try again.";           
    }
    
    std::cout<<ris<<std::endl;
    
    return 0;
}