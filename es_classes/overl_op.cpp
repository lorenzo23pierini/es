#include "overl_op.hpp"

int main(){
    Shape s1(3,4);
    Shape s2(2,5);
    Shape s3(s1.getLength() + s2.getLength(), s1.getWidth() + s2.getWidth());

    int total=s1+s2;  
    
    print_info(s3);
    cout<< "Total: "<<total<<endl;
}