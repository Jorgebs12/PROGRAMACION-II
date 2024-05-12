#ifndef PRACTICA_3_VEHICULO_H
#define PRACTICA_3_VEHICULO_H

#include<string>
#include<array>
#include<iostream>
#include<limits>

using namespace std;

//DefiniciÃ³n de una estructura de etiqueta Matricula
struct Matricula{
    int numero{0};
    string letras;

public:
    string getCosa() const;
    void setCosa(const string &newCosa);
};

class Vehiculo {
private:
    array<string, 2> MarcaModelo;
    Matricula placa;
    int nRuedas;
    int nPlazas;

    bool ValorNumericoOk(int, int) const; //Como es la declaraciÃ³n del metodo no hace falta especificar la etiqueta
    bool ValorLiteralOk(const string &, const string &) const;

public:
    const array<string, 2> &getMarcaModelo() const;

    const Matricula &getMatricula() const;

    int getnRuedas() const;

    int getnPlazas() const;

    void setMarcaModelo(const array<string, 2> &);

    void setMatricula(const Matricula &);

    void setnRuedas(int);

    void setnPlazas(int);

    //Constructores
    Vehiculo();

    Vehiculo(int, int, int, const string &, const string &,
             const string &); //nPlazas,nRuedas,parte nÃºmerica matricula, marca vehÃ­culo, modelo vehÃ­culo
    Vehiculo(const Vehiculo &);

    //Destructor
    ~Vehiculo();

    //Predecremento
    Vehiculo& operator--();

    //Postdecremento
    Vehiculo operator++(int);


    //Operador <<
    friend ostream& operator <<(ostream &os, const Vehiculo &vehi){
        os << "Los datos del coche son: " << "Numero de plazas: " << vehi.getnPlazas() << " Numero de ruedas: " << vehi.getnRuedas() << " la matricula es: " << vehi.getMatricula().numero << "-" << vehi.getMatricula().letras  << " y el coche es: " << vehi.getMarcaModelo().at(0) << " " << vehi.getMarcaModelo().at(1);
        return os;
    }

    //Operador >>
    friend istream& operator >>(istream &is, Vehiculo &vehi){
        int rueda;
        int plaza;
        int mNumero;
        string mLetra;
        string marca;
        string modelo;

        cout << "Introduce el numero de ruedas: ";
        cin >> rueda;
        cout << "Introduce el numero de plazas: ";
        cin >> plaza;
        cout << "Introduce el numero de la matricula: ";
        cin >> mNumero;
        cout << "Introduce las letras de la matricula: ";
        cin >> mLetra;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Introduce la marca del coche: ";
        getline(is,marca);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Introduce el modelo del coche: ";
        getline(is,modelo);

        try{
            vehi.setnPlazas(plaza);
            vehi.setnRuedas(rueda);
            vehi.placa.numero = mNumero;
            vehi.placa.letras = mLetra;
            vehi.setMarcaModelo({marca,modelo});

            }catch(int e){
                cout << "Error: " << e << endl;
        }
        return is;
    }
};



#endif //PRACTICA_3_VEHICULO_H
