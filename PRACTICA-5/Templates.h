#ifndef PRACTICA_5_TEMPLATES_H
#define PRACTICA_5_TEMPLATES_H

#include <iostream>
#include "Horda.h"

using namespace std;

template<typename T>
bool EncontrarPersonaje(const Horda<T> &miHorda, const string &nombre){
    for(const auto &elem: miHorda.getEquipo()){

        if(nombre == elem.getNombre()){
            return true;
        }
    }

    return false;
}


#endif //PRACTICA_5_TEMPLATES_H
