#include <iostream>
using namespace std;

class Vote
{
        int grade[10];
        int index;
    public:
        Vote();
        void setId(int id);
        void setGrade(int id, int gr);
        int getId();
        int getGrade(int id);
        float getAvg();
        void print();
};

Vote::Vote()
{
    for(int i=0;i<10; i++)
    {
        grade[i]=0;
    }
    index=0;
}

void Vote::setId(int id)
{
    index=id;
}

void Vote::setGrade(int id, int gr)
{
    grade[id]=gr;
}

int Vote::getId()
{
    return index;
}

int Vote::getGrade(int id)
{
    return grade[id];
}

float Vote::getAvg()
{
    int sum=0;
    for(int i=0;i<10;i++)
        sum+=grade[i];
    return sum/10.0;
}

void Vote::print()
{
    cout<<index<<"\n";
    for(int i=0;i<10;i++)
    {
        cout<<grade[i]<<" ";
    }
}
