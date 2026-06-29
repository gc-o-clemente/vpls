#ifndef SENSOR_HPP
#define SENSOR_HPP
#include <string>

class Sensor {
    private:
        int _id; //Identificador único do sensor

        std::string _nome; //Localização ou nome do sensor

        std::string _tipo; //Tipo de grandeza medida (ex: Temperatura, Pressao).

        double _valor; //Leitura atual do sensor.

        static int _proximo_id; //Contador global para gerar IDs automáticos, iniciando em 1.

        static int _total_ativos; //Contador global de quantos objetos Sensor existem atualmente na memória.

        static bool _exibir_mensagens; //Estado global do objeto para impressão de mensagens (inicia como true). 
    
    public:
        Sensor(std::string nome, std::string tipo, double valor); //Construtor que inicializa os atributos, incrementa o _proximo_id e o _total_ativos.

        ~Sensor(); //Destrutor que decrementa o _total_ativos. Se _exibir_mensagens for true, deve imprimir: Sensor <id> desativado.

        static void set_exibir_mensagens(bool valor); //Altera o estado do interruptor global de mensagens.

        //Getters: 
            int get_id();
            std::string get_nome();
            std::string get_tipo();
            double get_valor();
            static int get_total_ativos(); 

        //Setters: 
            void set_valor(double v); 
};

#endif