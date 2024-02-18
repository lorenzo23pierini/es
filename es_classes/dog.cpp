#include "dog.hpp"

int main()
{
    Dog dog1;
    Dog dog2;

    //string name_dog1="Trixie"; //passaggio in più non necessario
    //int license_dog1=1234;
    //string name_dog2="Kali";
    //int license_dog2=5679;

    //dog1.setName(name_dog1); //posso lavorare direttamente negli argomenti dei metodi
    //dog1.setLicense(license_dog1);
    //dog2.setName(name_dog2);
    //dog2.setLicense(license_dog2);

    dog1.setName("Trixie"); //senza l'assegnazione dei parametri non funziona
    dog1.setLicense(1234);
    dog2.setName("Kali");
    dog2.setLicense(5679);

    dog1.print();
    dog2.print();

    return 0;
}