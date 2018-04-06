//
// Created by Samuel Borjas on 7/9/2017.
//

#ifndef AVLARCHIVOS_DATAFILE_H
#define AVLARCHIVOS_DATAFILE_H
#include <cstdio>

class datafile {
public:
    datafile(char * dire);
    char * direccion;
    FILE * archivo;
    void abrir();
    void cerrar();
    void escribir(char * data,int pos,int longitud);
    char * leer(int pos,int longitud);
    bool isVacio();
    int getTam();

};


#endif //AVLARCHIVOS_DATAFILE_H
