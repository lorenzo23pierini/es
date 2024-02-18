#include <iostream>
using namespace std;

class Shape{
     int length;
     int width;

     public:

     Shape(){
        length=0;
        width=0;
     }
     
     Shape(int l, int w){
        length=l;
        width=w;
     }

    int getLength(){
        return length;
    }

    int getWidth(){
        return width;
    }

    double Area(){
        return length*width;
     }

    //int operator +(Shape s){
    //    return Area()+s.Area();
    //}
    
   int operator +(Shape shapeIn)
      {
          return ((width + shapeIn.getWidth())*(length + shapeIn.getLength()));
      }
};

void print_info(Shape s){
    cout<<"Le dimensioni di s3 sono: \n";
    cout<<"length: "<<s.getLength()<<endl;
    cout<<"width: "<<s.getWidth()<<endl;
    cout<<"Area: "<<s.Area()<<endl;
}
