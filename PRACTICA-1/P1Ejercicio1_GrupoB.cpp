#include <iostream>
#include <array>

using namespace std;

//CLASE PERSONA
class Persona {

public:

    //CONSTRUCTORES
    Persona();
    Persona(const string &nombre, int edad);

    const string& getNombre() const;
    void setNombre(const string &newNombre);

    int getEdad() const;
    void setEdad(int newEdad);

private:

    string nombre;
    int edad;
};

//CLASE VEHICULO

struct Matricula {
    int numerica;
    string literal;
};

class Vehiculo {

public:

    //CONSTRUCTORES
    Vehiculo();
    Vehiculo(const array<string,2> &miArray, const Matricula &matri, int ruedas, int plazas);


    int getNumRuedas() const;
    void setNumRuedas(int newNumRuedas);

    int getNumPlazas() const;
    void setNumPlazas(int newnumPlazas);

    const Matricula &getMatri() const;
    void setMatri(const Matricula &matri);

    const array<string, 2> &getMarcModel() const;
    void setMarcModel(const array<string, 2> &marcModel);

private:

    array <string,2> MarcModel;
    Matricula matri;
    int numRuedas;
    int numPlazas;
};


int main() {

    Persona persona1("PEPE",25);
    array<string,2> miArray = {"Seat","Ibiza 1.6"};

    Matricula matri;
    matri.numerica = 1254;
    matri.literal = "JBK";

    Vehiculo coche1 (miArray, matri, 4,5);

    cout << "La persona se llama: " << persona1.getNombre() << " y tiene " << persona1.getEdad() << endl;

    cout << "El coche es: ";
    for(int i=0; i<miArray.size();i++){
        cout << miArray.at(i) << " ";
    }
    cout << "tiene estas ruedas: " << coche1.getNumRuedas() << " y estas plazas " << coche1.getNumPlazas() << endl;

    cout << "Matricula: " << coche1.getMatri().numerica << " " << coche1.getMatri().literal;

    return 0;
}

//DECLARACION DE LA CLASE PERSONA
const string &Persona::getNombre() const {
    return nombre;
}

void Persona:: setNombre(const string &newNombre){
    nombre = newNombre;
}

void Persona::setEdad(int newEdad){

    if(newEdad < 0){
        edad = 0;
    }else{
        edad = newEdad;
    }
}

int Persona::getEdad() const {
    return edad;
}

Persona::Persona() {

}

Persona::Persona(const string &n, int e) {
    nombre = n;
    setEdad(e);
}


//DECLARACION CLASE VEHICULO
int Vehiculo::getNumRuedas() const {
    return numRuedas;
}

void Vehiculo::setNumRuedas(int newNumRuedas) {

    if(newNumRuedas < 0){
        numRuedas = 0;
    }else{
        numRuedas = newNumRuedas;
    }
}

int Vehiculo::getNumPlazas() const {
    return numPlazas;
}

void Vehiculo::setNumPlazas(int newNumPlazas) {

    if(newNumPlazas < 0){
        numPlazas = 0;
    }else {
        numPlazas = newNumPlazas;
    }
}

const array<string, 2> &Vehiculo::getMarcModel() const {
    return MarcModel;
}

void Vehiculo::setMarcModel(const array<string, 2> &marcModel) {
    MarcModel = marcModel;
}

const Matricula &Vehiculo::getMatri() const {
    return matri;
}

void Vehiculo::setMatri(const Matricula &nueva) {

    for(int i =0;i<nueva.literal.size();i++){
        if(nueva.literal.at(i) == 'E'){
            matri.literal = "---";
            break;
        }else{
            matri.literal = nueva.literal;
        }
    }

    if(nueva.numerica > 9999){
        matri.numerica = 0;
    }else{
        matri.numerica = nueva.numerica;
    }
}

Vehiculo::Vehiculo() {

}

Vehiculo::Vehiculo(const array<string, 2> &arr, const Matricula &matri, int r, int p) {
    MarcModel = arr;
    setMatri(matri);
    setNumRuedas(r);
    setNumPlazas(p);
}



