#include "Segmento.h"

Segmento::Segmento(int portaDeOrigem, int portaDeDestino, string dado):
portaDeOrigem(portaDeOrigem), portaDeDestino(portaDeDestino), dado(dado){

}

Segmento::~Segmento(){

}

int Segmento::getPortaDeOrigem(){
    return this->portaDeOrigem;
}

int Segmento::getPortaDeDestino(){
    return this->portaDeDestino;
}

string Segmento::getDado(){
    return this->dado;
}

void Segmento::imprimir(){
    
}