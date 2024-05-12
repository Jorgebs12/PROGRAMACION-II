#include <iostream>
#include <array>
#include "Vehiculo.h"

using namespace std;

void estadoParking(const array<array<Vehiculo,6>,4> &miParking){

    for(int i=0; i<miParking.size(); i++){
        for(int j=0; j<miParking.size(); j++){
            if(miParking.at(i).at(j).getnPlazas() >= 1) {
                cout << "1";
            }else{
                cout << "0";
            }
        }
    }
}


void insertarVehiculo(const Vehiculo &vec, int fila, int columna, array<array<Vehiculo,6>,4> &miParking){

    if(vec.getnRuedas() <= 4 || vec.getnPlazas() <= 1){

        cout << "No puedes aparcar";
    } else{

        miParking.at(fila).at(columna) = Vehiculo();
    }
}

void sacarVehiculo(int fila, int columna, array<array<Vehiculo,6>,4> &miParking) {

    for (int i = 0; i < miParking.size(); i++) {
        for (int j = 0; j < miParking.size(); j++) {

            if (i == fila && j == columna) {

                Vehiculo();
                cout << "Vehiculo sacado";

            } else {

                throw "Plaza libre";
            }
        }
    }
}

void menu(){

    //DECLARACION DEL PARKING EN FORMA DE MATRIZ
    array<array<Vehiculo,6>,4> miParking;

    Matricula matri;
    matri.letras = "GHJ";
    matri.numero = 1234;

    array<string,2> miArray = {"SEAT", "IBIZA"};

    Vehiculo coche1 (4,4,matri,miArray);

    int op = 0;

    do{
        cout << endl;
        cout << "Elije un opcion: " << endl;
        cout << " 1. Visualizar estado del parking" << endl;
        cout << " 2. Aparcar un vehiculo" << endl;
        cout << " 3. Sacar un vehiculo" << endl;

        cin >> op;

        switch (op) {

            case 1:

                estadoParking(miParking);

                break;
            case 2:

                insertarVehiculo(coche1,4,5,miParking);

                break;

            case 3:

                int fila;
                int col;

                cout << "Introduce una fila: " << endl;
                cin >>  fila;
                cout << "Introduce una fila: " << endl;
                cin >>  col;

                sacarVehiculo(fila, col, miParking);

                break;

            default:
                break;
        }

    }while(op != 0);
}

int main() {

    menu();

    return 0;
}
