#include <iostream>
#include "Fila.h"
#include "Datagrama.h"
#include <string>

using namespace std;

Fila::Fila(int tamanho):
tamanho(tamanho){
    this->fila = new Datagrama* [tamanho];
}

Fila::~Fila(){
    delete this->fila;
}

bool Fila::enqueue(Datagrama* d){
    if(this->count != this->tamanho){
        this->fila[this->cauda] = d;
        if(this->cauda==this->tamanho-1){
            this->cauda = 0;
        }
        else{
            this->cauda += 1;
        }
        this->count += 1;
        return true;
    }
    else{
        return false;
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
        d = NULL;
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