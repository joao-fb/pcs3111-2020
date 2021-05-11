#include "Hospedeiro.h"
#include "ServidorWeb.h"
#include "Navegador.h"

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway):
No(endereco), endereco(endereco), gateway(gateway){
    this->processos = new vector<Processo*>();
}

Hospedeiro::~Hospedeiro(){

    delete this->processos;
}

void Hospedeiro::adicionarServidorWeb(int porta, string conteudo){
    for(unsigned int i=0; i<this->processos->size(); i++){
        if(this->processos->at(i)->getPorta() == porta){
            throw new logic_error("Processo já adicionado na porta");
        }
    }

    ServidorWeb* sw = new ServidorWeb(this->endereco, porta, this->gateway, conteudo);
    this->processos->push_back(sw);
}

void Hospedeiro::adicionarNavegador(int porta){
    for(unsigned int i=0; i<this->processos->size(); i++){
        if(this->processos->at(i)->getPorta() == porta){
            throw new logic_error("Processo já adicionado na porta");
        }
    }
    
    Navegador* n = new Navegador(this->endereco, porta, this->gateway);
    this->processos->push_back(n);
}

Processo* Hospedeiro::getProcesso(int porta){
    Processo* p = NULL;
    for(unsigned int i=0; i<this->processos->size(); i++){
        if(this->processos->at(i)->getPorta() == porta){
            p = this->processos->at(i);
        }
    }
    
    return p;
}

vector<Processo*>* Hospedeiro::getProcessos(){
    return this->processos;
}

void Hospedeiro::processar(){
    int portaOrigem, portaDesitno;
    Datagrama* d;
    Segmento* s;
    Processo *p;

    if(!this->fila->isEmpty()){ 
        cout << "Hospedeiro " << this->endereco << endl;

        d = this->fila->dequeue();
        s = d->getDado();

        portaDesitno = s->getPortaDeDestino();

        p = this->getProcesso(portaDesitno);
        
        if(p != NULL){
            Navegador* navegador = dynamic_cast<Navegador* >(p);
            if(navegador != NULL){
                navegador->receber(d->getOrigem(), s);
            }
            else{
                ServidorWeb* sw = dynamic_cast<ServidorWeb* >(p);
                sw->receber(d->getOrigem(), s);
            }
        }
        else{
            cout << "Sem destino: ";
            cout << "Origem: " << d->getOrigem() << ":"  << d->getDado()->getPortaDeOrigem();
            cout << ", Destino: " << d->getDestino() << ":"  << d->getDado()->getPortaDeDestino();
            cout << ", TTL: " << d->getTtl() << ", " << d->getDado()->getDado() << endl;
        }
    }
}