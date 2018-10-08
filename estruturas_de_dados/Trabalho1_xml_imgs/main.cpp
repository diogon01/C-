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
#include "array_stack.h"

using namespace structures;

int main() {
    
    ArrayStack<std::string > *validar = new ArrayStack<std::string >();
    std::string line;
    char xmlfilename[100];
    char c;
    //std::cin >> xmlfilename;
    std::ifstream myfile ("dataset01.xml");
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
  
  
  //! Parte dois do trabalho verificar a vizinhança de 4 
  std::ifstream vizinhanca ("dataset01.xml");
  std::string valores, nome, data;
  int altura, largura;
  while (vizinhanca.get(c)){
    if(c == '<') {
      
      line = "";
      while (vizinhanca.get(c) && c != '>') {
        //! Concatenar melhor depois
        line = line + c;
      }

    }
    if (c == '>') {
      char fimtag = line.at(0);
      if (fimtag == '/') {
        if(line == "/name") {
          nome = valores;
        }
        if (line == "/height") {
          altura = std::stoi(valores);
        }
        if (line == "/width") {
          largura = std::stoi(valores);
        }
        valores = "";
        if (nome != "" && altura != NULL && 
        largura != NULL && line == "data" ) {
          while (vizinhanca.get(c) && c != '>') {
            
          }
        }
      }
    }
    if (c != '<' && c != '>' && c != '\n') {
      valores = valores + c;
    }
    
  }

  vizinhanca.close();     
  
  return 0;
}
