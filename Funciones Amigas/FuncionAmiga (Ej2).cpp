#include <iostream>
#include <stdio.h>
using namespace std;

class Ejemplo{
    int Atrib1, Atrib2;

  public:
    Ejemplo();
    Ejemplo(int, int);
    void Imprime();
    friend int Suma(int, Ejemplo);
};

Ejemplo::Ejemplo(){
  
}
Ejemplo::Ejemplo(int Num1, int Num2){
  Atrib1 = Num1;
  Atrib2 = Num2;
}
void Ejemplo::Imprime(){
  cout<<"Valor del primer atributo es: "<<Atrib1<<endl;
  cout<<"Valor del segundo atributo es: "<<Atrib2<<endl;
}
int Suma(int Dato, Ejemplo Valor){
  return (Dato + Valor.Atrib1 + Valor.Atrib2);
}
void UsaFuncionesAmigas(){
  int Resultado;
  Ejemplo ObjEjemplo(5,5);
  Resultado = Suma(5,ObjEjemplo);
  cout<<endl<<"El resultado de la suma es: "<<Resultado<<endl;
  ObjEjemplo.Imprime();
}

int main() {
  UsaFuncionesAmigas();
}