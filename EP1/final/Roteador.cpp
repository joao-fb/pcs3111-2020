#include <iostream>
#include <string>
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "Fila.h"

using namespace std;

#define TAMANHO_FILA 3

Roteador::Roteador(int endereco):
endereco(endereco){
    this->tabelaDeRepasse = new TabelaDeRepasse();
    this->fila = new Fila(TAMANHO_FILA);
}

Roteador::~Roteador(){
    delete this->tabelaDeRepasse;
    delete this->fila;
}

TabelaDeRepasse* Roteador::getTabela(){
    return this->tabelaDeRepasse;
}

Fila* Roteador::getFila(){
    return this->fila;
}

int Roteador::getEndereco(){
    return this->endereco;
}

void Roteador::receber(Datagrama* d){
    bool recebido;
    recebido = this->fila->enqueue(d);

    if(!recebido){
        cout << "\tFila em " << this->endereco << " estourou" << endl;
    }
}

void Roteador::processar(){
    Datagrama* d;
    Roteador* rDestino;

    //Fila nao esta vazia
    if(!this->fila->isEmpty()){ 
        cout << "Roteador " << this->getEndereco() << endl;

        d = this->fila->dequeue();
        d->processar();

        if(d->getTtl() <= 0){
            cout << "\tDestruido por TTL: ";
            cout << "Origem: " << d->getOrigem() << ", Destino: " << d->getDestino();
            cout << ", TTL: " << d->getTtl() << " " << d->getDado() << endl;
            d->~Datagrama();
        } 
        //Dado nao esta desativado
        else{
            //Esse eh o roteador de destino
            if(d->getDestino()== this->endereco){
                this->ultimoDadoRecebido = d->getDado();
                cout << "\tRecebido: " << d->getDado() << endl;
                d->~Datagrama();
            }
            //Esse nao eh o roteador destino
            else{
                rDestino = this->tabelaDeRepasse->getDestino(d->getDestino());

                //Nao temos roteador na tabela
                if(rDestino == NULL){
                    d->~Datagrama();
                }
                //Temos o roteador na tabela
                else{
                    cout << "\tEnviado para " << rDestino->getEndereco() << " ";
                    cout << "Origem: " << d->getOrigem() << ", Destino: " << d->getDestino();
                    cout << ", TTL: " << d->getTtl() << ", " << d->getDado() << endl;
                    rDestino->receber(d);
                }
            }
        }
    }
}

string Roteador::getUltimoDadoRecebido(){
    return this->ultimoDadoRecebido;
}

void Roteador::imprimir(){

}
