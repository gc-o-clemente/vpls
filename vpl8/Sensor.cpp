#include <iostream>
#include <string>
#include "Sensor.hpp"

//incialização de atributos estáticos
    int Sensor::_proximo_id = 1;
    int Sensor::_total_ativos = 0;
    bool Sensor::_exibir_mensagens = true;

//construtor
    Sensor::Sensor(std::string nome, std::string tipo, double valor) {
        _nome = nome;
        _tipo = tipo;
        _valor = valor;
        _id = _proximo_id; 
        _proximo_id++; 
        _total_ativos++; 
    }

//destrutor
    Sensor::~Sensor() {
        _total_ativos--;

        if (_exibir_mensagens == true) {
            std::cout << "Sensor " << _id << " desativado." << std::endl;
        }
    }

//setter estatico
    void Sensor::set_exibir_mensagens(bool valor) {
        _exibir_mensagens = valor;
    }

//getters
    int Sensor::get_id() { 
        return _id; 
    }
    std::string Sensor::get_nome() { 
        return _nome; 
    }
    std::string Sensor::get_tipo() { 
        return _tipo; 
    }
    double Sensor::get_valor() { 
        return _valor; 
    }
    int Sensor::get_total_ativos() { 
        return _total_ativos; 
    }

//setters
    void Sensor::set_valor(double v) {
        _valor = v;
    }