#include "Personaje.h"

Personaje::Personaje(const string &nombre, int vida, int ataque) {
    this -> nombre = nombre;
    this -> vida = vida;
    this -> ataque = ataque;
}

Personaje::Personaje() {
    this -> vida = 0;
    this -> ataque = 0;
}

int Personaje::Atacar() {
    return 0;
}

const string &Personaje::getNombre(void) const {
    return nombre;
}

void Personaje::setNombre(const string &nombre) {
    Personaje::nombre = nombre;
}

int Personaje::getVida(void) const {
    return vida;
}

void Personaje::setVida(int vida) {
    Personaje::vida = vida;
}

int Personaje::getAtaque(void) const {
    return ataque;
}

void Personaje::setAtaque(int ataque) {
    Personaje::ataque = ataque;
}

ostream& operator<<(ostream& os, const Personaje &miPersonaje){

    os <<  "Nombre: " << miPersonaje.getNombre() << " " << "Vida: " << miPersonaje.getVida() << " " << "Ataque: " << miPersonaje.getAtaque() << endl ;

    return os;
}