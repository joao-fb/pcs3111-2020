#include "Processo.h"

int Processo::padrao = 5;

Processo::Processo(int endereco, int porta, Roteador* gateway):
endereco(endereco), porta(porta), gateway(gateway){
    
}

Processo::~Processo(){

}

int Processo::getEndereco(){
    return this->endereco;
}

int Processo::getPorta(){
    return this->porta;
}

void Processo::imprimir(){

}

void Processo::setTtlPadrao(int padrao){
    Processo::padrao = padrao;
}

int Processo::getTtlPadrao(){
    return Processo::padrao;
}