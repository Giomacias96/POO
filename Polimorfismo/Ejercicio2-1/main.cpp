#include <iostream>
#include <stdio.h>
using namespace std;

class Animal{
  private:
    int edad;
  public:
    Animal(int);
    virtual void comer();
};

class Humano : public Animal{
  private:
    string nombre;
  public:
    Humano(int, string);
    void comer();
};

class Perro : public Animal{
  private:
    string nombre, raza;
  public:
    Perro(int, string, string);
    void comer();
};

Animal::Animal(int _edad){
  edad = _edad;
}

void Animal::comer(){
  cout << "Yo como ";
}

Humano::Humano(int _edad, string _nombre) : Animal(_edad){
  nombre = _nombre;
}

void Humano::comer(){
  Animal::comer();
  cout << "en una mesa, sentado en su silla." << endl;
}

Perro::Perro(int _edad, string _nombre, string _raza) : Animal(_edad){
  nombre = _nombre;
  raza = _raza;
}

void Perro::comer(){
  Animal::comer();
  cout << "en el suelo, con su plato" <<endl;
}

int main() {
  Animal *animales[2];

  animales[0] = new Perro(5,"Bobby", "Pastor Aleman");
  animales[1] = new Humano(18, "Juan");

  animales[0]->comer();
  animales[1]->comer();


return 0;
}