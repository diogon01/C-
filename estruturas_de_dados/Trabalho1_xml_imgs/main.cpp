#include <iostream>
#include <fstream>
#include <cstdint>
#include <stdexcept>
#include <string>
#include "array_stack.h"

using namespace structures;

int main () {
  
  ArrayStack<std::string > *validar = new ArrayStack<std::string >();
  std::string line;
  char xmlfilename[100];
  char c;
  std::cin >> xmlfilename;
  std::ifstream myfile (xmlfilename);
  //! char que vai receber os caracteres do XML 
  char c;
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
        if(line.at(0) == '/') {
          if(validar->top() != line) {
            throw std::out_of_range("Uma marcação aberta deveria ter sido fechada antes");
          } else if (validar->top() == "") {
            throw std::out_of_range("Uma marcação foi fechada sem que tenha sido aberta antes");
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

/*  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  */
  return 0;
}
