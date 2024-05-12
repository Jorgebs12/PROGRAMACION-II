#ifndef PRACTICA_5_MAGO_H
#define PRACTICA_5_MAGO_H
#include <iostream>
#include "Personaje.h"

using namespace std;

class Mago: public Personaje{

public:

    Mago();
    Mago(const string &nombre, int vida, int ataque, int nivelMago):Personaje(nombre, vida, ataque), nivelMago(nivelMago){};
    ~Mago();

    int getNivelMago() const;
    void setNivelMago(int nivelMago);

    int Atacar();

private:

    int nivelMago;
};

ostream& operator<<(ostream& os, const Mago &miMago);

#endif //PRACTICA_5_MAGO_H
