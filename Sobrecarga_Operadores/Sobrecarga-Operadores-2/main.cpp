#include <iostream>
#include <stdio.h>
using namespace std;

class Racional{
    void reduce();
  public:
    Racional();
    Racional(const Racional& other);
    Racional(int num, int den = 1);

    void operator+=(const Racional& otro);
    void operator-=(const Racional& otro);
    void operator*=(const Racional& otro);
    void operator/=(const Racional& otro);

    Racional operator+(const Racional& otro) const;
    Racional operator-(const Racional& otro) const; 
    Racional operator*(const Racional& otro) const;
    Racional operator/(const Racional& otro) const;

    bool operator>(const Racional& otro) const;
    bool operator>=(const Racional& otro) const;
    bool operator<(const Racional& otro) const;
    bool operator<=(const Racional& otro) const;
    bool operator==(const Racional& otro) const;
    bool operator!=(const Racional& otro) const;

    float a_float() const {return float(_num) / float(_den);}
    float a_double() const {return double(_num) / double(_den);}

    void escribe(ostream& o) const;
    void lee(istream& i);

  private:
    int _num;
    int _den;
};

ostream& operator<<(ostream& o, const Racional& R);
istream& operator>>(istream& i, Racional& R);

Racional operator+(int n, const Racional& R);
Racional operator-(int n, const Racional& R);
Racional operator*(int n, const Racional& R);
Racional operator/(int n, const Racional& R);

int mcd(int a, int b){
  while (b != 0){
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void Racional::reduce(){
  int M = mcd(_num,_den);
  _num /= M;
  _den /= M;
  if((_num < 0 && _den < 0) || 
     (_den < 0 && _num > 0)){
    _num = -_num;
    _den = -_den;
  }
}

Racional::Racional(){
  _num = 0;
  _den = 1;
}
Racional::Racional(const Racional& other){
  _num = other._num;
  _den = other._den;
}
Racional::Racional(int num, int den){
  _num = num;
  _den = den;
  reduce();
}
void Racional::escribe(ostream& o) const{
  o << _num;
  if(_den != 1) o << '/' << _den;
}
void Racional::lee(istream& i){
  char c;
  i >> _num >> c >> _den;
  reduce();
}

ostream& operator<<(ostream& o, const Racional& R){
  R.escribe(o);
  return o;
}
istream& operator>>(istream& i, Racional& R){
  R.lee(i);
  return i;
}
void Racional::operator+=(const Racional& otro){
  int a = _num, b = _den;
  int c = otro._num, d = otro._den;
  _num = a*d + c*b;
  _den = b*d;
  reduce();
}
void Racional::operator-=(const Racional& otro){
  int a = _num, b = _den;
  int c = otro._num, d = otro._den;
  _num = a*d - c*b;
  _den = b*d;
  reduce();
}
void Racional::operator*=(const Racional& otro){
  _num *= otro._num;
  _den *= otro._den;
  reduce();
}
void Racional::operator/=(const Racional& otro){
  _num *= otro._den;
  _den *= otro._num;
  reduce();
}
Racional Racional::operator+(const Racional& otro) const{
  Racional resultado (_num, _den);
  resultado += otro;
  return resultado;
}
Racional Racional::operator-(const Racional& otro) const{
  Racional resultado (_num, _den);
  resultado -= otro;
  return resultado;
}
Racional Racional::operator*(const Racional& otro) const{
  Racional resultado (_num, _den);
  resultado *= otro;
  return resultado;
}
Racional Racional::operator/(const Racional& otro) const{
  Racional resultado (_num, _den);
  resultado /= otro;
  return resultado;
}
bool Racional::operator>(const Racional& otro) const{
  int a = _num, b = _den;
  int c = otro._num, d = otro._den;
  return a*d > c*b;
}
bool Racional::operator<=(const Racional& otro) const{
  return !operator>(otro);
}
bool Racional::operator<(const Racional& otro) const{
  int a = _num, b = _den;
  int c = otro._num, d = otro._den;
  return a*d < c*b;
}
bool Racional::operator>=(const Racional& otro) const{
  return !operator<(otro);
}
bool Racional::operator==(const Racional& otro) const{
  return _num == otro._num && _den == otro._den;
}
bool Racional:: operator!=(const Racional& otro) const{
  return !operator==(otro);
}
Racional operator+(int n, const Racional& R){
  return Racional(n) + R;
}
Racional operator-(int n, const Racional& R){
  return Racional(n) - R;
}
Racional operator*(int n, const Racional& R){
  return Racional(n) * R;
}
Racional operator/(int n, const Racional& R){
  return Racional(n) / R;
}

int main() {
  Racional Z;
  Racional R(-1,3);
  Racional S(1,2);
  Racional Y(2,5);

  cout << R + 2 << endl;
  cout << S * 2 << endl;
  cout << 1 - R << endl;
  
  cout << R.a_float() << endl;
  
 /* cout << R + S + S <<endl;
  cout << R - S <<endl;
  cout << R * S <<endl;
  cout << R / S <<endl;
  
  R = Racional(3,5);
  S = Racional(3,5);
  cout << (R > S) << endl;
  cout << (R >= S) << endl;
  cout << (R < S) << endl;
  cout << (R <= S) << endl;
  cout << (R == S) << endl;
  cout << (R != S) << endl;*/

  /*T.lee(cin);
  T.escribe(cout);
  cout<< endl;
  R.escribe(cout);
  cout<< endl;*/
  
}