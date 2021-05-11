#ifndef ROTEADOR_H
#define ROTEADOR_H

#include <iostream>
#include <string>
#include "TabelaDeRepasse.h"
#include "Fila.h"

using namespace std;

class TabelaDeRepasse;

class Roteador{
    
    public:
        Roteador(int endereco);
        ~Roteador();
        TabelaDeRepasse* getTabela();
        Fila* getFila();
        int getEndereco();
        void receber(Datagrama* d);
        void processar();
        string getUltimoDadoRecebido();
        void imprimir();
    
    private:
        int endereco;
        TabelaDeRepasse* tabelaDeRepasse;
        Fila* fila;
        string ultimoDadoRecebido="";

};

#endif