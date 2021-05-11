#include "Datagrama.h"

Datagrama::Datagrama(int origem, int destino, int ttl, Segmento* dado):
origem(origem), destino(destino), ttl(ttl), dado(dado){
    
}

Datagrama::~Datagrama(){
    delete this->dado;
}

int Datagrama::getOrigem(){
    return this->origem;
}

int Datagrama::getDestino(){
    return this-> destino;
}

int Datagrama::getTtl(){
    return this->ttl;
}

Segmento* Datagrama::getDado(){
    return this->dado;
}

void Datagrama::processar(){
    this->ttl -= 1;
}

bool Datagrama::ativo(){
    return this->ttl > 0;
}

void Datagrama::imprimir(){
    cout << "Mensagem: " << this->dado << endl;
}
