#include "comunicacao.hpp"
#include <string>

Comunicacao::Comunicacao() {}

std::string Comunicacao::gerarRelatorio(int posicao, int bateria, bool completou_missao) {
    std::string status = completou_missao ? "Concluida" : "Pendente";
    return "R2D2 em " + std::to_string(posicao) + ", Bateria: " + std::to_string(bateria) + "%, Missao: " + status;
}

bool Comunicacao::enviarSinal(std::string mensagem, int bateria, bool completou_missao) {
    if (bateria < 5) return false;
    if (completou_missao) return true;
    return false;
}