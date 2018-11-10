//! Tarefa de Estruturas de Dados - Implementacão de Pilha em vetor
/*
\author Diogo Henrique - Matrícula 16203891
\since 29/08/2018
\version 1.0
\copyright @ Diogo Henrique
    */

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <fstream>
#include "NoTrie.h"

using namespace std;


int main() {

    NoTrie<string> *noTrie = new NoTrie<string>();
    string filename;
    string word;
    string letra;
    char c;


    cin >> filename;  // entrada
    ifstream myfile (filename);
     //! Laço de repetiçao que vai rodar ate finalizar os colchetes
    while (myfile.get(c) ) {  // leitura das palavras ate' encontrar "0"
        
        //! Abertura de colchete
        if(c =='[') {
          letra = "";
          while (myfile.get(c) && c != ']') {
            //! Concatenar melhor depois
            letra = letra + c;
          }

          //! Colchete que encerra a palavra
          if(c == ']') {
            noTrie->insert(letra) 
          }
        }
        cin >> word;
        if (word.compare("0") == 0) {
            break;
        }
        cout << word << endl;
    }
    return 0;  
}
