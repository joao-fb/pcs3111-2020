#include "ServidorWeb.h"


ServidorWeb::ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo):
Processo(endereco, porta, gateway), conteudo(conteudo){

}

ServidorWeb::~ServidorWeb(){

}

void ServidorWeb::receber(int origem, Segmento* mensagem){
    cout << "ServidorWeb " << this->porta << endl;

    Segmento* s = new Segmento(this->porta, mensagem->getPortaDeOrigem(), this->conteudo);
    Datagrama* d = new Datagrama(this->endereco, origem, this->getTtlPadrao(), s);
    this->gateway->receber(d);

    cout << "\tDevolvendo mensagem para: " << origem << ":" << mensagem->getPortaDeOrigem() << endl;
}