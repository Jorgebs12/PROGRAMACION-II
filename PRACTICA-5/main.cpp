#include <iostream>
#include <vector>
#include <memory>
#include "Mago.h"
#include "Barbaro.h"
#include "Horda.h"
#include "Templates.h"

int main() {

    Mago mago1("Pepe", 100,200,300);
    Mago mago2("Paco", 200,300,400);

    Barbaro barbaro1("Manolo", 489,1295,6452);
    Barbaro barbaro2("Ezequiel", 546,7954,5000);


    //SOBRECARGA <<
    vector<Mago> misMagos;
    misMagos.push_back(mago1);
    misMagos.push_back(mago2);

    Horda miHordaMagos(misMagos);
    cout << "Mi horda de magos son: " << miHordaMagos << endl;

    vector<Barbaro> misBarbaros;
    misBarbaros.push_back(barbaro1);
    misBarbaros.push_back(barbaro2);

    Horda miHordaBarbaros(misBarbaros);
    cout << "Mi horda de magos son: " << miHordaBarbaros << endl;

    //ENCONTRAR PERSONAJE
    cout << "Se ha encontrado el nombre?: " << EncontrarPersonaje(miHordaMagos,"Pepe") << endl << endl;



    //APARTADO 5
    shared_ptr<Mago> miMagoPuntero = make_shared<Mago>(Mago("Nano", 2,33,14));
    shared_ptr<Barbaro> miBarbaroPuntero = make_shared<Barbaro>(Barbaro("Cholo", 88,14,200000));
    shared_ptr<Personaje> miPersonajePuntero = make_shared<Personaje>(Personaje("Gargamel", 88,14));

    vector<shared_ptr<Mago>> miVectorPunteroMagos;
    vector<shared_ptr<Barbaro>> miVectorPunteroBarbaros;
    vector<shared_ptr<Personaje>> miVectorPunteroPersonajes;

    Horda<shared_ptr<Mago>> hordaMagos(miVectorPunteroMagos);
    Horda<shared_ptr<Barbaro>> hordaBarbaro(miVectorPunteroBarbaros);
    Horda<shared_ptr<Personaje>> hordaPersonaje(miVectorPunteroPersonajes);

    return 0;
}
