#include "Vehiculo.h"
#include <iostream>

using namespace std;

bool Vehiculo::ValorNumericoOk(int mat, int n) const
{//Primer parÃ¡metro la parte numÃ©rica de la matricula, la segunda el nÃºmero de dÃ­gitos a comprobar
    //Implementamos el mÃ©todo de forma algorÃ­tmica para facilitar la reusabilidad
    int aux{mat},cont{0};

    while(aux>0)
    {//Vamos dividiendo entre 10 para contar el nÃºmero de cifras
        aux/=10;
        cont++;
    }

    if(cont>n)
    {//Si tiene mÃ¡s de n cifras no es ok
        return false;
    }

    return true; //Es ok
}
bool Vehiculo::ValorLiteralOk(const string &m, const string &t) const
{
    for(char elem:m)
    {//Recorremos la parte literal de la matricula
        if(t.find(elem)!=-1) //Si encontramos una de las letras no validas contenidas en t serÃ­a parte literal no vÃ¡lida
        {//string.find() devuelve -1 si el elemento estÃ¡ en la cadena
            return false;
        }
    }

    return true; //Valida
}

//DefiniciÃ³n de los mÃ©todos getter de la clase
const array<string,2>& Vehiculo::getMarcaModelo() const{return MarcaModelo;}
const Matricula& Vehiculo::getMatricula() const{return placa;}
int Vehiculo::getnRuedas() const{return nRuedas;}
int Vehiculo::getnPlazas() const{return nPlazas;}


//DefiniciÃ³n de los mÃ©todos setter de la clase
void Vehiculo::setMarcaModelo(const array<string,2> &mm){MarcaModelo=mm;}
void Vehiculo::setMatricula(const Matricula &m){
    if(ValorNumericoOk(m.numero,4))
    {//Si la parte numerica es ok, nos la "quedamos"
        placa.numero=m.numero;
    }
    else{
        throw 0;
    }

    if(ValorLiteralOk(m.letras,"AEIOUaeiou"))
    {//Si la parte literal es ok, nos la "quedamos"
        placa.letras=m.letras;
    }
    else{
        throw 1;
    }

}
void Vehiculo::setnRuedas(int r){
    if(r<0)
    {
        throw 3;
    }
    else
    {
        nRuedas=r;
    }
}
void Vehiculo::setnPlazas(int p){
    if(p<0)
    {
        throw 4;
    }
    else
    {
        nPlazas=p;
    }
}

Vehiculo::Vehiculo() {

}

Vehiculo::Vehiculo(int nr, int np, const Matricula &matri, const array<string, 2> &mm) {

    setnRuedas(nr);
    setnPlazas(np);
    setMatricula(matri);
    MarcaModelo = mm;
}

Vehiculo::Vehiculo(const Vehiculo &) {

}

Vehiculo::~Vehiculo() {

}
