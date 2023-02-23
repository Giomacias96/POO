#include <iostream>
#include <stdio.h>
using namespace std;

class Persona{
    string Id;
    string Nombre;

  public:
    Persona(string _Id, string _Nombre){
      cout << "Constructor Persona" << endl;
      Id = _Id;
      Nombre = _Nombre;
    }

    virtual void Mostrar(){
      cout << "Mostrar Persona" << endl;
    }

    virtual ~Persona(){
      cout << "Destructor Persona" << endl;
    }
};

class Estudiante : public Persona{
    string Carrera;
  public:
    Estudiante(string _Id, string _Nombre, string _Carrera) : Persona(_Id, _Nombre){
      cout << "Constructor Estudiante" << endl;
    }

    void Mostrar(){
      cout << "Mostrar Estudiante" << endl;
    }

    ~Estudiante(){
      cout << "Destructor Estudiante" << endl;
    }
};

class Trabajador : public Persona{
    float Sueldo;
  public:
    Trabajador(string _Id, string _Nombre, float _Sueldo) : Persona(_Id, _Nombre){
      cout << "Constructor Trabajador" <<endl;
      Sueldo = _Sueldo;
    }

    void Mostrar(){
      cout << "Mostrar Trabajador" << endl;
    }

    ~Trabajador(){
      cout << "Destructor Trabajador" << endl;
    }
};

int main() {
  Persona *arr[3];

  arr[0] = new Estudiante("1", "Roger", "Sistemas");
  arr[1] = new Trabajador("2", "Cesar", 1300);
  arr[2] = new Persona("3", "Juan");

  arr[0]->Mostrar();
  arr[1]->Mostrar();
  arr[2]->Mostrar();

  delete arr[0];
  delete arr[1];
  delete arr[2];

  return 0;
}