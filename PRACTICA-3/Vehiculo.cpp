#include "Vehiculo.h"

bool Vehiculo::ValorNumericoOk(int mat, int n) const
{//Primer parÃ¡metro la parte numÃ©rica de la matricula, la segunda el nÃºmero de dÃ­gitos a comprobar
    //Implementamos el metodo de forma algorÃ­tmica para facilitar la reusabilidad
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
        //placa.numero=0;
        throw 1;
    }

    if(ValorLiteralOk(m.letras,"AEIOUaeiou"))
    {//Si la parte literal es ok, nos la "quedamos"
        placa.letras=m.letras;
    }
    else{
        //placa.letras="---";
        throw 2;
    }

}
void Vehiculo::setnRuedas(int r){
    if(r>0)
    {
        nRuedas=r;
    }
    else
    {
        //nRuedas=0;
        throw 3;
    }
}
void Vehiculo::setnPlazas(int p){
    if(p>0)
    {
        nPlazas=p;
    }
    else
    {
        //nPlazas=0;
        throw 4;
    }
}

//Constructores
Vehiculo::Vehiculo()
{
    nRuedas=0;
    nPlazas=0;
    placa.numero=0;
    //El resto de atributos no es necesario que sean inicializados, ya que tienen sus propios constructores
}
Vehiculo::Vehiculo(int pl, int r,int nM, const string& lM, const string& mar, const string& mod) //nPlazas,nRuedas,parte nÃºmerica matricula, marca vehÃ­culo, modelo vehÃ­culo
{
    array<string,2> aux; aux.at(0)=mar; aux.at(1)=mod;
    Matricula auxM{nM,lM};
    //Utilizamos los setter de la clase para hacer control de integridad de la informaciÃ³n encapsulada, ya que el constructor modifica el valor de los atributos.
    setMarcaModelo(aux);
    setMatricula(auxM);
    setnPlazas(pl);
    setnRuedas(r);
}
Vehiculo::Vehiculo(const Vehiculo &e)
{
    placa=e.placa;
    MarcaModelo=e.MarcaModelo;
    nRuedas=e.nRuedas;
    nPlazas=e.nPlazas;
}
//Destructor
Vehiculo::~Vehiculo()
{//Aunque "no haga nada" debemos definir el destructor si lo hemos declarado. Al igual que el resto de mÃ©todos de la clase. Si no... error :(

}

Vehiculo &Vehiculo::operator--() {
    placa.numero -= 1;
    return *this;
}

Vehiculo Vehiculo::operator++(int) {
    Vehiculo temp = *this;
    placa.numero++;
    return temp;
}
