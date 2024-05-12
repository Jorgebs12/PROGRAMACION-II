#include "Mago.h"

int Mago::getNivelMago() const {
    return nivelMago;
}


Mago::~Mago() {

    cout << "Mago Muerto" << endl;
}

int Mago::Atacar() {

    cout << "Abracadabra" << endl;
    return getAtaque();
}

Mago::Mago() {
    this -> nivelMago = 0;

}

void Mago::setNivelMago(int nivelMago) {
    Mago::nivelMago = nivelMago;
}

ostream& operator<<(ostream& os, const Mago &miMago){

    os <<  "Nombre: " << miMago.getNombre() << " "  << "Vida: " << miMago.getVida() << " " << "Ataque: " << miMago.getAtaque() << endl ;

    return os;
}