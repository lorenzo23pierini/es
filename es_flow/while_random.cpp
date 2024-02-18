#include <iostream>
#include <sstream>
#include <time.h> //added for the random number generator seed
#include <cstdlib> //added to use the rand function

int main()
{
    int target;
    std::string userString; //I use string type because I want inser ".q" to close the programm (like root)
    int guess=-1;

    srand(time(NULL)); //set the seed for the random number generator
    target=rand() %100+1; //generate the 'random' number

    while(guess!=target)
    {
        std::cout<<"Guess a number between 0 and 100: ";
        
        std::getline(std::cin,userString);
        std::stringstream(userString)>>guess; //converte in int (int because guess is int)
        std::cout<<userString<<"\n";

        if(guess>target)
            std::cout<<"Your guess is too high\n";
        else if(guess<target)
            std::cout<<"Your guess is too low\n";
        else
            std::cout<<"You guessed the target!\n";

        if(userString==".q")
        {
            std::cout<<"goof bye!";
            std::cout<<"The number was "<<target<<"\n";
            break;
        }
    }
    return 0;
}