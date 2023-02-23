#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

class Formula{
  private:
    float a,b,c;
  public:
    void SetA(float a){
      this -> a = a;
    }
    void SetB(float b){
      this -> b = b;
    }
    void SetC(float c){
      this -> c = c;
    }

    float x1(){
      return ((-b + sqrt(pow(b,2)- 4*a*c))/(2*a));
    }
    float x2(){
      return ((-b - sqrt(pow(b,2) - 4*a*c))/(2*a));
    }
};

int main() {
  Formula f;

  f.SetA(-1);
  f.SetB(7);
  f.SetC(-10);

  cout<<endl<< "X1: "<< f.x1();
  cout<<endl<< "X2: "<< f.x2();
}