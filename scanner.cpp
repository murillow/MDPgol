#include <bits/stdc++.h>

using namespace std;

#define MAX_STATES 21
#define MAX_CHARSET 18

int sigma[MAX_STATES][MAX_CHARSET] = {
/*Q/C  LL  DD  ((  ))  **  ++  ,,  --  ..  //  <<  ==  >>  ""  ;;  OO  EE  EOF
/*q0*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*q1*/  7,  2, 17, 18, 16, 16, 20, 16, 20, 16, 10, 12, 11,  8, 19, 20,  7,  6,
/*q2*/  0,  2,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  4,  0,
/*q3*/  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*q4*/  0,  2,  0,  0,  0,  5,  0,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*q5*/  0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*q6*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*q7*/  7,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7,  0,
};

inline int charToCol(char c) {
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return c == 69 ? 16 : 1;
  } else if (c >= 48 && c <= 57) {
    return 2;
  } else if (c >= 40 && c <= 47) {
    return c - 37;
  } else if (c >= 60 && c <= 62) {
    return c - 49;
  } else if (c == 34) {
    return 14;
  } else if (c == 59) {
    return 15;
  } else if (c == -1) {
    return 17;
  } else {
    return 0;
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