#ifndef PRACTICA_4_PERSONA_H
#define PRACTICA_4_PERSONA_H

#include <vector>
#include <iostream>

using namespace std;

class Persona {

public:

    Persona();
    Persona(const string &nom, int ed);

    const string &getNombre() const;
    void setNombre(const string &nombre);

    int getEdad() const;
    void setEdad(int edad);


private:

    string nombre;
    int edad;
};

bool operator > (const Persona &per1, const Persona &per2);

ostream & operator << (ostream &os, const Persona &per);


#endif //PRACTICA_4_PERSONA_H
