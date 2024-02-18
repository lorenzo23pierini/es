#include "template_class.hpp"

int main(){
    StudentRecord<int> SRint(3);
    SRint.setId(111111);
    SRint.printGrades();

    StudentRecord<char> SRchar('B');
    SRchar.setId(222222);
    SRchar.printGrades();

    StudentRecord<float> SRfloat(3.333);
    SRfloat.setId(4444);
    SRfloat.printGrades();
    
    return 0;
}