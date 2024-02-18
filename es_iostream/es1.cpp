#include <iostream>
using namespace std;

double pi(){
    return 3.14;
}

void print(double x){
    cout<<"Il valore scelto è: "<<x<<endl;
}

int main(){
    int a;
    int* b;
    double c;
    b=&a;
    cout<<"Inserisci valore a: "<<endl;
    cin>>a;
    cout<<a<<endl;
    cout<<b<<endl;
    double p=pi();
    cout<<"Il valore di pi-greco è: "<<p<<endl;
    cout<<"Inserisci valore c: "<<endl;
    cin>>c;
    print(c);
}