#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>
#include "Datagrama.h"

using namespace std;

class Fila{
    public:
        Fila(int tamanho);
        virtual ~Fila();
        virtual void enqueue(Datagrama* d);
        virtual Datagrama* dequeue();
        virtual bool isEmpty();
        virtual void imprimir();

    private:
        int tamanho;
        int inicio=0;
        int cauda=0;
        int count=0;
        Datagrama** fila;
};

#endif