#include <iostream>
#include "Funciones.h"
#include "Pareja.h"

using namespace std;

int main() {

    //APARTADO 1
    vector<int> miVector = {1,22,3,4,10,8,9};
    //vector<int> miVector = {};
    cout << "El numero mayor: " << EncontrarMayor(miVector) << endl;

    Persona per1("Juan", 24);
    Persona per2("Pepe", 30);
    Persona per3("Maria", 18);

    vector<Persona> misPersonas = {per1,per2,per3};

    cout << "La persona mayor es: " << EncontrarMayor(misPersonas) << endl << endl;


    //APARTADO 2
    cout << "Los numeros son: " << miVector << endl;
    cout << "Las personas son: " << misPersonas << endl << endl;


    //APARTADO 3
    Pareja<Persona, int> pareja1(per1,1);
    Pareja<Persona, int> pareja2(per2,2);

    vector<Pareja<Persona,int>> miVectorParejas = {pareja1, pareja2};

    for(const auto &elem: miVectorParejas){
        cout << "Nombre: " << elem.getVar1().getNombre() << " tienen una edad: " << elem.getVar1().getEdad() << " y tienen un numero " << elem.getVar2() << " ";
    }
    return 0;
}
