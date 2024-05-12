#ifndef PRACTICA_2_VEHICULO_H
#define PRACTICA_2_VEHICULO_H

#include<string>
#include<array>
using namespace std;

//DefiniciÃ³n de una estructura de etiqueta Matricula
struct Matricula{
    int numero{0};
    string letras;
};

class Vehiculo{

private:
    array<string,2> MarcaModelo;
    Matricula placa;
    int nRuedas;
    int nPlazas;

    bool ValorNumericoOk(int,int) const; //Como es la declaraciÃ³n del mÃ©todo no hace falta especificar la etiqueta
    bool ValorLiteralOk(const string&,const string &) const;

public:

    //CONSTRUCTOR POR DEFECTO
    Vehiculo();
    //CONSTRUCTOR CON PARAMETROS
    Vehiculo(int nRuedas, int nPlazas, const Matricula &matri, const array<string,2> &marcaModelo);
    //CONSTRUCTOR COPIA
    Vehiculo(const Vehiculo &);
    //DESTRCUTOR
    ~Vehiculo();



    const array<string,2>& getMarcaModelo() const;
    const Matricula& getMatricula() const;
    int getnRuedas() const;
    int getnPlazas() const;

    void setMarcaModelo(const array<string,2> &);
    void setMatricula(const Matricula &);
    void setnRuedas(int);
    void setnPlazas(int);

};


#endif //PRACTICA_2_VEHICULO_H
