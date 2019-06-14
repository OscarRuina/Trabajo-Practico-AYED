#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <cstdlib>
#include "time.h"


//devuelve un numero aleatorio
int numeroRandom(int limiteSuperior){
    srand(time(NULL));
    int num = 1 + rand() % (limiteSuperior);
}

#endif // FUNCIONES_H
