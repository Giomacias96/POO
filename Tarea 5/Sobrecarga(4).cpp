#include <iostream>
#include <stdio.h>
using namespace std;

class Sally{
  public:
    int num;
    Sally();
    Sally(int);
    Sally operator+(Sally);
};

Sally::Sally(){
  
}
Sally::Sally(int a){
  num = a;
}
Sally Sally::operator+(Sally aso){
  Sally brandNew;
  brandNew.num = num + aso.num;
  return(brandNew);
}

int main() {
  Sally a(34);
  Sally b(21);
  Sally c;

  c = a + b;
  cout << c.num << endl;
}