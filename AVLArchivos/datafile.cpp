//
// Created by Samuel Borjas on 7/9/2017.
//

#include "datafile.h"
#include <io.h>
#include <stdlib.h>
#include <cstring>
#include <stdio.h>
#include <iostream>
using namespace std;

datafile::datafile(char *dire) {
    direccion = dire;
    if( (_access( dire, 0 )) == -1 ){
        archivo=fopen(dire,"wb+");
        cerrar();
    }
}

void datafile::abrir(){
    archivo=fopen(direccion,"rb+");
}

void datafile::cerrar() {
    fclose(archivo);
}

void datafile::escribir(char * data,int pos,int longitud){
    fseek(archivo,pos,SEEK_SET);
    fwrite(data, 1,longitud,archivo);
}

char * datafile::leer(int pos,int longitud) {
    char *data=new char[longitud];
    fseek(archivo,pos,SEEK_SET);
    fread(data,1, longitud,archivo);
    return data;
}

bool datafile::isVacio() {
    fseek(archivo,0,SEEK_END);
    return ftell(archivo)>0 ? false:true;
}

int datafile::getTam() {
    fseek(archivo,0,SEEK_END);
    return ftell(archivo);
}