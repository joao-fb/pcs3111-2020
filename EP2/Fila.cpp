#include <iostream>
#include <string>
#include <stdexcept>

#include "Fila.h"
#include "Datagrama.h"


using namespace std;

Fila::Fila(int tamanho):
tamanho(tamanho){
    this->fila = new Datagrama* [tamanho];
}

Fila::~Fila(){
    delete[] this->fila;
}

void Fila::enqueue(Datagrama* d){
    if(this->count != this->tamanho){
        this->fila[this->cauda] = d;
        if(this->cauda==this->tamanho-1){
            this->cauda = 0;
        }
        else{
            this->cauda += 1;
        }
        this->count += 1;
    }
    else{
        throw new overflow_error("A fila já está cheia!");
    }
    
}

Datagrama* Fila::dequeue(){
    Datagrama* d;

    if(this->count!=0){
        d = this->fila[this->inicio];
        if(this->inicio==this->tamanho-1){
            this->inicio=0;
        }
        else{
            this->inicio += 1;
        }
        this->count-=1;
    }
    else{
        throw new underflow_error("A fila está vazia!");
    }

    return d;
}

bool Fila::isEmpty(){
    return this->count==0;
}

void Fila::imprimir(){
    cout << "Incio: " << this->inicio << endl;
    cout << "Cauda: " << this->cauda << endl;
    cout << "Tamanho: " << this->tamanho << endl;
    cout << "Count: " << this->count << endl;
}