#include <bits/stdc++.h>

using namespace std;

#define MAX_STATES 20
#define MAX_CHARSET 16

int sigma[MAX_STATES][MAX_CHARSET];

inline int charToCol(char c) {
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return 0;
  } else if (c >= 48 && c <= 57) {
    return 1;
  } else if (c >= 40 && c <= 47) {
    return c - 38;
  } else if (c >= 60 && c <= 62) {
    return c - 50;
  } else if (c == 34) {
    return 13;
  } else if (c == 59) {
    return 14;
  } else {
    return 15;
  }
}

int main() {
  char caracter, pause;

  // Cria um fluxo de arquivo a partir de "texto.alg"
  ifstream myfile ("texto.alg");

  // Testa se foi possível abrir o arquivo
  if (myfile.is_open()) {
    // Loop de leitura de caracteres
    while (myfile.get(caracter)) {
      if (caracter != '\n') {
        // Imprime o caractere de uma linha
        cout << caracter;
      } else {
        // Pausa a cada linha esperando um "enter"
        cin.get(pause);
      }
    }
    // Fecha o fluxo de arquivo
    myfile.close();
  }
  // Se o arquivo não for aberto
  else {
    cout << "Impossivel abrir o arquivo!\n";
  }
  return 0;
}