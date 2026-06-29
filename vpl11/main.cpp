// TESTES DO MODULO DE ENERGIA
TEST_CASE("Teste 02: Energia - Inicializacao negativa travada em zero") {
    Energia bateria(-20);
    CHECK(bateria.getCarga() == 0);
}

TEST_CASE("Teste 03: Energia - Consumo normal de bateria") {
    Energia bateria(50);
    bateria.consumir(20);
    CHECK(bateria.getCarga() == 30);
}

TEST_CASE("Teste 04: Energia - Protecao contra consumo negativo (exploit)") {
    Energia bateria(40);
    bateria.consumir(-10); 
    CHECK(bateria.getCarga() == 40);
}

TEST_CASE("Teste 05: Energia - Limite de consumo travado no zero") {
    Energia bateria(15);
    bateria.consumir(20);
    CHECK(bateria.getCarga() == 0); 
}

// TESTES DO MODULO DE COMUNICACAO
TEST_CASE("Teste 06: Comunicacao - Relatorio com missao pendente") {
    Comunicacao com;
    std::string relatorio = com.gerarRelatorio(5, 80, false);
    CHECK(relatorio == "R2D2 em 5, Bateria: 80%, Missao: Pendente");
}

TEST_CASE("Teste 07: Comunicacao - Relatorio com missao concluida") {
    Comunicacao com;
    std::string relatorio = com.gerarRelatorio(10, 15, true);
    CHECK(relatorio == "R2D2 em 10, Bateria: 15%, Missao: Concluida");
}

TEST_CASE("Teste 08: Comunicacao - Sinal enviado com sucesso") {
    Comunicacao com;
    bool envia_sinal = com.enviarSinal("Relatorio", 10, true);
    CHECK(envia_sinal == true);
}

TEST_CASE("Teste 09: Comunicacao - Falha ao enviar sinal por falta de bateria") {
    Comunicacao com;
    bool envia_sinal = com.enviarSinal("Relatorio", 4, true);
    CHECK(envia_sinal == false);
}

TEST_CASE("Teste 10: Comunicacao - Falha ao enviar sinal por missao pendente") {
    Comunicacao com;
    bool envia_sinal = com.enviarSinal("Relatorio", 100, false);
    CHECK(envia_sinal == false);
}

// TESTES DO MODULO DO R2D2
TEST_CASE("Teste 11: R2D2 - Estado inicial correto (Posicao e energia)") {
    R2D2 r2(100, 50);
    CHECK(r2.getPosicao() == 0);
    CHECK(r2.getEnergiaRestante() == 100);
}

TEST_CASE("Teste 12: R2D2 - Movimento basico para frente") {
    R2D2 r2(50, 100);
    r2.mover(10);
    CHECK(r2.getPosicao() == 10);
    CHECK(r2.getEnergiaRestante() == 40);
}

TEST_CASE("Teste 13: R2D2 - Movimento para tras (consumo absoluto)") {
    R2D2 r2(50, 100);
    r2.mover(15);  
    r2.mover(-5);  
    CHECK(r2.getPosicao() == 10);
    CHECK(r2.getEnergiaRestante() == 30);
}

TEST_CASE("Teste 14: R2D2 - Limite inferior do corredor (posicao 0)") {
    R2D2 r2(50, 100);
    r2.mover(5);
    r2.mover(-10); // Tenta recuar mais do que o limite 0
    CHECK(r2.getPosicao() == 0);
    CHECK(r2.getEnergiaRestante() == 40); // Consumiu 5 pra ir, 5 pra voltar ao zero
}

TEST_CASE("Teste 15: R2D2 - Limite superior do corredor") {
    R2D2 r2(100, 20);
    r2.mover(30);
    CHECK(r2.getPosicao() == 20);
    CHECK(r2.getEnergiaRestante() == 80);
}

TEST_CASE("Teste 16: R2D2 - Obstaculo bloqueando movimento para frente") {
    R2D2 r2(50, 50, 15);
    r2.mover(20);       
    CHECK(r2.getPosicao() == 14); // Posição imediatamente anterior
    CHECK(r2.getEnergiaRestante() == 36); 
}

TEST_CASE("Teste 17 Refeito: R2D2 - Falta de bateria no meio do caminho") {
    R2D2 r2(10, 50); 
    r2.mover(25);  
    CHECK(r2.getPosicao() == 10);
    CHECK(r2.getEnergiaRestante() == 0);
}

TEST_CASE("Teste 18: R2D2 - Interacao simultanea de obstaculo e falta de bateria") {
    R2D2 r2(5, 50, 15);
    r2.mover(20); 
    CHECK(r2.getPosicao() == 5); 
    CHECK(r2.getEnergiaRestante() == 0);
}

TEST_CASE("Teste 19: R2D2 - Nao concluir missao sem voltar a base") {
    R2D2 r2(100, 20);
    bool status = r2.mover(20);
    CHECK(r2.getPosicao() == 20);
    CHECK(r2.getEnergiaRestante() == 80);
    CHECK(status == false); // Bateu no terminal mas não retornou
}

TEST_CASE("Teste 20: R2D2 - Sucesso absoluto da missao") {
    R2D2 r2(100, 15); 
    r2.mover(15);     
    bool status = r2.mover(-15); 
    CHECK(r2.getPosicao() == 0);
    CHECK(r2.getEnergiaRestante() == 70);
    CHECK(status == true); // Tocou terminal e voltou pra 0
}