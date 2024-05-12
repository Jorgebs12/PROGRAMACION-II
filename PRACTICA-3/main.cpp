#include <iostream>
#include "Vehiculo.h"
#include "Funciones.h"

using namespace std;

//Operador +
bool operator+(array<array<Vehiculo,6>,4> &p, const Vehiculo &miCoche){
    for(int i=0; i<p.size();i++){
        for(int j=0; j<p.size();j++){
            if(p.at(i).at(j).getnRuedas() == 0){
                p.at(i).at(j) = miCoche;
                return true;
            }
        }
    }
    return false;
}
int main() {

    std::cout << "Hello, Emilio!" << std::endl;

    Vehiculo miCoche(4,4,1234,"JBL","SEAT","IBIZA");

    array<array<Vehiculo,6>,4> miParking;

    //SOBRECARGA OPERADOR +
    miParking + miCoche;
    Mostrar(miParking);

    //SOBRECARGA EL OPERADOR <<
    cout << "OPERADOR << " << miCoche << endl;

    //SOBRECARGA PREDECREMENTO
    cout << "OPERADOR -- " << --miCoche << endl;

    //SOBRECARGA POSINCREMENTO
    cout << "OPERADOR ++ " << miCoche++ << endl;

    //SOBRECARGA DEL OPERADOR >>
    Vehiculo aux;
    cin >> aux;
    cout << aux;







    return 0;
}
