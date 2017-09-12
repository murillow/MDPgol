// Lendo o arquivo de texto de exemplo

#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
    char caracter, pause;

    //Cria um fluxo de arquivo a partir de "texto.alg"
    ifstream myfile ("texto.alg");

    //Testa se foi possivel abrir o arquivo
    if(myfile.is_open())
    {
        //Loop de leitura de caracteres
        while(myfile.get(caracter))
        {
            //Imprime o caracter de uma linha
            if(caracter != '\n')
              cout << caracter;
            //Pausa a cada linha esperando um "enter"
            else
              cin.get(pause);
        }
        //Fecha o fluxo de arquivo
        myfile.close();
    }
    //Se o arquivo não for aberto
    else
      cout << "Impossivel abrir o arquivo!\n";

    return 0;
}
