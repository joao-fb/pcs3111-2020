#include "Navegador.h"


Navegador::Navegador(int endereco, int porta, Roteador* gateway):
Processo(endereco, porta, gateway){
    
}

Navegador::~Navegador(){

}

void Navegador::abrir(int endereco, int porta){
    Segmento* s = new Segmento(this->porta, porta, "GET");
    Datagrama* d = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), s);
    this->gateway->receber(d);
    this->conteudo = "";
    this->awaiting = true;
}

void Navegador::abrir(int endereco){
    Segmento* s = new Segmento(this->porta, 80, "GET");
    Datagrama* d = new Datagrama(this->endereco, endereco, this->getTtlPadrao(), s);
    this->gateway->receber(d);
    this->conteudo = "";
    this->awaiting = true;
}

string Navegador::getConteudo(){
    return this->conteudo;
}

void Navegador::receber(int origem, Segmento* mensagem){
    cout << "Navegador " << this->porta << endl;

    if(this->awaiting){
        cout << "\tRecebido de " << origem << ":" << mensagem->getPortaDeOrigem();
        cout << ": " << mensagem->getDado() << endl;
        this->conteudo = mensagem->getDado();
        this->awaiting = false;
    }
    else{
        cout << "\tMensagem ignorada: " << origem << ":" << mensagem->getPortaDeOrigem();
        cout << ": " << mensagem->getDado() << endl;
    }
}