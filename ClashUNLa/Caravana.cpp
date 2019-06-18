#include "Caravana.h"

/******************************************************************************/
/* Definición de Tipos de Datos para manejo interno */
/*--------------------------------------------------*/


/******************************************************************************/
/* Funciones Adicionales */
/*-----------------------*/

/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/


/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

/*
  pre : la caravana no debe haber sido creada.
  post: caravana queda creada y preparada para ser usada.

  caravana : estructura de datos a ser creado.
*/
void crearCaravana(Caravana &caravana) {
  caravana.primero = fin();
}

/*
  pre : caravana Creada con crearLista().
  post: Devuelve true si caravana esta vacia, sino devuelve false.

  caravana : caravana sobre la cual se invoca la primitiva.
*/
bool caravanaVacia(Caravana &caravana) {

  return (primero(caravana) == fin());
}

/*
  pre : caravana Creada con crearLista().
  post: devuelve la representacion de lo Siguiente al último Nodo de la caravana,
        o sea el valor Null, que en esta implementacion representa el final de
        la caravana.

  return representación del fin de la caravana.
*/
PtrNodoCaravana fin() {
  return NULL;
}

/*
  pre : caravana Creada con crearLista().
  post: devuelve el puntero al primer elemento de la caravana, o devuelve fin() si
        esta vacia

  caravana : caravana sobre la cual se invoca la primitiva.
  return puntero al primer nodo.
*/
PtrNodoCaravana primero(Caravana &caravana) {
  return caravana.primero;
}

/*
  pre : caravana Creada con crearLista().
  post: devuelve el puntero al nodo proximo del apuntado, o devuelve fin() si
        ptrNodo apuntaba a fin() o si caravana esta vacia.

  caravana : caravana sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el siguiente.
  return puntero al nodo siguiente.
*/
PtrNodoCaravana siguiente(Caravana &caravana, PtrNodoCaravana ptrNodo) {

  /* verifica si la caravana está vacia o si ptrNodo es el último */
  if ((! caravanaVacia(caravana)) && (ptrNodo != fin()))
    return ptrNodo->sgte;
  else
    return fin();
}

/*
  pre : caravana Creada con crearLista().
        ptrNodo es un puntero a un nodo de caravana.
  post: devuelve el puntero al nodo anterior del apuntado, o devuelve fin() si
        ptrNodo apuntaba al primero o si caravana esta vacia.

  caravana : caravana sobre la cual se invoca la primitiva.
  prtNodo : puntero al nodo a partir del cual se requiere el anterior.
  return puntero al nodo anterior.
*/
PtrNodoCaravana anterior(Caravana &caravana, PtrNodoCaravana ptrNodo) {

  PtrNodoCaravana ptrPrevio = fin();
  PtrNodoCaravana ptrCursor = primero(caravana);

  while (( ptrCursor != fin()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(caravana,ptrCursor);
  }
  return ptrPrevio;
}

/*
  pre : caravana creada con crearLista().
  post: devuelve el puntero al ultimo nodo de la caravana, o devuelve fin() si
        si caravana esta vacia.

  caravana : caravana sobre la cual se invoca la primitiva.
  return puntero al último nodo.
*/
PtrNodoCaravana ultimo(Caravana &caravana) {

  /* el último nodo de la caravana es el anterior al fin() */
  return anterior(caravana,fin());
}

/*----------------------------------------------------------------------------*/
PtrNodoCaravana crearNodoLista(Dato dato) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoCaravana ptrAux = new NodoCaravana;

  ptrAux->dato = dato;
  ptrAux->sgte = fin();

  return ptrAux;
}

/*
  pre : caravana creada con crearLista().
  post: agrega un nodo nuevo al principio de la caravana con el dato proporcionado
        y devuelve un puntero a ese elemento.

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al principio de la caravana.
  return puntero al nodo adicionado.
*/
PtrNodoCaravana adicionarPrincipio(Caravana &caravana, Dato dato) {

  /* crea el nodo */
  PtrNodoCaravana ptrNuevoNodo = crearNodoLista(dato);

  /* lo incorpora al principio de la caravana */
  ptrNuevoNodo->sgte = caravana.primero;
  caravana.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}

/*
  pre : caravana creada con crearLista().
  post: agrega un nodo despues del apuntado por ptrNodo con el dato
        proporcionado y devuelve un puntero apuntado al elemento insertado.
        Si la caravana esta vacía agrega un nodo al principio de esta y devuelve
        un puntero al nodo insertado. Si ptrNodo apunta a fin() no inserta
        nada y devuelve fin().

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo después del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoCaravana adicionarDespues(Caravana &caravana, Dato dato, PtrNodoCaravana ptrNodo) {

  PtrNodoCaravana ptrNuevoNodo = fin();

  /* si la caravana está vacia se adiciona la principio */
  if (caravanaVacia(caravana))
    ptrNuevoNodo = adicionarPrincipio(caravana,dato);

  else {
    if (ptrNodo != fin()) {

      /* crea el nodo y lo intercala en la caravana */
      ptrNuevoNodo = crearNodoLista(dato);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*
  pre : caravana creada con crearLista().
  post: agrega un nodo al final de la caravana con el dato proporcionado y devuelve
        un puntero al nodo insertado.

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a adicionar al final de la caravana.
  return puntero al nodo adicionado.
*/
PtrNodoCaravana adicionarFinal(Caravana &caravana, Dato dato) {

  /* adiciona el dato después del último nodo de la caravana */
  return adicionarDespues(caravana,dato,ultimo(caravana));
}

/*
  pre : caravana creada con crearLista().
  post: agrega un nodo con el dato proporcionado antes del apuntado por ptrNodo
        y devuelve un puntero al nodo insertado. Si la caravana esta vacia no
        inserta nada y devuelve fin(). Si ptrNodo apunta al primero, el nodo
        insertado sera el nuevo primero.

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a adicionar.
  ptrNodo : puntero al nodo antes del cual se quiere adicionar el dato.
  return puntero al nodo adicionado.
*/
PtrNodoCaravana adicionarAntes(Caravana &caravana, Dato dato, PtrNodoCaravana ptrNodo) {

  PtrNodoCaravana ptrNuevoNodo = fin();

  if (! caravanaVacia(caravana)) {
    if (ptrNodo != primero(caravana))
      ptrNuevoNodo = adicionarDespues(caravana,dato,anterior(caravana,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(caravana,dato);
   }
   return ptrNuevoNodo;
}

/*
  pre : caravana creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  post: coloca el dato proporcionado en el nodo apuntado por ptrNodo.

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a colocar.
  ptrNodo : puntero al nodo del cual se quiere colocar el dato.
*/
void colocarDato(Caravana &caravana, Dato &dato, PtrNodoCaravana ptrNodo) {

  if ( (! caravanaVacia(caravana)) && (ptrNodo != fin()))
    ptrNodo->dato = dato;
}

/*
  pre : caravana creada con crearLista(), no vacia. ptrNodo es distinto de fin().
  post: devuelve el dato del nodo apuntado por ptrNodo.

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento obtenido.
  ptrNodo : puntero al nodo del cual se quiere obtener el dato.
*/
void obtenerDato(Caravana &caravana, Dato &dato, PtrNodoCaravana ptrNodo) {

  if ((! caravanaVacia(caravana)) && (ptrNodo != fin()))
    dato = ptrNodo->dato;
}

/*
  pre : caravana creada con crearLista().
  post: elimina el nodo apuntado por ptrNodo. No realiza accion si la caravana
        esta vacia o si ptrNodo apunta a fin().

  caravana : caravana sobre la cual se invoca la primitiva.
  ptrNodo : puntero al nodo que se desea eliminar.
*/
void eliminarNodo(Caravana &caravana, PtrNodoCaravana ptrNodo) {

  PtrNodoCaravana ptrPrevio;

  /* verifica que la caravana no esté vacia y que nodo no sea fin*/
  if ((! caravanaVacia(caravana)) && (ptrNodo != fin())) {

    if (ptrNodo == primero(caravana))
      caravana.primero = siguiente(caravana,primero(caravana));

    else {
      ptrPrevio = anterior( caravana , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*...*/
void eliminarNodoPrimero(Caravana &caravana) {

  if (! caravanaVacia(caravana))
    eliminarNodo(caravana,primero(caravana));
}

/*...*/
void eliminarNodoUltimo(Caravana &caravana) {

  if (! caravanaVacia(caravana))
    eliminarNodo(caravana,ultimo(caravana));
}

/*
  pre : caravana creada con crearLista().
  post: elimina todos los Nodos de la caravana quedando destruida e inhabilitada
        para su uso.

  caravana : caravana sobre la cual se invoca la primitiva.
*/
void eliminarLista(Caravana &caravana) {

  /* retira uno a uno los nodos de la caravana */
  while (! caravanaVacia(caravana))
    eliminarNodo(caravana,primero(caravana));
}
/* Definición de Operaciones Adicionales */
/*---------------------------------------*/

/*
  pre : caravana fue creada con crearLista().
  post: si el dato se encuentra en la caravana, devuelve el puntero al primer nodo
        que lo contiene. Si el dato no se encuentra en la caravana devuelve fin().

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a localizar.
  return puntero al nodo localizado o fin().
*/
PtrNodoCaravana localizarDato(Caravana &caravana, Dato dato) {

   bool encontrado = false;
   Dato datoCursor;
   PtrNodoCaravana ptrCursor = primero(caravana);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != fin()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(caravana,datoCursor,ptrCursor);
    if (compararTren(datoCursor,dato) == 0)
      encontrado = true;
    else
      ptrCursor = siguiente(caravana,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = fin();

  return ptrCursor;
}

/*
  pre : la caravana fue creada con crearLista().
  post : elimina el dato de la caravana, si el mismo se encuentra.

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a eliminar.
*/
void eliminarDato(Caravana &caravana, Dato dato) {

  /* localiza el dato y luego lo elimina */
  PtrNodoCaravana ptrNodo = localizarDato(caravana,dato);
  if (ptrNodo != fin())
    eliminarNodo(caravana,ptrNodo);
}

/*
  pre : caravana fue creada con crearLista() y cargada con datos ordenados de
        menor a mayor respecto del sentido progresivo.
  post: agrega a la caravana el dato manteniendo el orden pero con multiples
        valores iguales y devuelve un puntero al nodo insertado.

  caravana : caravana sobre la cual se invoca la primitiva.
  dato : elemento a insertar.
  return puntero al nodo insertado.
*/
PtrNodoCaravana insertarDato(Caravana &caravana, Dato dato) {

  PtrNodoCaravana ptrPrevio = primero(caravana);
  PtrNodoCaravana ptrCursor = primero(caravana);
  PtrNodoCaravana ptrNuevoNodo;
  Dato datoCursor;
  bool ubicado = false;


  while ((ptrCursor != fin()) && (! ubicado)) {

    obtenerDato(caravana,datoCursor,ptrCursor);
    if (compararTren(datoCursor,dato) == MAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(caravana,ptrCursor);
    }
  }

  if (ptrCursor == primero(caravana))
    ptrNuevoNodo = adicionarPrincipio(caravana,dato);
  else
    ptrNuevoNodo = adicionarDespues(caravana,dato,ptrPrevio);

  return ptrNuevoNodo;
}

/*
  pre : la caravana fue creada con crearLista().
  post : reordena la caravana.

  caravana : caravana sobre la cual se invoca la primitiva.
*/


/*
  pre : la caravana fue creada con crearLista().
  post : devuelve la cantidad de datos que tiene la caravana.

  caravana : caravana sobre la cual se invoca la primitiva.
*/
int longitud(Caravana &caravana){
  PtrNodoCaravana ptrCursor = primero(caravana);
  int longitud = 0;
  while ( ptrCursor != fin() ) {
        longitud++;
        ptrCursor = siguiente( caravana, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/
