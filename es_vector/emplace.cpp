#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    vector<int>::iterator it;
    cout<<v.size()<<endl;

    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(it=v.begin(); it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    it=v.begin()+2;
    v.insert(it, 5);

    for(it=v.begin(); it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    it=v.begin()+2; //Se non resetto l'iterator il -5 viene messo alla fine
    v.emplace(it, -5);

    for(it=v.begin(); it!=v.end();it++)
        cout<<*it<<" ";
    cout<<endl;
}