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

/* Variaveis globais */
map <string, pair <string, string> > symbol_table; // <Lexema, Token, Atributo>
string lex;
string lastLex;
string token;
int line = 1;
int col = 1;
int state;
int lastState;
FILE *fd, *fopen();

/* Declaracoes de funcoes */
bool entry_exists(string);
int symbol_to_charClass (char);
void show_error (int);
string make_token (int);
void make_token_attr (string, string);
pair <string, pair <string, string> > scanner (void);

/******************************************************************************/
/* main - driver principal */
int main(int argc, char **argv) {
  pair <string, pair <string, string> > token_attr; // <Lexema, Token, Atributo>

  symbol_table["inicio"]     = make_pair("inicio", "");
  symbol_table["varinicio"]  = make_pair("varinicio", "");
  symbol_table["varfim"]     = make_pair("varfim", "");
  symbol_table["escreva"]    = make_pair("escreva", "");
  symbol_table["leia"]       = make_pair("leia", "");
  symbol_table["se"]         = make_pair("se", "");
  symbol_table["entao"]      = make_pair("entao", "");
  symbol_table["fimse"]      = make_pair("fimse", "");
  symbol_table["fim"]        = make_pair("fim", "");
  symbol_table["inteiro"]    = make_pair("inteiro", "");
  symbol_table["literal"]    = make_pair("literal", "");
  symbol_table["real"]       = make_pair("real", "");

  if ((fd = fopen("texto.alg", "r")) == NULL) {
    cout << "Erro na abertura do arquivo fonte!\n";
  } else {
    do {
      token_attr = scanner();
      cout << token_attr.first << ":" << token_attr.second.first << endl;      
    } while (token_attr.first != "EOF");
  }

  return 0;
}

/******************************************************************************/
/* scanner - funcao que realiza a analise lexica de programas MDPgol e retorna o
             pair <token, lexema, atributo> */
pair <string, pair <string, string> > scanner() {
  pair <string, pair <string, string> > nextToken;
  char nextChar;
  int charClass;
  nextChar = getc(fd);
  col++;  
  if (nextChar == '\n') {
    line++;
    col = 1;
  }
  charClass = symbol_to_charClass(nextChar);
  state = sigma[state][charClass];
  if (state < 0) {
    printf("texto.alg:%d:%d erro: ", line, col);
    show_error(state);
    exit(EXIT_FAILURE);
  } else if (state > 0) {
    lex.push_back(nextChar);
    lastState = state;
  } else {
    if (lex.size() >= 1) {
      token = make_token(lastState);
      if (lastState == 9) { // ID
        if (!entry_exists(lex)) {
          symbol_table[lex] = make_pair(token, "");
          lastLex = lex;
        } else if (lex == "inteiro" || lex == "literal" || lex == "real") {
          symbol_table[lastLex].second = lex;
          cout << "inserindo: <" << token << ", " << lastLex << ", " << lex << ">\n";
        } else {
          cout << "existente: <" << symbol_table[lex].first << ", " << lex << ", " << symbol_table[lex].second << ">\n";                      
        }
      }
      nextToken = make_pair(token, make_pair(lex, ""));
      lex.clear();
      if (sigma[state][charClass] > 0) {
        state = sigma[state][charClass];
        lex.push_back(nextChar);
        lastState = state;
      } else if (sigma[state][charClass] < 0) {
        state = sigma[state][charClass];        
        printf("texto.alg:%d:%d erro: ", line, col);
        show_error(state);
        exit(EXIT_FAILURE);
      }
      return nextToken;    
    }
  }
  nextToken = scanner();
  return nextToken;
}

/******************************************************************************/
/* entry_exists - funcao que verifica se um lexema de token ID se encontra na
                  tabela de simbolos */
bool entry_exists(string lex) {
  map <string, pair <string, string> >::iterator it;
  for (it = symbol_table.begin(); it != symbol_table.end(); it++) {
    if (it->first == lex) {
      return true;
    }
  }
  return false;
}

/******************************************************************************/
/* symbol_to_charClass - funcao que recebe um caractere da entrada e determina
                         sua classe de caractere */
int symbol_to_charClass(char c) {
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

/******************************************************************************/
/* show_error - funcao que indica que o scanner encontrou um lexema fora do
                padrao especificado */
void show_error(int code) {
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

/******************************************************************************/
/* make_token - funcao que recebe um estado de aceitacao e retorna o token
                representado por esse estado */
inline string make_token(int s) {
  if (s == 1 || s == 3 || s == 6) {
    return "Num";
  } else if (s == 8) {
    return "Literal";
  } else if (s == 9) {
    return "id";
  } else if (s == 11) {
    return "Comentario";
  } else if (s == 12) {
    return "EOF";
  } else if (s == 13 || s == 14 || s == 15 || s == 16) {
    return "OPR";
  } else if (s == 17) {
    return "RCB";
  } else if (s == 18) {
    return "OPM";
  } else if (s == 19) {
    return "AB_P";
  } else if (s == 20) {
    return "FC_P";
  } else if (s == 21) {
    return "PT_V";
  } else {
    return "ERRO";
  }
}