#include <iostream>
#include <stdio.h>;
using namespace std;

class Persona{
  private:
    string Nombre;
    friend void FuncionAmiga(Persona&);

  public:
    Persona(string _Nombre = "Sin Nombre"){
      Nombre = _Nombre;
    }
    void SetNombre(string _Nombre){
      Nombre = _Nombre;
    }
    string GetNombre(){
      return Nombre;
    }
};

void FuncionAmiga(Persona &unapersona){
  unapersona.Nombre = "Pepe";
}

int main() {
  Persona p;

  FuncionAmiga(p);
  cout<<endl<< p.GetNombre();
}