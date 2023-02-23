#include <iostream>
#include <stdio.h>
using namespace std;

class Personaje{
    int ataque, defensa;
  public:
    Personaje(int a, int d){
      ataque = a;
      defensa = d;
    }

    void mostrarDatos(){
      cout<<"Ataque = "<<ataque<<endl;
      cout<<"Defensa = "<<defensa<<endl;
    }
  friend void modificar(Personaje &, int, int);
};

void modificar(Personaje &p, int at, int def){
  p.ataque = at;
  p.defensa = def;
}

int main() {
  Personaje principal(100,90);
  principal.mostrarDatos();
  modificar(principal, 50, 40);
  principal.mostrarDatos();
  
}