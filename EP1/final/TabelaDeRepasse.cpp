#include <iostream>
#include <string>
#include "TabelaDeRepasse.h"
#include "Roteador.h"

using namespace std;

#define MAXIMO_TABELA 5

TabelaDeRepasse::TabelaDeRepasse(){
    this->enderecos = new int[MAXIMO_TABELA];
    this->adjacentes = new Roteador* [MAXIMO_TABELA];
    this->padrao = NULL;
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete this->enderecos;
    delete this->adjacentes;
}

bool TabelaDeRepasse::mapear(int endereco, Roteador* adjacente){
    int i;
    for(i=0; i<this->slotDisponivel; i++){
        if(this->enderecos[i]==endereco){
            this->adjacentes[i]=adjacente;
            return true;
        }
    }
    if(this->slotDisponivel <= MAXIMO_TABELA){
        this->enderecos[this->slotDisponivel] = endereco;
        this->adjacentes[this->slotDisponivel] = adjacente;

        this->slotDisponivel += 1;

        return true;
    }
    else{
        return false;
    }
}

Roteador** TabelaDeRepasse::getAdjacentes(){
    return this->adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return this->slotDisponivel;
}

void TabelaDeRepasse::setPadrao(Roteador* padrao){
    this->padrao = padrao;
}

Roteador* TabelaDeRepasse::getDestino(int endereco){
    int i;
    Roteador* r=this->padrao;
    
    for(i=0; i<this->slotDisponivel; i++){
        if(this->enderecos[i]==endereco){
            r = this->adjacentes[i];
        }
    }
    return r;
}

void TabelaDeRepasse::imprimir(){

}
