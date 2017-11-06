#include <bits/stdc++.h>

using namespace std;

#define SIGMA_MAX_STATES 22
#define SIGMA_MAX_CHAR_CLASSES 23
#define ACTION_MAX_STATES 59
#define ACTION_MAX_TERMINALS 21
#define TRANSITION_MAX_STATES 59
#define TRANSITION_MAX_NON_TERMINALS 14

int sigma[SIGMA_MAX_STATES][SIGMA_MAX_CHAR_CLASSES] = {
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

string action[ACTION_MAX_STATES][ACTION_MAX_TERMINALS] = {
};

string transition[TRANSITION_MAX_STATES][TRANSITION_MAX_NON_TERMINALS] = {
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
int token_to_code(string);
int nt_to_code(string);

/******************************************************************************/
/* main - driver principal */
int main(int argc, char **argv) {
  map <int, int> rhs_size; // |Beta|
  map <int, string> lhs; // <Num_Regra, LHS>
  map <int, string> Beta; // Num_Regra -> Beta
  pair <string, pair <string, string> > terminal; // <Lexema, Token, Atributo>
  int a, s;
  string t;
  stack <string> parser_stack;
  pair <string, string> state_terminal;

  lhs[1] = "P'";
  lhs[2] = "P";
  lhs[3] = "V";  
  lhs[4] = "LV";
  lhs[5] = "LV";
  lhs[6] = "D";
  lhs[7] = "TIPO";
  lhs[8] = "TIPO";
  lhs[9] = "TIPO";
  lhs[10] = "A";
  lhs[11] = "ES";
  lhs[12] = "ES";
  lhs[13] = "ARG";
  lhs[14] = "ARG";
  lhs[15] = "ARG";
  lhs[16] = "A";
  lhs[17] = "CMD";
  lhs[18] = "LD";
  lhs[19] = "LD";
  lhs[20] = "OPRD";
  lhs[21] = "OPRD";
  lhs[22] = "A";
  lhs[23] = "COND";
  lhs[24] = "CABECALHO";
  lhs[25] = "EXP_R";
  lhs[26] = "CORPO";
  lhs[27] = "CORPO";
  lhs[28] = "CORPO";
  lhs[29] = "CORPO";
  lhs[30] = "A";  

  Beta[1] = "P";
  Beta[2] = "inicio V A";
  Beta[3] = "varinicio LV";  
  Beta[4] = "D LV";
  Beta[5] = "varfim;";
  Beta[6] = "id TIPO;";
  Beta[7] = "int";
  Beta[8] = "real";
  Beta[9] = "lit";
  Beta[10] = "ES A";
  Beta[11] = "leia id;";
  Beta[12] = "escreva ARG;";
  Beta[13] = "literal";
  Beta[14] = "num";
  Beta[15] = "id";
  Beta[16] = "CMD A";
  Beta[17] = "id rcb LD;";
  Beta[18] = "OPRD opm OPRD";
  Beta[19] = "OPRD";
  Beta[20] = "id";
  Beta[21] = "num";
  Beta[22] = "COND A";
  Beta[23] = "CABECALHO CORPO";
  Beta[24] = "se (EXP_R) entao";
  Beta[25] = "OPRD opr OPRD";
  Beta[26] = "ES CORPO";
  Beta[27] = "CMD CORPO";
  Beta[28] = "COND CORPO";
  Beta[29] = "fimse";
  Beta[30] = "fim"; 
  
  rhs_size[1] = 1;  
  rhs_size[2] = 3;
  rhs_size[3] = 2;
  rhs_size[4] = 2;
  rhs_size[5] = 2;
  rhs_size[6] = 3;
  rhs_size[7] = 1;
  rhs_size[8] = 1;
  rhs_size[9] = 1;
  rhs_size[10] = 2;
  rhs_size[11] = 3;
  rhs_size[12] = 3;
  rhs_size[13] = 1;
  rhs_size[14] = 1;
  rhs_size[15] = 1;
  rhs_size[16] = 2;
  rhs_size[17] = 4;
  rhs_size[18] = 3;
  rhs_size[19] = 1;
  rhs_size[20] = 1;
  rhs_size[21] = 1;
  rhs_size[22] = 2;
  rhs_size[23] = 2;
  rhs_size[24] = 5;
  rhs_size[25] = 3;
  rhs_size[26] = 2;
  rhs_size[27] = 2;
  rhs_size[28] = 2;
  rhs_size[29] = 1;
  rhs_size[30] = 1;

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

  parser_stack.push("0");  

  if ((fd = fopen("texto.alg", "r")) == NULL) {
    cout << "Erro na abertura do programa fonte!\n";
  } else {
    do {
      terminal = scanner();
      s = atoi(parser_stack.top().c_str());
      a = token_to_code(terminal.second.first);
      if (action[s][a][0] == 'S') {
        t = action[s][a].substr(1, 2);
        parser_stack.push(terminal.second.first);
        parser_stack.push(t);
      } else if (action[s][a][0] == 'R') {
        int rule = atoi((action[s][a].substr(1, 2)).c_str());
        for (int i = 0; i < rhs_size[rule]; i++) {
          parser_stack.pop();
        }
        t = parser_stack.top();
        string A = lhs[rule];
        parser_stack.push(A);
        int u = atoi(t.c_str());
        int nt = token_to_code(A);
        string new_state = transition[u][nt];
        parser_stack.push(new_state);
        cout << A << " -> " << Beta[rule] << endl;
      } else if (action[s][a][0] == 'A') {
        return 0;
      } else {
        // erro();
      }
      // cout << terminal.first << ":" << terminal.second.first << endl;      
    } while (terminal.first != "EOF");
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
/* token_to_code - funcao que recebe um token do fluxo de tokens retornados pelo
                   scanner e retorna seu codigo interno */
int token_to_code(string t) {
  if (t == "inicio") return 0;
  if (t == "varinicio") return 1;
  if (t == "inicio") return 2;
  if (t == "inicio") return 3;
  if (t == "inicio") return 4;
  if (t == "inicio") return 5;
  if (t == "inicio") return 6;
  if (t == "inicio") return 7;
  if (t == "inicio") return 8;
  if (t == "inicio") return 9;
  if (t == "inicio") return 10;
  if (t == "inicio") return 11;
  if (t == "inicio") return 12;
  if (t == "inicio") return 13;
  if (t == "inicio") return 14;
  if (t == "inicio") return 15;
  if (t == "inicio") return 16;
  if (t == "inicio") return 17;
  if (t == "inicio") return 18;
  if (t == "inicio") return 19;
  else return 20;
}

/******************************************************************************/
/* nt_to_code - funcao que recebe um nao-terminal da gramatica do MDPgol e 
                retorna seu codigo interno */
int nt_to_code(string n) {
  return 0;
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