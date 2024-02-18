#include<iostream>
#include<fstream>
#include<vector>

int main(){
    std::ifstream dati("dati.txt");
    if(!dati.is_open()){
        std::cerr<<"Impossibile aprire il file!"<<std::endl;
        return 1;
    }
    std::vector<double> x;
    std::vector<double> y;

    double ascissa, ordinata;

    while(dati>>ordinata>>ascissa){
        y.push_back(ordinata);
        x.push_back(ascissa);
    }
    dati.close();

    std::cout<<"Ascisse: ";
    for(auto& i : x){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    
    std::cout<<"Ordinate: ";
    for(auto& i : y){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;

    return 0;
}