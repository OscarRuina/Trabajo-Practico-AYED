#include "TiposMinerales.h"

bool CompararMinerales(TiposMinerales tipo1,TiposMinerales tipo2){
    if(tipo1!=tipo2){
        return false;
    }
    return true;
}

TiposMinerales traerTipo(int n){
    TiposMinerales tipo;
    switch(n){
        case 1:
            tipo = carbon;
            break;
        case 2 :
            tipo = bronce;
            break;
        case 3:
            tipo = plata;
            break;
        case 4:
            tipo = oro;
            break;
        case 5:
            tipo = platino;
            break;
        default:
            break;
    }
    return tipo;

}
