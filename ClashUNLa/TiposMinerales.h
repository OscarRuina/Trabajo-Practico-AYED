#ifndef TIPOSMINERALES_H
#define TIPOSMINERALES_H

/*Definicion del tipo de datos ENUM para el manejo de tiposMinerales*/
 enum TiposMinerales{
    vacio = 0,
    carbon = 1,
    bronce = 2,
    plata = 3,
    oro = 4,
    platino = 5,
};
/*-----------------------------------*/
/*compara los minerales*/
bool CompararMinerales(TiposMinerales tipo1,TiposMinerales tipo2);
/*-----------------------------------*/
/*trae un tipo mineral*/
TiposMinerales traerTipo(int n);

#endif // TIPOSMINERALES_H
