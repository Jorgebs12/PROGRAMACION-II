
#ifndef PRACTICA_4_FUNCIONES_H
#define PRACTICA_4_FUNCIONES_H


#include <vector>
#include <iostream>
#include "Persona.h"

using namespace std;

//APARTADO 1
template<typename T>
T EncontrarMayor(const vector<T> &miVector){

    T mayor;

    if(miVector.empty()){
        throw 1;
    }
    mayor = miVector.at(0);

    for(int i=1; i <miVector.size();i++){
        if(miVector.at(i) > mayor ){
            mayor = miVector.at(i);
        }
    }
    return mayor;
}

//APARTADO 2
template<typename T>
ostream & operator << (ostream &os, const vector<T> &miVector){

    for(int i=0;i < miVector.size(); i++){
        os << miVector.at(i) << " - ";
    }
    return os;
}



#endif //PRACTICA_4_FUNCIONES_H
