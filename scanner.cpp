#include <bits/stdc++.h>

using namespace std;

#define MAX_STATES 23
#define MAX_CHAR_CLASSES 23

int sigma[MAX_STATES][MAX_CHAR_CLASSES] = {
////// 00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
////// \t, \n, SP, "", ((, )), **, ++, --, .., //, 09, ;;, <<, ==, >>, Az, EE, __, {{, }}, EF, OO,
/*00*/  0,  0,  0,  7, 19, 20, 18, 18, 18, 22, 18,  1, 21, 13, 15, 14,  9,  9, 22, 10, 22, 12, 22,
/*01*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  1,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,
/*02*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*03*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,
/*04*/  0,  0,  0,  0,  0,  0,  0,  5,  5,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*05*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*06*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*07*/  7,  7,  7,  8,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  0,  7,
/*08*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*09*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0,  9,  9,  9,  0,  0,  0,  0,
/*10*/ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11,  0, 10,
/*11*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*12*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*13*/  0,  0,  0,  0,  0,  0,  0,  0, 17,  0,  0,  0,  0,  0, 15, 16,  0,  0,  0,  0,  0,  0,  0,
/*14*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15,  0,  0,  0,  0,  0,  0,  0,  0,
/*15*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*16*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*17*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*18*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*19*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*20*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*21*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*22*/ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
};

//q0        = estado  inicial
//q1 - q6   = estados Num
//q7 - q8   = estados Literal
//q9        = estado  Identificador
//q10 e q11 = estados Comentários
//q12       = End Of File
//q13 - q16 = estados Operadores Relacionáis
//q17       = estado  Atribuição
//q18       = estado  Operadores Aritméticos
//q19       = estado  AB_P
//q20       = estado  FC_P
//q21       = estado  PT_V
//q19       = estado  ERRO

int symbolToCharClass(char);
void showToken(int);
void showError(int);

int main(void) {
  string lex;
  int col = 0, line = 1;
  char symbol;
  int charClass, nextState, state = 0;

  ifstream source("texto.alg");

  if (source.is_open()) {
    while (source.get(symbol)) {
      charClass = symbolToCharClass(symbol);
      nextState = sigma[state][charClass];
      if (symbol == '\n') {
        line++;
        col = 0;
      }
      if (state == 22) {
        printf("ERRO:%d:%d: ", line, col);
        showError(nextState);
        exit(EXIT_FAILURE);
      }
      // cout << state << " - " << charClass << " - " << symbol << endl;
      if (nextState) {
        lex.push_back(symbol);
      }
      else {
        showToken(state);
        if (lex.size() >= 1) cout << lex << endl;
        lex.clear();
        if (sigma[nextState][charClass]) {
          nextState = sigma[nextState][charClass];
          lex.push_back(symbol);
        }
      }
      state = nextState;
      col++;
    }
  }
  else {
    cout << "Impossível abrir o arquivo!\n";
  }
  return 0;
}

int symbolToCharClass(char c) {
  if (c == '\t') {
    return 0;
  } else if (c == '\n') {
    return 1;
  } else if (c == ' ') {
    return 2;
  } else if (c == '"') {
    return 3;
  } else if (c >= '(' && c <= '+') {
    return c - 36;
  } else if (c >= '-' && c <= '/') {
    return c - 37;
  } else if (c >= '0' && c <= '9') {
    return 11;
  } else if (c >= ';' && c <= '>') {
      return c - 47;
  } else if ((c >= 'A' && c <= 'Z') || ((c >= 'a' && c <= 'z'))) {
    if (c != 'E') {
      return 16;
    } else {
      return 17;
    }
  }
  else if (c == '_') {
    return 18;
  } else if (c == '{') {
    return 19;
  } else if (c == '}') {
    return 20;
  } else if (c == EOF) {
    return 21;
  } else {
    return 22;
  }
}

void showToken(int i) {
  if (i == 1 || i == 3 || i == 6)
    cout << "Token: NUM\t";
  else if (i == 8)
    cout << "Token: Literal\t";
  else if (i == 9)
    cout << "Token: ID\t";
  else if (i == 11)
    cout << "Token: Comentario\t";
  else if (i == 12)
    cout << "Token: End Of File\t";
  else if (i == 13 || i == 14 || i == 15 || i == 16)
    cout << "Token: Operador Relacional\t";
  else if (i == 17)
    cout << "Token: Atribuicao\t";
  else if (i == 18)
    cout << "Token: Operador Aritimetico\t ";
  else if (i == 19)
    cout << "Token: Abre Parentese\t";
  else if (i == 20)
    cout << "Token: Fecha Parentese\t";
  else if (i == 21)
    cout << "Token: Ponto e Virgula\t";
}

void showError(int code) {
  printf("%d\n", code);
}