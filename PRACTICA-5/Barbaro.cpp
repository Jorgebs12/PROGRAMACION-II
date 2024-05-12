#include "Barbaro.h"

int Barbaro::getDefensa() const {
    return defensa;
}

Barbaro::Barbaro() {
    this -> defensa = 0;
}

int Barbaro::Atacar() {
    cout << "Aaaaaaaaaa" << endl;
    return getAtaque();
}

Barbaro::~Barbaro() {
    cout << "Barbaro Muerto" << endl;
}

ostream& operator<<(ostream& os, const Barbaro &miBarbaro){

    os <<  "Nombre: " << miBarbaro.getNombre() << " " << "Vida: " << miBarbaro.getVida() << " " << "Ataque: " << miBarbaro.getAtaque() << endl ;

    return os;
}