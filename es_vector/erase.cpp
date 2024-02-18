#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    vector<int>::iterator it;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    cout<<"Vector has "<<v.size()<<" elements, that are: "<<endl;
    for(it=v.begin(); it!=v.end(); it++)
        cout<<*it<<" ";
    cout<<endl;

    v.erase(v.begin()+4);
    cout<<"After clear, the vector has "<<v.size()<<" elements, that are: \n";
    for(it=v.begin(); it!=v.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
}