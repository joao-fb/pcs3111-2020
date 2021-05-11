#ifndef DATAGRAMA_H
#define DATAGRAMA_H

#include <iostream>
#include <string>
#include "Segmento.h"

using namespace std;

class Datagrama {
    public:
        Datagrama(int origem, int destino, int ttl, Segmento* dado);
        virtual ~Datagrama();
        virtual int getOrigem();
        virtual int getDestino();
        virtual int getTtl();
        virtual Segmento* getDado();
        virtual void processar();
        virtual bool ativo();
        virtual void imprimir(); 

    private:
        int origem;
        int destino;
        int ttl;
        Segmento* dado;

};

#endif
