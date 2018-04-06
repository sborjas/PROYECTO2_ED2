//
// Created by Samuel Borjas on 7/9/2017.
//

#include "nodo.h"
#include <iostream>
#include <stdio.h>
#include <cstring>


nodo::nodo(int d, int nR) {
    dato = d;
    izquierdo = 0;
    derecho = 0;
    alturaDer = 0;
    alturaIz = 0;
    nRegistros = nR;
    f = 0;
}

char* nodo::toChar() {
    iz=false;
    der=false;
    int pos=0;
    char * data= new char[22];
    if(this->derecho!=0)
        der=true;
    if(this->izquierdo!=0)
        iz=true;
    memcpy(&data[pos],&dato,4);
    pos+=4;
    memcpy(&data[pos],&nRegistros,4);
    pos+=4;
    memcpy(&data[pos],&alturaIz,4);
    pos+=4;
    memcpy(&data[pos],&alturaDer,4);
    pos+=4;
    memcpy(&data[pos],&iz,1);
    pos+=1;
    memcpy(&data[pos],&der,1);
    pos+=1;
    memcpy(&data[pos],&f,4);
    pos+=4;
    return data;
}

void nodo::initFromChar(char *data) {
    int pos=0;
    memcpy(&dato,&data[pos],4);
    pos+=4;
    memcpy(&nRegistros,&data[pos],4);
    pos+=4;
    memcpy(&alturaIz,&data[pos],4);
    pos+=4;
    memcpy(&alturaDer,&data[pos],4);
    pos+=4;
    memcpy(&iz,&data[pos],1);
    pos+=1;
    memcpy(&der,&data[pos],1);
    pos+=1;
    memcpy(&f,&data[pos],4);
    pos+=4;
}

