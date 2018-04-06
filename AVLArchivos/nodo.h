//
// Created by Samuel Borjas on 7/9/2017.
//

#ifndef AVLARCHIVOS_NODO_H
#define AVLARCHIVOS_NODO_H


class nodo {
public:
    nodo(int d,int nR);
    nodo *padre;
    nodo *izquierdo;
    nodo *derecho;
    int dato;
    /*
     * char name[30];
     * char lastname[30];
     * char credit_card[25];
     * char date[12];
     * short int day;
     * short int month;
     * short int year;
     * char payment_type[10]
     * double total;
     * char business_type[20]
     * char business_name[50]
     */
    int alturaIz;
    int alturaDer;
    bool iz;
    bool der;
    int f;
    int nRegistros;
    char *toChar();
    void initFromChar(char *data);

};


#endif //AVLARCHIVOS_NODO_H
