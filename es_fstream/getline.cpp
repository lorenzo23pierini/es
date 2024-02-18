#include <iostream>
#include  <string>

int main(){
    std::string name1="";
    int add1=0;
    std::string Add1="";
    std::string cell1="";
    
    std::string name2="";
    int add2=0;
    std::string Add2="";
    std::string cell2="";
    
    std::cout<<"(Users 1) \n";
    std::cout<<"Name: ";
    getline(std::cin, name1);
    std::cout<<name1<<std::endl;
    
    std::cout<<"Address: ";
    std::cin>>add1;
    getline(std::cin, Add1);
    std::cout<<add1<<" "<<Add1<<std::endl;
    
    std::cout<<"Phone number: ";
    getline(std::cin, cell1);
    std::cout<<cell1<<std::endl;
    
    std::cout<<"(Users 2) \n";
    std::cout<<"Name: ";
    getline(std::cin, name2);
    std::cout<<name2<<std::endl;
    
    std::cout<<"Address: ";
    std::cin>>add2;
    getline(std::cin, Add2);
    std::cout<<add2<<" "<<Add2<<std::endl;
    
    std::cout<<"Phone number: ";
    getline(std::cin, cell2);
    std::cout<<cell2<<std::endl;
    /*
    Oppure:
    
    std::cout<<"\n\n"<<name1<<"\n";
    std::cout<<"\t\t"<<address1<<"\n";
    std::cout<<"\t\t"<<phoneNo1<<"\n";

    std::cout<<"\n\n"<<name2<<"\n";
    std::cout<<"\t\t"<<address2<<"\n";
    std::cout<<"\t\t"<<phoneNo2<<"\n";

    Utilizzando le indentazioni come richiesto dall'esercizio di Udacity
    */
    
    return 0;
}
