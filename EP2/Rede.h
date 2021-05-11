#ifndef REDE_H
#define REDE_H

#include <list>
#include <vector>
#include "No.h"
#include "Hospedeiro.h"

using namespace std;

class Rede{
    public:
        Rede();
        virtual ~Rede();
        virtual void adicionar(No* no);

        virtual No* getNo(int endereco);
        virtual list<Hospedeiro*>* getHospedeiros();

        virtual void passarTempo();
        virtual void imprimir(); 
    private:
        vector<No*>* nos;
        int quantidadeDeRoteadores;
};

#endif