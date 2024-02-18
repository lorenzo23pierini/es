#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vIn);
void assignFunction(vector<int> vIn, int in);
void pushBackFunction(vector<int> vIn, int in);
void emplaceFunction(vector<int> vIn, int loc, int in);

void printVector(vector<int> vIn){
    vector<int>::iterator it;
    cout<<"The vector elements are: ";
    if(vIn.size()==0)
        cout<<"----";
    else
        for(it=vIn.begin(); it!=vIn.end(); it++)
            cout<<*it<<" ";
    cout<<"\nThe size of the vector is: "<<vIn.size()<<"\n\n";
}
void assignFunction(vector<int> vIn, int in){
    cout<<"Assigning "<<in<<" and printing the vector: "<<endl;
    cout<<"(Note: Assign reset the entired vector)."<<endl;
    vIn.assign(1,in);
    printVector(vIn);
}
void pushBackFunction(vector<int> vIn, int in){
    cout<<"Push_Back "<<in<<" and printing the vector: "<<endl;
    vIn.push_back(in);
    printVector(vIn);
}
void emplaceFunction(vector<int> vIn, int loc, int in){
    cout<<"Emplaceing "<<in<<" and printing the vector: "<<endl;
    cout<<"(Note: loc is the location in which the user wants insert the element)."<<endl;
    vector<int>::iterator it;
    it=vIn.begin()+loc;
    vIn.emplace(it,in);
    printVector(vIn);
}

int main(){
    vector<int> v;
    printVector(v);

    v.assign(10,5);
    printVector(v);

    assignFunction(v,1); //Assign rimpiazza tutto il vector!!!

    pushBackFunction(v,2);

    emplaceFunction(v,1,3);

    v.clear();
    printVector(v);
}
