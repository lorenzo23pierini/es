#include <iostream>
using namespace std;

template <class T>
class Multiplier{
    private:
        T M1;
        T M2;
        T product;
    public:
        void setM1(T input1);
        void setM2(T input2);
        void setProduct();
        T getM1();
        T getM2();
        T getProduct();
        void printEquation();
};

template<class T>
void Multiplier<T>::setM1(T input1){
    M1=input1;
}

template<class T>
void Multiplier<T>::setM2(T input2){
    M2=input2;
}

template<class T>
void Multiplier<T>::setProduct(){
    product=M1*M2;
}

template<class T>
T Multiplier<T>::getM1(){
    return M1;
}

template<class T>
T Multiplier<T>::getM2(){
    return M2;
}

template<class T>
T Multiplier<T>::getProduct(){
    return product;
}

template<class T>
void Multiplier<T>::printEquation(){
    cout<<M1<<" * "<<M2<<" = "<<product<<endl;
}


int main(){
    Multiplier<int> mInt;
    Multiplier<float> mFloat;

    mInt.setM1(-5);
    mInt.setM2(2);
    mInt.setProduct();

    mFloat.setM1(4.33);
    mFloat.setM2(8.25);
    mFloat.setProduct();

    mInt.printEquation();
    mFloat.printEquation();

    return 0;
}