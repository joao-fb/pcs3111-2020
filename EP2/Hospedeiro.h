#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include <vector>
#include "No.h"
#include "Processo.h"

class Hospedeiro: public No{
    public:
        Hospedeiro(int endereco, Roteador* gateway);
        virtual ~Hospedeiro ();

        virtual void adicionarServidorWeb(int porta, string conteudo);
        virtual void adicionarNavegador(int porta);

        virtual Processo* getProcesso(int porta);
        virtual vector<Processo*>* getProcessos();

        virtual void processar();
    
    private:
        int endereco;
        Roteador* gateway;
        vector<Processo*>* processos;

};

#endif