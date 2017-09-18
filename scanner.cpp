#include <bits/stdc++.h>

using namespace std;

#define MAX_STATES        20
#define MAX_CHAR_CLASSES  20

int sigma[MAX_STATES][MAX_CHAR_CLASSES] = {
/////   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19
/////  LL  DD  ((  ))  **  ++  ,,  --  ..  //  <<  ==  >>  ""  ;;  {{  }}  EE  OO  EOF
/*0*/   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*1*/   7,  2, 17, 18, 16, 16, 18, 16, 18, 16, 10, 12, 11,  8, 19, 14,  0,  7,  0,  6,
/*2*/   0,  2,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  0,  0,  0,  4,  0,  0,
/*3*/   0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*4*/   0,  2,  0,  0,  0,  5,  0,  5,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*5*/   0,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*6*/   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*7*/   7,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 18,  0,
/*8*/   8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  9,  8,  8,  8,  8,  8,  0,
/*9*/   0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*10*/  0,  0,  0,  0,  0,  0,  0, 13,  0,  0,  0, 12,  0,  0,  0,  0,  0,  0,  0,  0,
/*11*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12,  0,  0,  0,  0,  0,  0,  0,  0,
/*12*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*13*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*14*/ 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 14, 14, 14,
/*15*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*16*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*17*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*18*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*19*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

inline int symbolToCharClass(char c) {
  if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
    return c == 69 ? 18 : 0;
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
  } else if (c == 123) {
    return 15;
  } else if (c == 125) {
    return 16;
  } else if (c == -1) {
    return 19;
  } else {
    return 17;
  }
}

int main() {
  char symbol;
  string lex;
  int state = 1, col = 0, line = 0, charClass, token;

  ifstream source("texto.alg");

  if (source.is_open()) {
    while (source.get(symbol)) {
      //while (isspace(symbol)) {
      //  cout << symbol << endl;
      //  source.get(symbol);
      //}
      if (symbol == '\n') {
        line++;
        col = 0, state = 1;
        cout << lex << endl;
        lex.clear();
      } else {
        charClass = symbolToCharClass(symbol);
        if (sigma[state][charClass]) {
          lex.push_back(symbol);
          state = sigma[state][charClass];
        } else {  
        }
      }
      col++;    
    }
    cout << lex << endl;
  } else {
    cout << "Impossível abrir o arquivo!\n";
  }
  return 0;
}