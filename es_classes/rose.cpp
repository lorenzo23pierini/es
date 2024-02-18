#include <iostream>
using namespace std;

class Flower{
    private:
        string bloomTime;
    public:
        Flower();
        void setBloomTime(string bloomIn);
        string getBloomTime();
};

Flower::Flower(){
    bloomTime="Default";
}

void Flower::setBloomTime(string bloomIn){
    bloomTime=bloomIn;
}

string Flower::getBloomTime(){
    return bloomTime;
}

class Rose: public Flower{
    private:
        string fragrance;
    public:
        Rose();
        void setFragrance(string fragranceIn);
        string getFragrance();
};

Rose::Rose(){
    fragrance="Default";
}

void Rose::setFragrance(string fragranceIn){
    fragrance=fragranceIn;
}

string Rose::getFragrance(){
    return fragrance;
}

int main(){
    Rose Rossa;
    Rossa.setFragrance("Dolce");
    cout<<Rossa.getFragrance()<<endl;

    Rose Bianca;
    Bianca.setFragrance("Pulita");
    cout<<Bianca.getFragrance()<<endl;

    Rossa.setBloomTime("All summer");
    Bianca.setBloomTime("First spring");

    cout<<Rossa.getBloomTime()<<endl;
    cout<<Bianca.getBloomTime()<<endl;

    return 0;
}