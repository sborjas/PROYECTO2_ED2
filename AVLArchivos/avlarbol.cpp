//
// Created by Samuel Borjas on 10/9/2017.
//

#include "avlarbol.h"
#include <iostream>
#include <cstring>

using namespace std;

avlarbol::avlarbol(datafile *a){
    raiz=0;
    cant=0;
    a = archivo;
}


void avlarbol::insertar(int valor, int nr){
    nodo * n=new nodo(valor,nr);
    agregar(n);
    cant++;
}

void avlarbol::agregar(nodo * n) {
    if(raiz==0)
        raiz=n;
    else
        raiz=insertar(raiz,n);
}


nodo * avlarbol::insertar(nodo *&sraiz,nodo * n) {
    nodo * nuevoPadre=sraiz;
    if(n->dato < sraiz->dato) {
        if(sraiz->izquierdo==0)
            sraiz->izquierdo=n;
        else {
            sraiz->izquierdo=insertar(sraiz->izquierdo,n);
            if((obtenerFE(sraiz->izquierdo))-obtenerFE(sraiz->derecho) ==2) {
                if(n->dato<sraiz->izquierdo->dato)
                    nuevoPadre=rotacionDerecha(sraiz);
                else
                    nuevoPadre=rotacionDDerecha(sraiz);
            }
        }

    }
    else if(n->dato>sraiz->dato) {
        if(sraiz->derecho==0)
            sraiz->derecho=n;
        else {
            sraiz->derecho=insertar(sraiz->derecho,n);
            if((obtenerFE(sraiz->derecho))-obtenerFE(sraiz->izquierdo) ==2) {
                if(n->dato>sraiz->derecho->dato)
                    nuevoPadre=rotacionIzquierda(sraiz);
                else
                    nuevoPadre=rotacionDIzquierda(sraiz);
            }
        }
    }
    else
        cout<<"Nodo Duplicado"<<endl;

    if(sraiz->izquierdo==0 && sraiz->derecho!=0) {
        sraiz->f=sraiz->derecho->f+1;
    }
    else if( sraiz->derecho==0 &&sraiz->izquierdo!=0 ) {
        sraiz->f=sraiz->izquierdo->f+1;
    }
    else {
        int a=obtenerFE(sraiz->izquierdo);
        int b=obtenerFE(sraiz->derecho);
        sraiz->f= a >b ? a+1:b+1;
    }
    return nuevoPadre;
}


nodo * avlarbol::buscar(int v) {
    return buscarAux(v,raiz);
}


nodo * avlarbol::buscarAux(int v,nodo *&r) {
    if(r==0)
        return 0;
    else if(r->dato==v)
    {
        return r;
    }
    else if(r->dato>v)
        return buscarAux(v,r->izquierdo);
    return buscarAux(v,r->derecho);
}


int avlarbol::obtenerFE(nodo * n) {
    if(n==0) {
        return -1;
    }
    else {
        return n->f;
    }
}

nodo * avlarbol::rotacionIzquierda(nodo *r) {
    nodo * hijoDer=r->derecho;
    r->derecho=hijoDer->izquierdo;
    hijoDer->izquierdo=r;
    int c=obtenerFE(r->izquierdo);
    int d=obtenerFE(r->derecho);
    r->f=(c>d ? c:d)+1;
    int a=obtenerFE(hijoDer->izquierdo);
    int b=obtenerFE(hijoDer->derecho);
    hijoDer->f= (a>b ? a:b)+1;
    return hijoDer;
}

nodo* avlarbol::rotacionDerecha(nodo *r) {
    nodo * hijoIz=r->izquierdo;
    r->izquierdo=hijoIz->derecho;
    hijoIz->derecho=r;
    int c=obtenerFE(r->izquierdo);
    int d=obtenerFE(r->derecho);
    r->f=(c>d ? c:d)+1;
    int a=obtenerFE(hijoIz->izquierdo);
    int b=obtenerFE(hijoIz->derecho);
    hijoIz->f= (a>b ? a:b)+1;
    return hijoIz;
}

nodo * avlarbol::rotacionDIzquierda(nodo *r) {
    nodo * tmp;
    r->izquierdo=rotacionDerecha(r->derecho);
    tmp=rotacionIzquierda(r);
    return tmp;
}

nodo * avlarbol::rotacionDDerecha(nodo *r) {
    nodo * tmp;
    r->izquierdo=rotacionIzquierda(r->izquierdo);
    tmp=rotacionDerecha(r);
    return tmp;
}

char * avlarbol::toChar() {
    int pos=0;
    char * entry_data= new char[22*cant];
    return toCharAux(raiz,pos,entry_data);
}

char * avlarbol::toCharAux(nodo *&r,int pos,char * data) {
    if(r==0)
        return data;
    char * data_entry= r->toChar();
    memcpy(&data[pos],data_entry,22);
    pos+=22;
    toCharAux(r->izquierdo,pos,data);
    toCharAux(r->derecho,pos,data);
}

//=====CARGAR DESDE ARCHIVO======================

void avlarbol::initFromChar(char * data) {
    int pos=0;
    nodo * r=initAux(data,pos);
    agregar(r);
}

nodo * avlarbol::initAux(char * data,int pos) {
    char * data_entry= new char[192];
    memcpy(data_entry,&data[pos],22);
    nodo * r=new nodo(0,0);
    r->initFromChar(data_entry);
    pos+=22;
    if(r->iz)
        r->izquierdo=initAux(data,pos);
    else
        r->izquierdo=0;
    if(r->der)
        r->derecho=initAux(data,pos);
    else
        r->derecho=0;
    return r;
}

//=====CARGAR DESDE ARCHIVO FIN DE LA FUNCION================

void avlarbol::escribir() {
    char * data= this->toChar();
    int tam= cant*22;
    archivo->escribir(data,0,tam);
}

void avlarbol::cargar() {
    int tam=archivo->getTam();
    char * data=archivo->leer(0,tam);
    initFromChar(data);
    cant=tam/22;
}

void avlarbol::preOrden(nodo *r) {
    if(r!=NULL){
        cout<<" "<<r->dato<<endl;
        preOrden(r->izquierdo);
        preOrden(r->derecho);
    }
    /*
    if(r==0) return;
    cout << r->dato<<endl;
    preOrden(r->izquierdo);
    preOrden(r->derecho);
     */
}

void avlarbol::postOrden(nodo *r){
    if(r!=NULL){
        postOrden(r->izquierdo);
        postOrden(r->derecho);
        cout<<r->dato<<" "<<endl;
    }
}

void avlarbol::inOrden(nodo *r){
    if(r!=NULL){
        inOrden(r->izquierdo);
        cout<<r->dato<<" "<<endl;
        inOrden(r->derecho);
    }
}

void avlarbol::imprimirArbol(nodo *r, int contador) {
    if(r == NULL){
        return;
    }else{
        imprimirArbol(r->derecho,contador+1);
        for(int x=0;x<contador;x++){
            cout<<"  ";
        }
        cout<<r->dato<<endl;
        imprimirArbol(r->izquierdo,contador+1);
    }
}


//FUNCIONES PARA ELIMINAR NODO DE UN ARBOL
nodo *avlarbol::minimo(nodo *arbol){
    if(arbol==NULL){
        return NULL;
    }
    if(arbol->izquierdo){
        return minimo(arbol->izquierdo);
    }else{
        return arbol;
    }
}

void avlarbol::reemplazar(nodo *arbolviejo,nodo *arbolnuevo){
    if(arbolviejo->padre){
        if(arbolviejo->dato==arbolviejo->padre->izquierdo->dato){
            arbolviejo->padre->izquierdo = arbolnuevo;
        }else if(arbolviejo->dato==arbolviejo->padre->derecho->dato){
            arbolviejo->padre->derecho = arbolnuevo;
        }
    }
    if(arbolnuevo){
        arbolnuevo->padre = arbolviejo->padre;
    }
}

void avlarbol::destruir(nodo *arbol){
    arbol->izquierdo = NULL;
    arbol->derecho = NULL;
    delete arbol;
}

void avlarbol::eliminarNodo(nodo *arbol){
    if(arbol->izquierdo && arbol->derecho){
        nodo *menor = minimo(arbol->derecho);
        arbol->dato =  menor->dato;
        eliminarNodo(menor);
    }else if(arbol->izquierdo){
        reemplazar(arbol,arbol->izquierdo);
        destruir(arbol);
    }else if(arbol->derecho){
        reemplazar(arbol,arbol->derecho);
        destruir(arbol);
    }else{
        reemplazar(arbol,NULL);
        destruir(arbol);
    }
}

void avlarbol::eliminar(nodo *arbol,int dato){
    nodo * nuevoPadre=arbol;
    if(arbol==NULL){
        return;
    }else if(dato < arbol->dato){
        eliminar(arbol->izquierdo,dato);
        if((obtenerFE(arbol->derecho))-obtenerFE(arbol->izquierdo) ==2) {
            if(dato>arbol->derecho->dato)
                nuevoPadre=rotacionIzquierda(arbol);
            else
                nuevoPadre=rotacionDIzquierda(arbol);
        }
    }else if(dato>arbol->dato){
        eliminar(arbol->derecho,dato);
        if((obtenerFE(arbol->derecho))-obtenerFE(arbol->izquierdo) ==2) {
            if(dato>arbol->derecho->dato)
                nuevoPadre=rotacionIzquierda(arbol);
            else
                nuevoPadre=rotacionDIzquierda(arbol);
        }
    }else{
        eliminarNodo(arbol);
    }
}
//FIN

