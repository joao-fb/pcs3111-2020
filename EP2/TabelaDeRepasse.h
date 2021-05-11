#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include <iostream>
#include <string>
#include "No.h"

using namespace std;


class TabelaDeRepasse{
    public:
        TabelaDeRepasse();
        virtual ~TabelaDeRepasse();
        
        virtual void mapear(int endereco, No* adjacente);
        virtual No** getAdjacentes();
        virtual int getQuantidadeDeAdjacentes();

        virtual void setPadrao(No* padrao);

        virtual No* getDestino(int endereco);
        virtual void imprimir();

        static const int MAXIMO_TABELA = 5; 
    
    private:
        No** adjacentes;
        int* enderecos;
        No* padrao;
        int slotDisponivel=0;
};

#endif