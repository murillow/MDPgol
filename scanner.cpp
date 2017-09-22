#include <bits/stdc++.h>

using namespace std;

#define MAX_STATES 22
#define MAX_CHAR_CLASSES 23

int sigma[MAX_STATES][MAX_CHAR_CLASSES] = {
////// 00, 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22,
////// \t, \n, SP, "", ((, )), **, ++, --, .., //, 09, ;;, <<, ==, >>, Az, EE, __, {{, }}, EF, OO,
/*00*/  0,  0,  0,  7, 19, 20, 18, 18, 18, -1, 18,  1, 21, 13, 15, 14,  9,  9, -2, 10, -3, 12, -4,
/*01*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  0,  1,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,
/*02*/ -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,  3, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
/*03*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  0,
/*04*/ -6, -6, -6, -6, -6, -6, -6,  5,  5, -6, -6,  6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,
/*05*/ -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,  6, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,
/*06*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*07*/  7,  7,  7,  8,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, -8,  7,
/*08*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
/*09*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  9,  0,  0,  0,  0,  9,  9,  9,  0,  0,  0,  0,
/*10*/ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, -9, 10,
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
/*21*/  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
};

// map <Lexema, Token, Atributo>
map <string, pair <string, string> > symbolTable;

// String auxiliar para guardar o ultimo lexema;
pair <string, pair <string, string> > bufferLex;

int       symbolToCharClass   (char);
void      showError           (int);
string    make_token          (int);
void      insertToken         (string,  string);

int main(int argc, char *argv[]) {
  string lex;
  int col = 0, line = 1;
  char symbol;
  int charClass, nextState, state = 0;

  symbolTable["inicio"]     = make_pair("inicio", "");
  symbolTable["varinicio"]  = make_pair("varinicio", "");
  symbolTable["varfim"]     = make_pair("varfim", "");
  symbolTable["escreva"]    = make_pair("escreva", "");
  symbolTable["leia"]       = make_pair("leia", "");
  symbolTable["se"]         = make_pair("se", "");
  symbolTable["entao"]      = make_pair("entao", "");
  symbolTable["fimse"]      = make_pair("fimse", "");
  symbolTable["fim"]        = make_pair("fim", "");
  symbolTable["inteiro"]    = make_pair("inteiro", "");
  symbolTable["literal"]    = make_pair("literal", "");
  symbolTable["real"]       = make_pair("real", "");

  ifstream source("texto.alg");

  if (source.is_open()) {
    bool read = true;
    while (true) {
      if (symbol == '\n' && read) {
        line++;
        col = 0;
      }
      if (source.eof()) {
        symbol = EOF;
      } else if (read) {
        source.get(symbol);
        col++;
      }
      read = true;
      charClass = symbolToCharClass(symbol);
      nextState = sigma[state][charClass];
      if (nextState < 0) {
        lex.push_back(symbol);
        insertToken(lex, make_token(nextState));
        cout << argv[0] << ":" << line << ":" << col << " erro: ";
        showError(nextState);
        exit(EXIT_FAILURE);
      }
      else if (nextState > 0 && (state != 10 || nextState != 10)) {
        lex.push_back(symbol);
      }
      else { //nextstate == 0
        if (lex.size() >= 1 && lex != "{") {
          insertToken(lex, make_token(state));
          lex.clear();
          read = false;
        }
      }
      if (symbol == EOF) break;
      state = nextState;
    }
  }
  else {
    cout << "Programa fonte nao encontrado!\n";
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
    return c != 'E' ? 16 : 17;
  } else if (c == '_') {
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

void showError(int code) {
  if (code == -1) cout << "token iniciado por '.'" << endl;
  if (code == -2) cout << "token iniciado por '_'" << endl;
  if (code == -3) cout << "token '}' sem um token '{' anterior" << endl;
  if (code == -4) cout << "caractere invalido" << endl;
  if (code == -5) cout << "esperado um token 'Num' (digito)" << endl;
  if (code == -6) cout << "esperado tokens '+', '-' ou 'Num' (digito) depois do 'E'" << endl;
  if (code == -7) cout << "esperado um token 'Num' (digito)" << endl;
  if (code == -8) cout << "esperado um token '\"' para fechar o ultimo token '\"'" << endl;
  if (code == -9) cout << "esperado um token '}' para fechar o ultimo token '{'" << endl;
}

string make_token(int i) {
  if (i == 1 || i == 3 || i == 6) {
    return "Num";
  } else if (i == 8) {
    return "Literal";
  } else if (i == 9) {
    return "id";
  } else if (i == 11) {
    return "Comentario";
  } else if (i == 12) {
    return "EOF";
  } else if (i == 13 || i == 14 || i == 15 || i == 16) {
    return "OPR";
  } else if (i == 17) {
    return "RCB";
  } else if (i == 18) {
    return "OPM";
  } else if (i == 19) {
    return "AB_P";
  } else if (i == 20) {
    return "FC_P";
  } else if (i == 21) {
    return "PT_V";
  } else {
    return "ERRO";
  }
}

void insertToken(string lex, string token) {
  if (!symbolTable.count(lex)) {
    symbolTable[lex] = make_pair(token, "");
    bufferLex.first = lex;
    bufferLex.second.first = token;
    bufferLex.second.second = "";
    cout << "Criando: " << bufferLex.second.first << ":" << bufferLex.first << endl;
  }
  else if (lex == "inteiro" || lex == "literal" || lex == "real") {
    symbolTable[bufferLex.first] = make_pair(bufferLex.second.first, lex);
    bufferLex.second.second = lex;
    cout << "Acrescentando tipo:  " << bufferLex.second.second << " em " <<
    bufferLex.second.first << ":" << bufferLex.first << endl;
  }
  else {
    cout << "Existente: " << token << ":" << lex << endl;
  }
}