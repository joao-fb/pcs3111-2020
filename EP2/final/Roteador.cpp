#include <iostream>
#include <string>
#include "Roteador.h"

using namespace std;


Roteador::Roteador(int endereco):
No(endereco){
    this->tabelaDeRepasse = new TabelaDeRepasse();
}

Roteador::~Roteador(){
    delete this->tabelaDeRepasse;
}

void Roteador::processar(){
    Datagrama* d;
    No* noDestino;

    //Fila nao esta vazia
    if(!this->fila->isEmpty()){ 
        cout << "Roteador " << this->getEndereco() << endl;

        d = this->fila->dequeue();
        d->processar();

        if(d->getTtl() <= 0){
            cout << "\tDestruido por TTL: ";
            cout << "Origem: " << d->getOrigem() << ":"  << d->getDado()->getPortaDeOrigem();
            cout << ", Destino: " << d->getDestino() << ":"  << d->getDado()->getPortaDeDestino();
            cout << ", TTL: " << d->getTtl() << ", " << d->getDado()->getDado() << endl;
            d->~Datagrama();
        } 
        //Dado nao esta desativado
        else{
            //Esse eh o roteador de destino
            if(d->getDestino()== this->endereco){
                cout << "\tRecebido: ";
                cout << "Origem: " << d->getOrigem() << ":"  << d->getDado()->getPortaDeOrigem();
                cout << ", Destino: " << d->getDestino() << ":"  << d->getDado()->getPortaDeDestino();
                cout << ", TTL: " << d->getTtl() << ", " << d->getDado()->getDado() << endl;
                d->~Datagrama();
            }
            //Esse nao eh o roteador destino
            else{
                noDestino = this->tabelaDeRepasse->getDestino(d->getDestino());

                //Nao temos roteador na tabela
                if(noDestino == NULL){
                    cout << "\tSem proximo: ";
                    cout << "Origem: " << d->getOrigem() << ":"  << d->getDado()->getPortaDeOrigem();
                    cout << ", Destino: " << d->getDestino() << ":"  << d->getDado()->getPortaDeDestino();
                    cout << ", TTL: " << d->getTtl() << ", " << d->getDado()->getDado() << endl;
                    d->~Datagrama();
                }
                //Temos o roteador na tabela
                else{
                    cout << "\tEnviado para " << noDestino->getEndereco() << " ";
                    cout << "Origem: " << d->getOrigem() << ":"  << d->getDado()->getPortaDeOrigem();
                    cout << ", Destino: " << d->getDestino() << ":"  << d->getDado()->getPortaDeDestino();
                    cout << ", TTL: " << d->getTtl() << ", " << d->getDado()->getDado() << endl;
                    noDestino->receber(d);
                }
            }
        }
    }
}

TabelaDeRepasse* Roteador::getTabela(){
    return this->tabelaDeRepasse;
}
