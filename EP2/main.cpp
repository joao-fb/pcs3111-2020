#include <iostream>
#include <string>
#include "Datagrama.h"
#include "Fila.h"
#include "Navegador.h"
#include "PersistenciaDeRede.h"
#include "Rede.h"
#include "Roteador.h"
#include "TabelaDeRepasse.h"

using namespace std;

int main(){

    int escolha=0, enderecoHospedeiro, portaHospedeiro, enderecoDestino, portaDestino, tempoMax, instante=1;
    string arquivo;
    Rede* rede;

    cout << "Digite o nome do arquivo: ";
    cin >> arquivo;
    
    PersistenciaDeRede* pr = new PersistenciaDeRede();
    try{
        rede = pr->carregar(arquivo);

    }catch(invalid_argument *e){
        cout << e->what();
        escolha = 4;
    }catch(logic_error *e){
        cout << e->what();
        escolha = 4;
    }catch(runtime_error *e){
        cout << e->what();
        escolha = 4;
    }

    while(escolha != 4){
        cout << endl;
        cout << "---" << endl;
        cout << "1) Usar um navegador" << endl;
        cout << "2) Passar tempo" << endl;
        cout << "3) Alterar TTL" << endl;
        cout << "4) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolha;
        if(escolha == 4){
            break;
        }
        if(escolha==1){
            list <Hospedeiro*>* hospedeiros = rede->getHospedeiros();
            list <Hospedeiro*>::iterator i = hospedeiros->begin();
            
            while(i != hospedeiros->end()){
                cout << "Hospedeiro " << (*i)->getEndereco() << endl;

                vector <Processo*>* processos = (*i)->getProcessos();
                for(int j=0; j<processos->size(); j++){
                    Processo* p = processos->at(j);

                    Navegador* nav = dynamic_cast<Navegador* >(p);

                    if(nav != NULL){
                        cout << "\tNavegador " << p->getPorta() << endl; 
                    }
                    else{
                        cout << "\tServidorWeb " << p->getPorta() << endl; 
                    }
                    
                }
                i++;
            }

            cout << endl;
            cout << "Digite o endereco do hospedeiro: ";
            cin >> enderecoHospedeiro;
            cout << "Digite a porta do navegador: ";
            cin >> portaHospedeiro;
            cout << "Abrir pagina no endereco: ";
            cin >> enderecoDestino;
            cout << "Porta do Servidor Web: ";
            cin >> portaDestino;
            
            No* no = rede->getNo(enderecoHospedeiro);
            Hospedeiro* hospedeiro = dynamic_cast<Hospedeiro* >(no);

            if(hospedeiro != NULL){
                Processo* processo = hospedeiro->getProcesso(portaHospedeiro);
                Navegador* navegador = dynamic_cast<Navegador* >(processo);

                if(navegador != NULL){
                    navegador->abrir(enderecoDestino, portaDestino);
                }
                // A porta nao e um navegador ou nao existe
                else{
                    cout << "Porta invalida" << endl;
                }
            }
            // O endereco nao e um hospedeiro ou nao existe
            else{
                cout << "Endereco invalido" <<  endl;
            }          
            
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
        if(escolha==3){
            int novoPadrao;

            cout << "TTL atual: " << Processo::getTtlPadrao() << endl;
            cout << "Novo TTL: ";
            cin >> novoPadrao;
            Processo::setTtlPadrao(novoPadrao);
        }
    }

    return 0;
}