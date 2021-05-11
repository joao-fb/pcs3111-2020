#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include <iostream>
#include <string>
#include "Roteador.h"

using namespace std;

class Roteador;

class TabelaDeRepasse{
    public:
        TabelaDeRepasse();
        ~TabelaDeRepasse();
        bool mapear(int endereco, Roteador* adjacente);
        Roteador** getAdjacentes();
        int getQuantidadeDeAdjacentes();
        void setPadrao(Roteador* padrao);
        Roteador* getDestino(int endereco);
        void imprimir();
    
    private:
        Roteador** adjacentes;
        int* enderecos;
        Roteador* padrao;
        int slotDisponivel=0;
};

#endif