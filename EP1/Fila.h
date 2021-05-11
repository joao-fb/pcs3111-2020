#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>
#include "Datagrama.h"

using namespace std;

class Fila{
    public:
        Fila(int tamanho);
        ~Fila();
        bool enqueue(Datagrama* d);
        Datagrama* dequeue();
        bool isEmpty();
        void imprimir();

    private:
        int tamanho;
        int inicio=0;
        int cauda=0;
        int count=0;
        Datagrama** fila;
};

#endif