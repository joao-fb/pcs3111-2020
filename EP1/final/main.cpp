#include <iostream>
#include <string>
#include "Fila.h"
#include "Datagrama.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"
#include "Rede.h"

using namespace std;

int main(){

    int escolha=0, origem, destino, ttl, tempoMax, instante=1;
    string mensagem;

    Roteador** roteadores = new Roteador* [6];
    for(int i=0; i<6; i++){
        roteadores[i] = new Roteador(i+1);
    }

    Rede* rede = new Rede(roteadores, 6);

    //Definindo roteadores padrões

    rede->getRoteador(1)->getTabela()->setPadrao(rede->getRoteador(2));
    rede->getRoteador(2)->getTabela()->setPadrao(rede->getRoteador(5));
    rede->getRoteador(3)->getTabela()->setPadrao(rede->getRoteador(2));
    rede->getRoteador(4)->getTabela()->setPadrao(rede->getRoteador(5));
    rede->getRoteador(5)->getTabela()->setPadrao(rede->getRoteador(2));
    rede->getRoteador(6)->getTabela()->setPadrao(rede->getRoteador(5));

    // Definindo roteadores adjacentes

    rede->getRoteador(1)->getTabela()->mapear(4, rede->getRoteador(4));

    rede->getRoteador(2)->getTabela()->mapear(1, rede->getRoteador(1));
    rede->getRoteador(2)->getTabela()->mapear(3, rede->getRoteador(3));

    rede->getRoteador(3)->getTabela()->mapear(6, rede->getRoteador(6));

    rede->getRoteador(4)->getTabela()->mapear(1, rede->getRoteador(1));

    rede->getRoteador(5)->getTabela()->mapear(4, rede->getRoteador(4));
    rede->getRoteador(5)->getTabela()->mapear(6, rede->getRoteador(6));

    rede->getRoteador(6)->getTabela()->mapear(3, rede->getRoteador(3));

    while(escolha != 3){
        cout << endl;
        cout << "Simulador de Rede: " << endl;
        cout << "---" << endl;
        cout << "1) Enviar um datagrama" << endl;
        cout << "2) Passar tempo" << endl;
        cout << "3) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;
        if(escolha == 3){
            break;
        }
        if(escolha==1){
            cout << endl;
            cout << "Endereco do roteador de origem: ";
            cin >> origem;
            cout << "Endereco de destino: ";
            cin >> destino;
            cout << "TTL: ";
            cin >> ttl;
            cout << "Mensagem: ";
            cin >> mensagem;
            rede->enviar(mensagem, rede->getRoteador(origem), destino, ttl);
        }
        if(escolha==2){
            instante = 1;
            cout << endl;
            cout << "Quantidade de tempo: ";
            cin >> tempoMax;

            while(instante <= tempoMax){
                cout << endl;
                cout << "Instante: " << instante << endl;
                cout << "---" << endl;
                rede->passarTempo();
                instante++;
            }
        }
    }

    return 0;
}