#ifndef PRACTICA_3_FUNCIONES_H
#define PRACTICA_3_FUNCIONES_H

#include <iostream>
#include <limits>
#include "Vehiculo.h"
int menuTextual()
{
    int op{0};
    std::cout<< "Menu parking"<<std::endl;
    std::cout<< "1.-Salir"<<std::endl;
    std::cout<< "2.-Agregar vehiculo"<<std::endl;
    std::cout<< "3.-Sacar vehiculo"<<std::endl;
    std::cout<< "4.-Visualizar estado plazas"<<std::endl;

    std::cin>>op;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if(op<0 or op>4)
        return -1;
    else
        return op;
}

void AgregarVehiculo(int fila,int col,const Vehiculo& c,std::array<std::array<Vehiculo,6>,4> &p)
{
    if(fila<0 or col<0 or fila>p.size() or col>p.at(0).size())
    {
        throw string{"Plaza inexistente"};
    }
    else if(p.at(fila).at(col).getnPlazas()==0 and p.at(fila).at(col).getnRuedas()==0)
    {//Si la plaza estÃ¡ libre la podemos ocupar
        p.at(fila).at(col)=c;
    }
    else
    {
        throw std::string{"Plaza ocupada"};
    }
}

Vehiculo SacarVehiculo(int fila,int col, std::array<std::array<Vehiculo,6>,4> &p)
{
    if(fila<0 or col<0 or fila>p.size() or col>p.at(0).size())
    {
        throw string{"Plaza inexistente"};
    }
    else if(p.at(fila).at(col).getnPlazas()==0 and p.at(fila).at(col).getnRuedas()==0)
    {
        Vehiculo aux,retorno{p.at(fila).at(col)};

        p.at(fila).at(col)=aux;
        return retorno; //Por si quisieramos hacer algo con la informaciÃ³n del coche antes de sacarle del parking
    }
    else
    {
        throw std::string{"Plaza vacia"};
    }
}

void Mostrar(const std::array<std::array<Vehiculo,6>,4> &p)
{
    for(auto const &e:p)
    {
        for(auto const &v:e)
        {
            if(v.getnPlazas()==0 and v.getnRuedas()==0)
            {
                cout<<"Vacio ";
            }
            else
            {
                cout<<"Ocupado ";
            }
        }
        cout<<endl;
    }
}

Vehiculo PedirInfoCoche(void)
{
    Vehiculo aux;

    int auxINT1,auxINT2;
    string auxSTR1,auxSTR2;

    cout<<"Introduzca parte numerica de la matricula y parte literal separados por un espacio: ";
    cin>>auxINT1>>auxSTR1;
    Matricula mat{auxINT1,auxSTR1};

    cout<<"Introduzca el numero de plazas y ruedas del vehiculo separados por un espacio: ";
    cin>>auxINT1>>auxINT2;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout<<"Introduzca marca del vehiculo: ";
    //cin>>auxSTR;
    getline(std::cin,auxSTR1); //Por si la marca tuviera espacios...

    cout<<"Introduzca modelo del vehiculo: ";
    //cin>>auxSTR;
    getline(std::cin,auxSTR2); //Por si la marca tuviera espacios...

    try{//nPlazas,nRuedas,parte nÃºmerica matricula, marca vehÃ­culo, modelo v
        Vehiculo coche(auxINT1,auxINT2,mat.numero,mat.letras,auxSTR1,auxSTR2);

        return coche; //Si llegamos aquÃ­ es porque hemos podido crear el objeto coche
    }
    catch(int e)
    {
        cout<<"Excepcion controlada. Error: "<<e<<endl;
        cout<<"Vehiculo no vÃ¡lido"<<endl;
    }
    catch(...)
    {
        cout<<"Excepcion no contemplada"<<endl;
    }
}


#endif //PRACTICA_3_FUNCIONES_H
