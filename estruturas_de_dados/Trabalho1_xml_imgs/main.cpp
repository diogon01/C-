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
#include <fstream>
#include "array_stack.h"

using namespace structures;

int main() {
    
    ArrayStack<std::string > *validar = new ArrayStack<std::string >();
    std::string line;
    char xmlfilename[100];
    char c;
    std::cin >> xmlfilename;
    std::ifstream myfile (xmlfilename);
  //! Laço de repetiçao que vai rodar ate finalizar as tags
  while (myfile.get(c)) {
    //! Abertura de Tag XML
    if (c == '<') {
      line = "";
      while (myfile.get(c) && c != '>' ) {
        //! Concatenar melhor depois
        line = line + c;
      }

      //! Final da tag<XML>
      if (c == '>') {
        char teste = line.at(0);
        if(teste == '/') {
          std::string ultimo = "/" + validar->top();
          if(ultimo != line) {
            throw std::out_of_range("Uma marcação aberta deveria ter sido fechada antes");
          }
          validar->pop();   
        } else {
          validar->push(line);
        }
      }  
    }     
  };
  //! Verifica se a fila esta vazia         
  if(!validar->empty()) {
    throw std::out_of_range("Uma existem tags ainda para serem validadas");
  }
  myfile.close();          
    
    
    return 0;
}
