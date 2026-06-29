#ifndef SISTEMA_HPP
#define SISTEMA_HPP
#include <string>
#include "Sensor.hpp"
#include "Alerta.hpp"

class Sistema {
    private:
        Sensor* _sensores[100]; //Array de ponteiros para sensores (máximo 100).
        Alerta* _alertas[100]; //Array de ponteiros para alertas (máximo 100).
        int _num_sensores, _num_alertas; //Contadores de ocupação dos arrays

    public:
        Sistema();
        ~Sistema();
        void adicionar_sensor(std::string nome, std::string tipo, double valor); //Instancia um novo sensor e imprime: Sensor <id> adicionado.
        void remover_sensor(int id); //Localiza o sensor, chama o delete para liberar a memória e imprime: Sensor <id> removido. Se não existir, imprime: Erro: sensor <id> nao encontrado.
        void atualizar_sensor(int id, double valor);
        void listar_sensores();
        void adicionar_alerta(std::string desc, std::string tipo, double limiar);
        void verificar_alertas(); //Varre todos os sensores contra todos os alertas. Para cada combinação que resultar em violação, imprime: ALERTA: <descricao>.
        
};

#endif

