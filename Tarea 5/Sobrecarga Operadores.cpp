#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

class Persona{
  public:
    Persona();
    Persona(const char* n, int ed, int est);
    Persona(const Persona& otra);

    ~Persona();

    char* nombre() const {return nombre_;}
    int estatura() const {return estatura_;}
    int edad() const {return edad_;}

    void estatura(int e) {estatura_ = e;}
	  void edad(int e) {edad_ = e;}
	  void nombre(char* n);

    Persona& operator =(const Persona& otra);
	  Persona operator +(const Persona& otra);
	  Persona operator +(int n); //p + 4
	  friend Persona operator +(int n, Persona& p); // 4 + p

	  friend std::ostream& operator <<(std::ostream& os, Persona& p);
	  friend std::istream& operator >>(std::istream& is, Persona& p);


  private:
    char* nombre_;
    int edad_, estatura_;
};

Persona::Persona(){
  
}
Persona::Persona(const char* n, int ed, int est) : edad_(ed), estatura_(est){
  nombre_ = new char[strlen(n) + 1];
  strcpy(nombre_,n);
  
}
Persona::Persona(const Persona& otra){
  edad_ = otra.edad_;
	estatura_ = otra.estatura_;

	nombre_ = new char[strlen(otra.nombre_) + 1];
	strcpy(nombre_, otra.nombre_);
}

void Persona::nombre(char* n){
	delete [] nombre_;
	nombre_ = new char[strlen(n) + 1];
	strcpy(nombre_, n);
}
Persona& Persona::operator =(const Persona& otra){
	if(this != &otra){
		delete[] nombre_;
		nombre_ = new char[strlen(otra.nombre_) + 1];
	 	strcpy(nombre_, otra.nombre_);

		edad_ = otra.edad_;
		estatura_ = otra.estatura_;
	}
	return *this;
}

Persona Persona::operator +(const Persona& otra){
	Persona tmp;
	tmp.nombre_ = new char[strlen(this->nombre_) + strlen(otra.nombre_) + 1];
	strcpy (tmp.nombre_, (*this).nombre_); //(*p).atributo === p->atributo
	strcat (tmp.nombre_, otra.nombre_);

	tmp.edad_ = this->edad_ + otra.edad_;
	tmp.estatura_ = this->estatura_ + otra.estatura_;

	return tmp;
}

Persona Persona::operator +(int n){
	Persona tmp;
	
	tmp.nombre_ = new char[strlen(this->nombre_) + 1];
	strcpy(tmp.nombre_, this->nombre_);

	tmp.edad_ = this->edad_ + n;
	tmp.estatura_ = this->estatura_;
	
	return tmp;
}

Persona operator +(int n, Persona& p){
	Persona tmp;

	tmp.nombre_ = new char[strlen(p.nombre_)+1];
	strcpy (tmp.nombre_, p.nombre_);
	
	tmp.edad_ = p.edad_ + n;
	tmp.estatura_ = p.estatura_;

	return tmp;
}

ostream& operator <<(ostream& os, Persona& p){
	os<<"Nombre: "<<p.nombre()<<" Edad: "<<p.edad()<<" Estatura: "<<p.estatura()<<"cm"<<endl;
	return os;
}

istream& operator >>(istream& is, Persona& p){

	char nom[30];
	int ed, est;

	cout<<"Inserte un nombre (Max. 30 caracteres)"<<endl;
	is.getline(nom,30);

	cout<<"Inserte una edad"<<endl;
	is>>ed;

	cout<<"Inserte una estatura"<<endl;
	is>>est;

	p.nombre_ = new char[strlen(nom) + 1];
	strcpy(p.nombre_,nom);

	p.edad_ = ed;
	p.estatura_ = est;

	return is;
}

Persona::~Persona(){
	delete[] nombre_;
}



int main() {
  Persona pp ("Pepe", 30, 180);

	Persona pepito(pp);

	Persona unapersona;

	Persona maria("Maria",30,150);

	maria = maria+pp;

	pepito = 3 + pepito;
	cout<<pepito;

	cout<<"Inserte una persona!"<<endl;
	cin>>unapersona;

	cout<<unapersona;

	return 0;

}