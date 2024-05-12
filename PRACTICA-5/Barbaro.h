#ifndef PRACTICA_5_BARBARO_H
#define PRACTICA_5_BARBARO_H
#include "Personaje.h"

#include <iostream>

using namespace std;

class Barbaro: public Personaje {

public:

    Barbaro();
    Barbaro(const string &nombre, int vida, int ataque, int defensa):Personaje(nombre, vida, ataque), defensa(defensa){};

    ~Barbaro();

    int getDefensa() const;
    int Atacar();

private:

    int defensa;
};

//AQUI LE DECIMOS COMO TIENE QUE IMPRIMIR UN BARBARO
ostream& operator<<(ostream& os, const Barbaro &miBarbaro);

#endif //PRACTICA_5_BARBARO_H
