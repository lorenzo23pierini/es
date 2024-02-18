#include "student.hpp"

int main()
{
    //int integer1;
    //float float1;

    int id; 
    int gradDate;
    Student Lollo; 
    
    cout<<"Inserisci id: ";
    cin>>id;
    cout<<"Inserisci gradDate: ";
    cin>>gradDate;
    //integer = 4; 
    //gradDate = 4.333; 
    cout<<"\n\n";

    Lollo.setName("Lorenzo Pierini"); //assign a value to the student name
    Lollo.setId(id); //assign a value to the student id number
    Lollo.setGradDate(gradDate); //assign a value to the student grad date
    
    //Let's print the values of our variables
    //cout<<"integer1 = "<<integer1<<"\n";
    //cout<<"float1 = "<<float1<<"\n\n";
    
    //There are two ways we can print the values of our class:
    //The first is to call the print function we created.
    cout<<"Using the Student::print function\n";
    cout<<"Student1 = ";
    Lollo.print();
    cout<<"\n\n";
    
    //The second is to access each member of the class using the get functions
    cout<<"Using the student access functions\n";
    cout<<"Student1 name = "<<Lollo.getName()<<"\n";
    cout<<"Student1 ID = "<<Lollo.getId()<<"\n";
    cout<<"Student1 Grad Date = "<<Lollo.getGradDate()<<"\n";
    
    return 0;
}