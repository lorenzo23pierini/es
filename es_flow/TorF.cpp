#include <iostream>
#include <string>

int main(){
    int a=5;
    int b=4;
    int c=5; //variabili che uso per creare diverse combinazioni di true e false

    std::string TorF[]={"False","True"}; //array di stringhe che utilizzo come immagazzinatore di 0,1

    std::cout<<"Find all possible outputs for the given expression: (A and B and C) or (A and((not B) or (not C))) = Q"<<std::endl;
    std::cout<<"If A,B and C are all true: Q="<<TorF[((a==c)&&(a==c)&&(a==c))||((a==c)&&((!(a==c))||(!(a==c))))]<<std::endl;
    std::cout<<"If A,B and C are all false: Q="<<TorF[((a==b)&&(a==b)&&(a==b))||((a==b)&&(!(a==b))||(!(a==b)))]<<std::endl;
    
    std::cout<<"If A is true and B,C false: Q="<<TorF[((a==c)&&(a==b)&&(a==b))||((a==c)&&((!(a==b))||(!(a==b))))]<<std::endl;
    std::cout<<"If B is true and A,C false: Q="<<TorF[((a==b)&&(a==c)&&(a==b))||((a==b)&&((!(a==c))||(!(a==b))))]<<std::endl;
    std::cout<<"If C is true and A,B false: Q="<<TorF[((a==b)&&(a==b)&&(a==c))||((a==b)&&((!(a==b))||(!(a==c))))]<<std::endl;
    
    std::cout<<"If A is false and B,C true: Q="<<TorF[((a==b)&&(a==c)&&(a==c))||((a==b)&&((!(a==c))||(!(a==c))))]<<std::endl;
    std::cout<<"If B is false and A,C true: Q="<<TorF[((a==c)&&(a==b)&&(a==c))||((a==c)&&((!(a==b))||(!(a==c))))]<<std::endl;
    std::cout<<"If C is false and A,B true: Q="<<TorF[((a==c)&&(a==c)&&(a==b))||((a==c)&&((!(a==c))||(!(a==b))))]<<std::endl;

    return 0;
}

