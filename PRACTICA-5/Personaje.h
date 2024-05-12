#ifndef PRACTICA_5_PERSONAJE_H
#define PRACTICA_5_PERSONAJE_H
#include <iostream>

using namespace std;

class Personaje {

public:

    Personaje();
    Personaje(const string &nombre, int vida, int ataque);

    const string &getNombre(void) const;
    void setNombre(const string &nombre);

    int getVida(void) const;
    void setVida(int vida);

    int getAtaque(void) const;
    void setAtaque(int ataque);

    int Atacar();

private:
    string nombre;
    int vida;
    int ataque;


};

ostream& operator<<(ostream& os, const Personaje &miPersonaje);

#endif //PRACTICA_5_PERSONAJE_H
