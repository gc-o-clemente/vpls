#include <iostream>
#include <String>
#include "Alerta.hpp"
#include "Sensor.hpp"

//construtor
Alerta::Alerta(std::string desc, std::string tipo, double limiar) { 
    _descricao = desc;
    _tipo_sensor = tipo;
    _limiar = limiar;
}

bool Alerta::verificar(Sensor* s) { 
    if (s->get_tipo() == _tipo_sensor && s->get_valor() > _limiar) { 
        return true;
    }
    else {
        return false;
    }
}

std::string Alerta::get_descricao() {
    return _descricao;
}