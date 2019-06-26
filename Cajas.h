#ifndef CAJAS_H
#define CAJAS_H


struct Caja{
    int cant;
};

void crearCajas(Caja &caja);
void eliminarCajas(Caja &caja);
void setCaja(Caja &caja,int cantidad);
int getCaja(Caja &caja);

#endif // CAJAS_H
