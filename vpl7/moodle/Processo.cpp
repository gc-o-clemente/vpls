#include <iostream>
#include "Processo.hpp"
#include <string>
using namespace std;

Processo::Processo(int id, std::string nome, int prioridade) {
    _id = id;
    _nome = nome;
    _prioridade = prioridade;
}

int Processo::getID() { return _id; }
int Processo::getPrioridade() { return _prioridade; }
string Processo::getNome() { return _nome; }

double Processo::tempo_reservado_processo() {
    if (_prioridade == 0) {
        return 0.5;
    } 
    else if (_prioridade == 1) {
        return 1.5;
    } 
    else if (_prioridade == 2) { 
        return 3.0;
    }
    return 0.0;
}

void Processo::imprimir_dados(){
    string nome_prioridade;
    if (_prioridade == 0) nome_prioridade = "BAIXA";
    else if (_prioridade == 1) nome_prioridade = "MEDIA";
    else if (_prioridade == 2) nome_prioridade = "ALTA";

    cout << _id << "\t" << _nome << "\t" << nome_prioridade << endl;
};

