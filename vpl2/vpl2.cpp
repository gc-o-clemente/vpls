#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; //n palavras proibidas
    
    if (!(cin >> n)) return 0; //se a leitura for possível, o if não é ativado. Se a leitura não acontecer, o if é ativado e interrompe a função main
    
    string palavras_proibidas[10]; // vetor para guardar as palavras 
    int contagem[10] = {0}; //quantas vezes aparecem
    int total_palavras_proibidas = 0; 

    for (int i = 0; i < n; ++i) {
        cin >> palavras_proibidas[i];  //lista de palavras proibidas
    } 

    string palavra;
    bool primeira_palavra = true;

    while (cin >> palavra) {
        
        if (!primeira_palavra) {
            cout << " ";// adiciona espaço antes da palavra, menos da primeira
        } 
        primeira_palavra = false;

        bool eh_proibida = false;
        
        for (int i = 0; i < n; ++i) {
            if (palavra == palavras_proibidas[i]) { //compara a palavra que esta sendo lida com a lista das proibidas
                string asteriscos(palavra.length(), '*');
                cout << asteriscos;
                contagem[i]++;
                total_palavras_proibidas++; 
                eh_proibida = true;
                break; // achou a palavra, não precisa continuar procurando
            }
        }

        if (!eh_proibida) {
            cout << palavra;
        }
    }
    
    cout << endl; 

    for (int i = 0; i < n; ++i) {
        cout << "Palavra " << palavras_proibidas[i] << " substituida " << contagem[i] << " vez(es)." << endl;
    }
    cout << total_palavras_proibidas << " palavras censuradas no total " << endl; 
    return 0;
}