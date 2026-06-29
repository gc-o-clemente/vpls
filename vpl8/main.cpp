#include <iostream>
#include <string>
#include <iomanip>
#include "Sensor.hpp"
#include "Alerta.hpp"
#include "Sistema.hpp"

int main() {
    std::cout << std::fixed << std::setprecision(1);

    Sistema sis;

    char comando;
    while (std::cin >> comando) {
        
        switch (comando) {
            case 's': { 
                std::string nome, tipo;
                double valor;
                std::cin >> nome >> tipo >> valor;
                sis.adicionar_sensor(nome, tipo, valor);
                break;  
            }
            case 'u': {
                int id;
                double valor;
                std::cin >> id >> valor;
                sis.atualizar_sensor(id, valor);
                break;
            }
            case 'r': {
                int id;
                std::cin >> id;
                sis.remover_sensor(id);
                break;
            }
            case 'a': {
                std::string desc, tipo;
                double limiar;
                std::cin >> desc >> tipo >> limiar;
                sis.adicionar_alerta(desc, tipo, limiar);
                break;
            }
            case 'l': { 
                sis.listar_sensores();
                break;
            }
            case 'c': {
                std::cout << "Total de sensores ativos: " << Sensor::get_total_ativos() << std::endl;
                break;
            }
            case 'v':{
                sis.verificar_alertas();
                break;
            }    
            default:{
                std::cout << "Comando invalido!" << std::endl;
                break;
            }
        }
    }

    // REGRA FINAL DE ENCERRAMENTO (Silenciar tudo)
    // O professor pede para setar o exibir_mensagens para false antes do programa fechar
    Sensor::set_exibir_mensagens(false);

    return 0; // Quando o main morre aqui, o Sistema é destruído, o que vai destruir os sensores silenciosamente.
}
