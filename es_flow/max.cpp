/*Find the min and max and average of 15 numbers that a user will input.
**The numbers range from 0 to 100. 
**We will do it now for practice and again later when we learn arrays and 
**functions. So you do not have to keep all fifteen numbers stored in memory.
**HINT: you will need to use scanf for input text.
*/

#include <iostream>

int main()
{
    int num=0;
    int max=0;
    
    for(int i=0;i<15;i++)
    {
        std::cout<<"Inserisci un numero da 0 a 100: "<<std::endl;
        std::cin>>num;
        if(num<0||num>100)
        {
            std::cout<<"Hai sbagliato a inserire il numero. Riprova."<<std::endl;
            i--; //Prima di continue sennò viene saltato il ripetere il passo i-esimo
            continue; //Fa proseguire il ciclo tornando indietro di uno grazie a i--
        }
        else
        {
            std::cout<<num<<" numero ["<<i+1<<"]\n";
            if(num>max)
                max=num;
        }
    }
    std::cout<<"Il massimo tra i numeri inseriti è: "<<max<<std::endl;
    return 0;
}
