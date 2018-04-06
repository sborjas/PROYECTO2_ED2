//
// Created by Samuel Borjas on 10/9/2017.
//

#ifndef AVLARCHIVOS_AVLARBOL_H
#define AVLARCHIVOS_AVLARBOL_H


#include "datafile.h"
#include "nodo.h"

class avlarbol {
public:
    avlarbol(datafile *archivo);
    datafile *archivo;
    nodo *raiz;
    void insertar(int valor, int nr);
    void agregar(nodo *nodo);
    nodo * insertar(nodo *&sraiz,nodo * n);
    nodo * buscarAux(int v,nodo *&r);
    nodo * buscar(int v);
    int obtenerFE(nodo * n);
    nodo * rotacionIzquierda(nodo *r);
    nodo * rotacionDerecha(nodo *r);
    nodo * rotacionDIzquierda(nodo *r);
    nodo * rotacionDDerecha(nodo *r);
    char * toChar();
    char * toCharAux(nodo *&r,int pos,char * data);
    void initFromChar(char * data);
    nodo * initAux(char * data,int pos);
    void cargar();
    void escribir();
    int cant;
    void preOrden(nodo *r);
    void inOrden(nodo *r);
    void postOrden(nodo *r);
    void imprimirArbol(nodo *r, int contador);
    nodo *minimo(nodo *r);
    void reemplazar(nodo *viejo, nodo *nuevo);
    void destruir(nodo *r);
    void eliminarNodo(nodo *r);
    void eliminar(nodo *r,int dato);


};


#endif //AVLARCHIVOS_AVLARBOL_H
