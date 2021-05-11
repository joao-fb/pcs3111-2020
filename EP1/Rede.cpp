#include <iostream>
#include <string>
#include "Rede.h"
#include "Roteador.h"
#include "Datagrama.h"

using namespace std;



Rede::Rede(Roteador** roteadores, int quantidadeDeRoteadores):
roteadores(roteadores), quantidadeDeRoteadores(quantidadeDeRoteadores){

}

Rede::~Rede(){

}

Roteador* Rede::getRoteador(int endereco){
    Roteador* r=NULL;
    for(int i =0; i<this->quantidadeDeRoteadores; i++){
        if(this->roteadores[i]->getEndereco() == endereco){
            r = this->roteadores[i];
        }
    }
    if(r==NULL){
        cout << "Erro: origem desconhecida";
    }
    return r;
}

void Rede::enviar(string texto, Roteador* origem, int destino, int ttl){
    Datagrama* d = new Datagrama(origem->getEndereco(), destino, ttl, texto);
    origem->receber(d);
}

void Rede::passarTempo(){
    for(int i=0; i<this->quantidadeDeRoteadores; i++){
        this->roteadores[i]->processar();
    }
}

void Rede::imprimir(){

}