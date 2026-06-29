#include <iostream>
#include <string>
#include <iomanip>
#include "FilaProcessos.hpp"

using namespace std;

FilaProcessos::FilaProcessos() {
    header = nullptr; 
    contador_id = 1;  
};

void FilaProcessos::adicionar_processo(string nome, int prioridade) {
    Processo* novo_processo = new Processo(contador_id, nome, prioridade);
    Node* new_node = new Node(novo_processo); 
    contador_id++;

    if (header == nullptr) {
        header = new_node;
    } else if(novo_processo->getPrioridade() > header->processo->getPrioridade()) {
        new_node->proximo = header;
        header = new_node;
    } else {
        Node* atual = header;
        while (atual->proximo != nullptr && atual->proximo->processo->getPrioridade() >= novo_processo->getPrioridade()) {
          atual = atual->proximo;
        }
    new_node->proximo = atual->proximo;
    atual->proximo = new_node;
    }
};

Processo* FilaProcessos::remover_processo_maior_prioridade() {
    if (header == nullptr) {
        return nullptr;
    }

    Node* node_remover = header;
    Processo* processo_removido = node_remover->processo;
    header = header->proximo;
    delete node_remover;
    return processo_removido;
}

Processo* FilaProcessos::remover_processo_por_id(int id) {
    if (header == nullptr) {
        return nullptr;
    }

    if (header->processo->getID() == id) {
        Node* node_remover = header;
        Processo* processo_removido = node_remover->processo; 
        header = header->proximo;
        delete node_remover;      
        return processo_removido;
    }

    Node* anterior = header;
    Node* atual = header->proximo;

    while (atual != nullptr && atual->processo->getID() != id) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == nullptr) {
        return nullptr;
    }
    
    anterior->proximo = atual->proximo;
    Processo* processo_removido = atual->processo;
    delete atual;  
    return processo_removido;
}

void FilaProcessos::estimativa_tempo_para_execucao(int id) {
    double tempo_acumulado = 0.0;
    Node* atual = header;
    
    while (atual != nullptr) {
        if (atual->processo->getID() == id) {
            cout << "Tempo estimado para execução do processo " 
                 << atual->processo->getNome() 
                 << " (id=" << id << ") eh " 
                 << fixed << setprecision(1) << tempo_acumulado 
                 << " segundos." << endl;
            return;
        }
        tempo_acumulado += atual->processo->tempo_reservado_processo();
        atual = atual->proximo;
    }   
};

void FilaProcessos::imprimir_fila() {
    Node* atual = header;
    while (atual != nullptr) {
        atual->processo->imprimir_dados();
        atual = atual->proximo;
    }
};



