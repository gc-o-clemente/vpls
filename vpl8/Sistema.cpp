#include <iostream>
#include <string>
#include "Sensor.hpp"
#include "Alerta.hpp"
#include "Sistema.hpp"

Sistema::Sistema(){
    _num_alertas = 0;
    _num_sensores = 0;
}

Sistema::~Sistema() {
    // Apaga os sensores que sobraram
    for (int i = 0; i < _num_sensores; i++) {
        delete _sensores[i];
    }
    // Apaga os alertas que sobraram
    for (int i = 0; i < _num_alertas; i++) {
        delete _alertas[i];
    }
}

void adicionar_sensor(std::string nome, std::string tipo, double valor) {
    Sensor* s = new Sensor(nome, tipo, valor);
    _sensores[_num_sensores] = s;
    _num_sensores++;
    std::cout << "Sensor " << s->get_id() << " adicionado." << std::endl;
}

void Sistema::remover_sensor(int id) {
    for (int i = 0; i < _num_sensores; i++) {
        if (_sensores[i]->get_id() == id) {
            delete _sensores[i]; 
            std::cout << "Sensor " << id << " removido." << std::endl;

            for (int j = i; j < _num_sensores - 1; j++) {
                _sensores[j] = _sensores[j + 1];
            }
            _num_sensores--; 
            return; 
        }
    }
    std::cout << "Erro: sensor " << id << " nao encontrado." << std::endl;
}

void Sistema::adicionar_alerta(std::string desc, std::string tipo, double limiar) {
    Alerta* a = new Alerta(desc, tipo, limiar);
    _alertas[_num_alertas] = a;
    _num_alertas++;
}

void Sistema::verificar_alertas() {
    for (int i = 0; i < _num_alertas; i++) {
        for (int j = 0; j < _num_sensores; j++) {
            if (_alertas[i]->verificar(_sensores[j]) == true) {
                std::cout << "ALERTA: " << _alertas[i]->get_descricao() << std::endl;
            }
        }
    }
}

void Sistema::atualizar_sensor(int id, double valor) {
    for (int i = 0; i < _num_sensores; i++) {
        if (_sensores[i]->get_id() == id) {
            _sensores[i]->set_valor(valor);
            return;
        }
    }
}

void Sistema::listar_sensores() {
    for (int i = 0; i < _num_sensores; i++) {
        // Formato exigido: <id> <nome> (<tipo>): <valor>
        std::cout << _sensores[i]->get_id() << " " 
                  << _sensores[i]->get_nome() << " (" 
                  << _sensores[i]->get_tipo() << "): " 
                  << _sensores[i]->get_valor() << std::endl;
    }
}