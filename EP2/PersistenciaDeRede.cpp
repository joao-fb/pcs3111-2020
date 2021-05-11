#include <iostream>
#include <fstream>
#include <stdexcept>
#include "PersistenciaDeRede.h"
#include "Hospedeiro.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "ServidorWeb.h"
#include "TabelaDeRepasse.h"

PersistenciaDeRede::PersistenciaDeRede(){

}

PersistenciaDeRede::~PersistenciaDeRede(){
    
}

Rede* PersistenciaDeRede::carregar(string arquivo){
    ifstream input;
    Rede *r = new Rede();
    int quantidadeRoteadores;

    input.open(arquivo);

    if(input.fail()){
        throw new invalid_argument("O arquivo nao existe");
    }

    input >> quantidadeRoteadores;
    cout << quantidadeRoteadores << endl;

        
    // Roteadores
    for(int i=0; i<quantidadeRoteadores; i++){
        int endereco;
        input >> endereco;

        cout << endereco << endl;

        Roteador* roteador = new Roteador(endereco);
        r->adicionar(roteador);
    }
    // Hospedeiros
    int quantidadeHospedeiros;
    input >> quantidadeHospedeiros;
    for(int i=0; i<quantidadeHospedeiros; i++){
        int endereco, gateway, quantidadeProcessos;
        No* no;
        Roteador* roteador;

        // Pega o endereco do hospedeiro e do seu roteador
        input >> endereco;
        input >> gateway;

        // Pega o no e faz um cast
        no = r->getNo(gateway);
        roteador = dynamic_cast<Roteador*>(no);

        if(roteador != NULL){
            Hospedeiro* h = new Hospedeiro(endereco, roteador);
            input >> quantidadeProcessos;

            cout << endereco << " " << gateway << " " << quantidadeProcessos << endl;
            
            // Adicionando processos
            for(int j=0; j<quantidadeProcessos; j++){
                string tipo, conteudo;
                int porta;

                input >> tipo;
                if(tipo == "w"){
                    input >> porta;
                    input >> conteudo;
                    
                    cout << tipo << " " << porta << " " << conteudo << endl;

                    h->adicionarServidorWeb(porta, conteudo);
                }
                else if(tipo == "n"){
                    input >> porta;
                    cout << tipo << " " << porta << endl;
                    h->adicionarNavegador(porta);
                }
                else{
                    throw new invalid_argument("O tipo do processo nao existe");
                }
            }
            // Fim da adicao de processos
            r->adicionar(h);
        }
        // Não conseguiu fazer o casting
        else{
            throw new logic_error("Nao foi possivel fazer o casting do no para roteador");
        }

    }
    // Fim hospedeiros

    //Tabela de repasse
    for(int i=0; i<quantidadeRoteadores; i++){
        int endereco, padrao, quantidadeMapeamentos;
        No* no;
        Roteador* roteador;
        input >> endereco;
        input >> padrao;
        input >> quantidadeMapeamentos;

        cout << endereco << " " << padrao << " " << quantidadeMapeamentos << endl;

        no = r->getNo(endereco);
        roteador = dynamic_cast<Roteador*>(no);
        if(roteador != NULL){

            roteador->getTabela()->setPadrao(r->getNo(padrao));
            for(int j=0; j<quantidadeMapeamentos; j++){
                int endereco, destino;

                input >> endereco;
                input >> destino;

                cout << endereco << " " << destino << " " << endl;

                roteador->getTabela()->mapear(endereco, r->getNo(destino));
            }
        }
        // Nao conseguiu fazer o casting
        else{
            throw new logic_error("Nao foi possivel fazer o casting do no para roteador");
        }
    }


    if(!input.eof()){
        throw new runtime_error("O arquivo saiu inesperadamente");
    }

    cout << endl << endl;

    return r;

}