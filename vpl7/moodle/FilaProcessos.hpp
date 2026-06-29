#ifndef FILAPROCESSOS_HPP
#define FILAPROCESSOS_HPP
#include "Processo.hpp"
#include <string>

struct Node {
    Processo* processo;
    Node* proximo;

    Node(Processo* p) {
        processo = p;
        proximo = nullptr; 
    }
};

struct FilaProcessos {
    Node* header;
    int contador_id;
    FilaProcessos();
    void adicionar_processo(std::string nome, int prioridade);
    Processo* remover_processo_maior_prioridade(); 
    Processo* remover_processo_por_id(int id);
    void estimativa_tempo_para_execucao(int id);
    void imprimir_fila();
};

#endif