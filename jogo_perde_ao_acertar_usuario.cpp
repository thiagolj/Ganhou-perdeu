
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 
    int numeroSecreto = rand() % 100 + 1;
    int palpite;
    int jogador = 1;
    int limiteInferior = 1;
    int limiteSuperior = 100;
    bool acertou = false;

    while (!acertou) {
        cout << "Jogador " << jogador << ", digite seu palpite (" << limiteInferior << " a " << limiteSuperior << "): ";
        cin >> palpite;

        if (palpite < limiteInferior || palpite > limiteSuperior) {
            cout << "Palpite fora do intervalo! Tente novamente." << endl;
            continue;
        }

        if (palpite == numeroSecreto) {
            cout << "Jogador " << jogador << " acertou o numero!" << endl;
            cout << "Parabens, Jogador " << jogador << "! Voce perdeu." << endl;
            acertou = true;
        } else if (palpite < numeroSecreto) {
            limiteInferior = palpite + 1;
            cout << "O numero está entre " << limiteInferior << " e " << limiteSuperior << "." << endl;
        } else {
            limiteSuperior = palpite - 1;
            cout << "O numero está entre " << limiteInferior << " e " << limiteSuperior << "." << endl;
        }

        // alterna entre jogador 1 e 2
        jogador = (jogador == 1) ? 2 : 1;
    }

    return 0;
}
