#ifndef REDE_H
#define REDE_H

#include <iostream>
#include <string>
#include "Roteador.h"

using namespace std;

class Rede{
    public:
        Rede(Roteador** roteadores, int quantidadeDeRoteadores);
        ~Rede();
        Roteador* getRoteador(int endereco);
        void enviar(string texto, Roteador* origem, int destino, int ttl);
        void passarTempo();
        void imprimir(); 
    private:
        Roteador** roteadores;
        int quantidadeDeRoteadores;
};

#endif