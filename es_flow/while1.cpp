/*Goal: In the programming quiz, use a while loop to prompt
**the user to guess a target number. 
**Tell the user if the guess is too high or too low. 
**The user enters -1  or guesses the target number to end 
**the program.
*/
#include <iostream>

int main()
{
    int target=55;
    int guess=-1;

    while(guess!=target)
    {
        std::cout<<"Guess a number between 0 and 100: ";
        std::cin>>guess;
        std::cout<<guess<<"\n";

        if(guess>target)
            std::cout<<"Your guess is too high\n";
        else if(guess<target)
            std::cout<<"Your guess is too low\n";
        else
            std::cout<<"You guessed the target!\n";

        //-1 to end the program (break)
        if(guess==-1)
        {
            std::cout<<"Good Bye!"<<std::endl;
            break;
        }
    }
    return 0;
}