#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string line;
    //create an utput stream to write to the file
    //append the new lines to the end of the file
    std::ofstream myfileI("input.txt",std::ios::app);
    if(myfileI.is_open())
    {
        myfileI<<"\nI am adding a line.\n";
        myfileI<<"I am adding another line.\n";
        myfileI.close();
    }
    else std::cout<<"Unable to pen file for writing";
    
    //create an input stream to read the file
    std::ifstream myfileO ("input.txt");
    //During the creation of ifstream, the file is opened.
    //So we do not have explicitly open the file.
    if(myfileO.is_open())
    {
        while(getline(myfileO,line))
        {
            std::cout<<line<<"\n";
        }
        myfileO.close();
    }
    else std::cout<<"Unable to open file for reading";
   return 0;
}