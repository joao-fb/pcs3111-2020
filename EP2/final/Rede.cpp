#include <iostream>
#include <string>
#include "Rede.h"
#include "Datagrama.h"

using namespace std;



Rede::Rede(){
    this->nos = new vector<No*>();
}

Rede::~Rede(){

}

void Rede::adicionar(No* no){
    for(unsigned int i =0; i<this->nos->size(); i++){
        if(this->nos->at(i)->getEndereco() == no->getEndereco()){
            throw new logic_error("No com mesmo endereco ja adicionado!");
        }
    }
    this->nos->push_back(no);
}

No* Rede::getNo(int endereco){
    No* no=NULL;
    for(unsigned int i =0; i<this->nos->size(); i++){
        if(this->nos->at(i)->getEndereco() == endereco){
            no = this->nos->at(i);
        }
    }
    // if(no==NULL){
    //     cout << "Erro: origem desconhecida";
    // }
    return no;
}

list<Hospedeiro*>* Rede::getHospedeiros(){
    Hospedeiro* h;
    list<Hospedeiro*>* hospedeiros =  new list<Hospedeiro*>();
    for(unsigned int i =0; i<this->nos->size(); i++){

        h = dynamic_cast<Hospedeiro* >(this->nos->at(i));
        if(h != NULL){
            hospedeiros->push_back(h);
        }
    }
    return hospedeiros;
}

void Rede::passarTempo(){
    for(unsigned int i =0; i<this->nos->size(); i++){
        No* no = this->nos->at(i);
        no->processar();
    }
}

void Rede::imprimir(){

}