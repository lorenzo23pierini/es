#include <iostream>
#include <fstream> //Necessario per utilizzare ifstream

int main(){
    //Apertura di un file in modalità di lettura (ifstream)
    std::ifstream dati("dati.txt");

    //Verifica se l'apertura del file è avenuta con successo
    if(!dati.is_open()){
        std::cerr<<"Impossibile aprire il file!"<<std::endl;
        return 1;//Esce dal programma con codice di errore
    }

    //Utilizzando ifstream si legge il contenuto del file
    std::string line;
    while(std::getline(dati,line)){
        std::cout<<line<<std::endl;
    }

    //Chiudi il file dopo averlo letto
    dati.close();

    return 0;
}