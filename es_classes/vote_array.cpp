#include "vote.hpp"

int main()
{
    const int SIZE=3;
    Vote student[SIZE]; //creo un corso di studenti
    //Ogni elemento di array è un oggetto della classe Vote!
    //So it has access to the members of Student
    
    student[0].setId(1001); //001=0*2^2+0*2^1+1*2^0=1
    student[1].setId(2010); //2
    student[2].setId(3011); //3

    student[0].setGrade(0,83); 
    student[1].setGrade(0,95); 
    student[2].setGrade(0,72); 
    
    student[0].setGrade(1,75); 
    student[1].setGrade(1,91); 
    student[2].setGrade(1,55); 
    
    student[0].setGrade(2,89); 
    student[1].setGrade(2,85); 
    student[2].setGrade(2,71); 
    
    student[0].setGrade(3,73); 
    student[1].setGrade(3,90); 
    student[2].setGrade(3,60); 
    
    student[0].setGrade(4,46); 
    student[1].setGrade(4,100); 
    student[2].setGrade(4,80);

    student[0].setGrade(5,88); 
    student[1].setGrade(5,99); 
    student[2].setGrade(5,77);

    student[0].setGrade(6,73); 
    student[1].setGrade(6,55); 
    student[2].setGrade(6,45);
    
    student[0].setGrade(7,43); 
    student[1].setGrade(7,45); 
    student[2].setGrade(7,87);

    student[0].setGrade(7,43); 
    student[1].setGrade(7,45); 
    student[2].setGrade(7,87);  

    student[0].setGrade(8,100); 
    student[1].setGrade(8,70); 
    student[2].setGrade(8,60);

    student[0].setGrade(9,86); 
    student[1].setGrade(9,34); 
    student[2].setGrade(9,100);

    for(int i=0;i<SIZE;i++)
    {
        student[i].print();
        cout<<endl;
        cout<<endl;
    }

    cout<<"La media per ogni studente è: "<<endl;
    for(int i=0;i<SIZE;i++)
        cout<<student[i].getId()<<": "<<student[i].getAvg()<<"\t\t ";
    cout<<endl;
    cout<<"La media dell'intero corso è: "<<endl;
    int sum=0;
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<10;j++)
            sum=sum+student[i].getGrade(j);
    cout<<sum/30.0<<endl;
    return 0;
}