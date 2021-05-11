#include "No.h"


No::No(int endereco):
endereco(endereco){
    this->fila = new Fila(TAMANHO_FILA);
}

No::~No(){
    delete this->fila;
}

Fila* No::getFila(){
    return this->fila;
}

int No::getEndereco(){
    return this->endereco;
}

void No::receber(Datagrama* d){
    bool recebido;
    try{
        this->fila->enqueue(d);
    } catch(overflow_error err){
        if(!recebido){
        cout << "\tFila em " << this->endereco << " estourou" << endl;
    }
    }
}

void No::imprimir(){
    
}