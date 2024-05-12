#include "Persona.h"

const string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const string &nombre) {
    Persona::nombre = nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::setEdad(int edad) {
    Persona::edad = edad;
}


Persona::Persona(){
    edad= 0;

}

Persona::Persona(const string &nom, int ed) {
    this -> nombre=nom;
    this -> edad=ed;
}


bool operator>(const Persona &per1, const Persona &per2) {
    return per1.getEdad() > per2.getEdad();
}

ostream &operator<<(ostream &os, const Persona &per) {

    os << per.getNombre() << " " << per.getEdad();

    return os;

}
