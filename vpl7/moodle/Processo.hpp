#ifndef PROCESSOS_HPP
#define PROCESSOS_HPP
#include <string>

struct Processo {
    int _id; 
    int _prioridade; 
    std::string _nome;

    Processo(int id, std::string nome, int prioridade);
        int getID();    
        std::string getNome(); 
        int getPrioridade(); 

    double tempo_reservado_processo();
    void imprimir_dados();
};

#endif