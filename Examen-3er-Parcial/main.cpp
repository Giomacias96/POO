#include <iostream>
#include <stdio.h>
using namespace std;

class Vehiculo{
  private:
    float VelocidadMaxima;
    int NumeroRuedas;
    string Marca;
    string Modelo;

  public:
    Vehiculo(float, int, string, string);
    virtual void mostrar();
    virtual ~Vehiculo(){}
};

class Moto : public Vehiculo{
  private:
    int Cilindrada;

  public: 
    Moto(float, int, string, string, int);
    void mostrar();
    ~Moto(){}
};

class Coche : public Vehiculo{
  private:
    string Traccion;

  public:
    Coche(float, int, string, string, string);
    void mostrar();
    ~Coche(){}
};

Vehiculo::Vehiculo(float _velMax, int _numRuedas, string _marca, string _modelo){
  VelocidadMaxima = _velMax;
  NumeroRuedas = _numRuedas;
  Marca = _marca;
  Modelo = _modelo;
}

void Vehiculo::mostrar(){
  cout << "Velocidad Maxima: " << VelocidadMaxima <<endl;
  cout << "Numero de Ruedas: " << NumeroRuedas <<endl;
  cout << "Marca: " << Marca <<endl;
  cout << "Modelo: " << Modelo <<endl;
}

Moto::Moto(float _velMax, int _numRuedas, string _marca, string _modelo, int _cilindrada) : Vehiculo(_velMax,_numRuedas,_marca,_modelo){
  Cilindrada = _cilindrada;
}

void Moto::mostrar(){
  Vehiculo::mostrar();
  cout << "Cilindrada: " << Cilindrada << endl;
}

Coche::Coche(float _velMax, int _numRuedas, string _marca, string _modelo, string _traccion) : Vehiculo(_velMax,_numRuedas,_marca,_modelo){
  Traccion = _traccion;
}

void Coche::mostrar(){
  Vehiculo::mostrar();
  cout << "Traccion: " << Traccion <<endl;
}

int main() {
  Vehiculo *vector[3];
  

  vector[0] = new Vehiculo(250,4,"Nissan","Tsuru");
  vector[1] = new Moto(300,2,"Mitsubishi","F-230",6);
  vector[2] = new Coche(220,4,"Ford", "Figo","Delantera");
  

  vector[0]->mostrar();
  cout<<endl;
  vector[1]->mostrar();
  cout<<endl;
  vector[2]->mostrar();
  cout<<endl;

  delete vector[0];
  delete vector[1];
  delete vector[2];

  return 0;
}