#include <iostream>
#include <stdio.h>
using namespace std;

class Registro;

class Producto{
  private:
    string nombreP;
  public:
    Producto();
    Producto(string nom);
  friend void mostrarDatos(Producto &pro1, Registro &r1);
};

Producto::Producto(){
  nombreP = "";
}
Producto::Producto(string nom){
  nombreP = nom;
}

class Registro{
  public:
    Registro();
    Registro(double cost);
  private:
    double costo;
  friend void mostrarDatos(Producto &pro1, Registro &r1);
};

Registro::Registro(){
  costo = 0;
}
Registro::Registro(double cost){
  costo = cost;
}
void mostrarDatos(Producto &pro1, Registro &r1){
  cout<<"Nombre producto: "<<pro1.nombreP<<endl;
  cout<<"Costo: "<<r1.costo;
}

int main() {
  Producto p1("Leche");
  Registro rel(0.90);
  cout<<endl;
  mostrarDatos(p1,rel);
  cout<<endl<<endl;
}  