#ifndef PRACTICA_5_HORDA_H
#define PRACTICA_5_HORDA_H

#include "Personaje.h"

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Horda{

public:

    Horda(const vector<T> &equipo){
        this -> equipo = equipo;
    }

    const vector<T> &getEquipo() const {
        return equipo;
    }

    friend ostream& operator<<(ostream& os, const Horda<T> &miHorda){

        // AQUI VAMOS A PASARLE EL OBJETO HORDA QUE TIENE EL VECTOR getEquipo QUE CONTIENE LOS PERSONAJES (MAGOS, BARBARO,ETC)
        // COMO NO SABE IMPRIMIR A UN MAGO HAY QUE SOBRECARGAR EL OPERADOS << EN LA CLASE MAGO, BARBARO Y PERSONAJE
        for(const auto &elem: miHorda.getEquipo() ){
            os << elem;
        }
        return os;
    }

private:

    vector<T> equipo;

};






#endif //PRACTICA_5_HORDA_H
