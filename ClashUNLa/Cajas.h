#ifndef CAJAS_H
#define CAJAS_H
/*Definicion del tipo de tipo de datos para el manejo de cajas*/
/*
Atributos:
cant: cantidad de cajas
usadas: cajas usadas
*/
/*Tipo de estructura de la estacion*/
struct Caja{
    int cant;
    int usadas;
};
/*------------------*/
/*
PRE: caja no debe haber sido creada
POST: caja creada
caja:instancia sobre la que actua la primitiva
*/
void crearCajas(Caja &caja);
/*------------------*/
/*
PRE: caja debe haber sido creada
POST: caja eliminada
caja:instancia sobre la que actua la primitiva
*/
void eliminarCajas(Caja &caja);
/*------------------*/
/*
PRE: caja  debe haber sido creada
POST: cantidad seteada
caja:instancia sobre la que actua la primitiva
cantidad: valor a setear
*/
void setCaja(Caja &caja,int cantidad);
/*------------------*/
/*
PRE: caja debe haber sido creada
POST: retorna el valor de cantidad
caja:instancia sobre la que actua la primitiva
*/
int getCaja(Caja &caja);
#endif // CAJAS_H
