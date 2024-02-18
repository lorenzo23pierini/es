#include "vote.hpp"

int main()
{
    Vote s1;
    s1.setId(339521);
    s1.setGrade(0,28);
    s1.setGrade(1,29);
    s1.setGrade(2,30);
    s1.setGrade(3,30);
    s1.setGrade(4,30);
    s1.setGrade(5,30);
    s1.setGrade(6,30);
    s1.setGrade(7,30);
    s1.setGrade(8,30);
    s1.setGrade(9,30);

    s1.getAvg();
    s1.print();
    cout<<endl;
    cout<<"The average of the chosen student is "<<s1.getAvg()<<endl;
    
    return 0;
}