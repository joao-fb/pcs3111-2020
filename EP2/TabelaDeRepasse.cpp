#include "TabelaDeRepasse.h"
#include <stdexcept>

using namespace std;

TabelaDeRepasse::TabelaDeRepasse(){
    this->enderecos = new int[MAXIMO_TABELA];
    this->adjacentes = new No* [MAXIMO_TABELA];
    this->padrao = NULL;
}

TabelaDeRepasse::~TabelaDeRepasse(){
    delete[] this->enderecos;
    delete[] this->adjacentes;
}

void TabelaDeRepasse::mapear(int endereco, No* adjacente){

    for(int i=0; i<this->slotDisponivel; i++){
        if(this->enderecos[i]==endereco){
            this->adjacentes[i]=adjacente;
        }
    }
    if(this->slotDisponivel < MAXIMO_TABELA){
        this->enderecos[this->slotDisponivel] = endereco;
        this->adjacentes[this->slotDisponivel] = adjacente;

        this->slotDisponivel += 1;

    }
    else{
        throw new overflow_error("Tabela de repasse já está cheia.");
    }
}

No** TabelaDeRepasse::getAdjacentes(){
    return this->adjacentes;
}

int TabelaDeRepasse::getQuantidadeDeAdjacentes(){
    return this->slotDisponivel;
}

void TabelaDeRepasse::setPadrao(No* padrao){
    this->padrao = padrao;
}

No* TabelaDeRepasse::getDestino(int endereco){
    No* r=this->padrao;
    
    for(int i=0; i<this->slotDisponivel; i++){
        if(this->enderecos[i]==endereco){
            r = this->adjacentes[i];
        }
    }
    return r;
}

void TabelaDeRepasse::imprimir(){

}
