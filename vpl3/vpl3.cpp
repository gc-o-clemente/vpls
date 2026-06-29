// 0) Crie uma função que receba três variveis inteiras como parâmetro, da seguinte forma:
//    - A primeira deve ser passada por referência 
//    - A segunda deve ser passada "por referência" usando aprimeiro_pontadores (passgem "por referência" disponível em C)
//    - A terceira deve ser passada por valor
//   A função deverá incrementar em 1 o valor das 3 variáveis e retornar.

void funcao(int &var_ref, int *var_pont, int var_valor){
    var_ref++;
    (*var_pont)++;
    var_valor++;
    return;
}

#include <iostream>
#include <string>
using namespace std;

int main(){

    // 1) Declare uma variável do tipo inteiro e preencha com o valor informado na entrada
    //cout << "Passo 1" <<endl;
    int var;
    cin >> var;

    // 2) Declare um ponteiro para inteiros e inicialize com valor nulo
    int *primeiro_pont = nullptr;

    // 3) Declare um vetor de inteiros com tamanho informado na entrada e preencha com dados lidos da entrada
    //cout << "Passo 3" <<endl;
    int tamanho;
    cin >> tamanho;
    int *vetor = new int[tamanho]; 
    for (int i = 0; i < tamanho; i++) {
        cin >> vetor[i];
    }

    // 4) Imprima o ENDEREÇO da variável declarada em (1)
    //cout << "Passo 4" <<endl;
    cout << &var << endl;

    // 5) Imprima o VALOR da variável declarada em (1)
    //cout << "Passo 5" <<endl;
    cout << var << endl; 

    // 6) Imprima o ENDEREÇO da variável declarada em (2)
    //cout << "Passo 6" <<endl;
    cout << &primeiro_pont << endl;
    
    // 7) Imprima o VALOR da variável declarada em (2)
    //cout << "Passo 7" <<endl;
    cout << primeiro_pont << endl;

    // 8) Imprima o ENDEREÇO da variável declarada em (3)
    //cout << "Passo 8" <<endl;
    cout << &vetor << endl;

    // 9) Imprima o ENDEREÇO da primeira posição da variável declarada em (3)
    //cout << "Passo 9" <<endl;
    cout << &vetor[0] << endl;

    // 10) Imprima o VALOR da primeira posição da variável declarada em (3)
    //cout << "Passo 10" <<endl;
    cout << vetor[0] << endl;

    // 11) Atribua o ENDEREÇO da variável declarada em (1) à variável declarada em (2)
    primeiro_pont = &var;

    // 12) Imprima o VALOR da variável declarada em (2)
    //cout << "Passo 12" <<endl;
    cout << primeiro_pont << endl;

    // 13) Imprima o VALOR guardado no ENDEREÇO ponteiro apontado por (2)
    //cout << "Passo 13" <<endl;
    cout << *primeiro_pont << endl;

    // 14) Coloque o VALOR '5' no ENDEREÇO ponteiro apontado por (2)
    *primeiro_pont = 5;

    // 15) Imprima o VALOR da variável declarada em (1)
    //cout << "Passo 15" <<endl;
    cout << var << endl;

    // 16) Atribua o VALOR da variável (3) à variável declarada em (2)
    primeiro_pont = vetor;

    // 17) Imprima o VALOR da variável declarada em (2)
    //cout << "Passo 17" <<endl;
    cout << primeiro_pont << endl;

    // 18) Imprima o VALOR guardado no ENDEREÇO ponteiro apontado por (2)
    //cout << "Passo 18" <<endl;
    cout << *primeiro_pont << endl;

    // 19) Atribua o ENDEREÇO da primeira posição de (3) à variável declarada em (2)
    primeiro_pont = &vetor[0];

    // 20) Compare o valor variáveis (2) e (3), imprimindo 'S' se forem iguais e 'N' se forem diferentes
    //cout << "Passo 20" <<endl;
    if (primeiro_pont == vetor) {
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    // 21) Imprima o VALOR da variável declarada em (2)
    //cout << "Passo 21" <<endl;
    cout << primeiro_pont << endl;

    // 22) Imprima o VALOR guardado no ENDEREÇO ponteiro apontado por (2)
    //cout << "Passo 22" <<endl;
    cout << *primeiro_pont << endl;

    // 23) Multiplique todos os valores do vetor declarado em (3) por '10', porém manipulando apenas a variável (2)
    for (int i = 0; i < tamanho; i++) {
        *primeiro_pont = 10 * (*primeiro_pont);
        primeiro_pont++;
    }

    // 24) Imprima os elementos de (3) a partir variável do vetor utilizando a notação [] (colchetes)
    //cout << "Passo 24" <<endl;
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " "; // Imprime com espaço em vez de quebrar linha
    }
    cout << endl; // Quebra a linha só no final

    // 25) Imprima os elementos de (3) a partir variável do vetor utilizando a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (3)
    //cout << "Passo 25" <<endl;
    for (int i = 0; i < tamanho; i++)
    cout << *(vetor + i) << endl;

    // 26) Imprima os elementos de (3) utilizando a variável (2) e a notação ponteiro/deslocamento
    // Ou seja, você NÃO deve efetivamente alterar o valor do ponteiro inicial de (2)
    //cout << "Passo 26" <<endl;
    for (int i = 0; i < tamanho; i++)
    cout << *(primeiro_pont + i) << endl;
    primeiro_pont++;

    // 27) Atribua o ENDEREÇO da última posição de (3) à variável declarada em (2)
    primeiro_pont = &vetor[tamanho - 1];

    // 28) Imprima o VALOR da variável declarada em (2)
    //cout << "Passo 28" <<endl;
    cout << primeiro_pont << endl;

    // 29) Imprima o VALOR guardado no ENDEREÇO ponteiro apontado por (2)
    //cout << "Passo 29" <<endl;
    cout << *primeiro_pont << endl;

    // 30) Declare um ponteiro para ponteiro e o inicialize com o ENDEREÇO da variável (2)
    int **segundo_pont = &primeiro_pont;

    // 31) Imprima o VALOR da variável declarada em (30)
    //cout << "Passo 31" <<endl;
    cout << segundo_pont << endl;
    
    // 32) Imprima o ENDEREÇO da variável declarada em (30)
    //cout << "Passo 32" <<endl;
    cout << &segundo_pont << endl;

    // 33) Imprima o VALOR guardado no ENDEREÇO ponteiro apontado por (30)
   //cout << "Passo 33" <<endl;
    cout << *segundo_pont << endl;

    // 34) Imprima o VALOR guardado no ENDEREÇO do ponteiro apontado por (30)
    //cout << "Passo 34" <<endl;
    cout << **segundo_pont << endl;

    // 35) Crie 3 variáveis interiras e leia o valor delas da entrada
    //cout << "Passo 35" <<endl;
    int var_1, var_2, var_3;
    cin >> var_1;
    cin >> var_2;
    cin >> var_3;

    // 36) Chame a função criada em (0) passando as 3 variáveis criadas em (35) como parâmetro.
    funcao(var_1, &var_2, var_3);
    
    // 37) Imprima o valor das 3 variáveis criadas em 35, uma por linha
    //cout << "Passo 37" <<endl;
    cout << var_1 << endl;
    cout << var_2 << endl;
    cout << var_3 << endl;

    return 0;
}