#include <iostream>
#include "datafile.h"
#include "avlarbol.h"

int main() {

    int contador = 0;
    datafile * archivo = new datafile("Indices.data");
    archivo->abrir();

    avlarbol * arbol = new avlarbol(archivo);
    arbol->insertar(10,0);
    arbol->insertar(5,0);
    arbol->insertar(13,0);
    arbol->insertar(1,0);
    arbol->insertar(6,0);
    arbol->insertar(16,0);
    arbol->insertar(17,0);

    //std::cout<< arbol->buscar(3)->dato;

    std::cout<<"===== PRE ORDEN======\n";
    arbol->preOrden(arbol->raiz);
    std::cout<<"===== IN ORDEN======\n";
    arbol->inOrden(arbol->raiz);
    std::cout<<"===== POST ORDEN======\n";
    arbol->postOrden(arbol->raiz);

    std::cout<<"===== IMPRIMIENDO ARBOL======\n";
    arbol->imprimirArbol(arbol->raiz,contador);

    //arbol->escribir();

    //arbol->buscar(10);
    //archivo->getTam();
    //archivo->cerrar();

    return 0;
}