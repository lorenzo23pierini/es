/*
Goal: practice if-else statements in C++
**Write a program to select the best pet. 
*/

#include<iostream>

int main()
{
   char skin, location; //ricorda di utilizzare '' e non "" per char!!
   
   std::cout<<"Would you like an animal with fur(f), feathers(t), or scales(s)?";
   std::cin>>skin;
   std::cout<<skin<<"\n";
   
   //Use if-else statements to control program flow
   if(skin=='f')
    {
         std::cout<<"Get a dog"<<"\n";
    }
    else if (skin=='t')
    {
         std::cout<<"Get a bird"<<"\n";
    }
    else if (skin=='s')
    {
        std::cout<<"Would you like an animal that lives in water(w), land(l), or both(b)?";
        std::cin>>location;
        
        //Use if-else statements to control program flow
        if(location=='w')
        {
            std::cout<<location<<" water \n";
            std::cout<<"Get a fish"<<"\n"; 
        }
        else if(location=='l')
        {
            std::cout<<location<<" land \n";
            std::cout<<"Get a gecko"<<"\n";
        }
        else if(location=='b')
        {
            std::cout<<location<<" both \n";
            std::cout<<"Get a frog"<<"\n";
        }
        else
            std::cout<<"Please insert w,l or b for water(w), land(l), or both(b). Try again. \n";
    }
    else
        std::cout<<"Please insert f,t or s for fur(f), feathers(t), or scales(s). Try again. \n";
   return 0;
}