//! Tarefa de Estruturas de Dados - Implementacão de Pilha em vetor
/*
\author Diogo Henrique - Matrícula 16203891
\since 29/08/2018
\version 1.0
\copyright @ Diogo Henrique
    */

#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint>
#include <stdexcept>

namespace structures {
//!...
template<typename T>
class ArrayStack {
 public:
    //! Construtor da classe sem parametro */
    ArrayStack();
    //! Construtor da classe com parametro */
    explicit ArrayStack(std::size_t max);
    //! Destrutor da classe */
    ~ArrayStack();
    //! Método de empilhar os dados */
    void push(const T& data);
    //! Método de desempilhar */
    T pop();
    //! Método que retorna o valor no topo da pilha */
    T& top();
    //! Método que limpa a pilha  */
    void clear();
    //! Método que retorna o tamanho da pilha  */
    std::size_t size();
    //! Método que retorna o tamanho da max da pilha  */
    std::size_t max_size();
    //! Método que retorna true se pilha estiver vazia  */
    bool empty();
    //! Método que retorna true se pilha estiver cheia  */
    bool full();

 private:
    T* contents;
    int top_;
    std::size_t max_size_;

    static const auto DEFAULT_SIZE = 10u;
};

//! Construtor da classe sem parametro */
template<typename T>
structures::ArrayStack<T>::ArrayStack() {	 	  	 	     	    	   	  	     	   	     	 	
    top_ = 0;
    max_size_ = DEFAULT_SIZE;
    contents = new T[max_size_];
}

/** Novo construtor **/
template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
    top_ = 0;
    max_size_ = max;
    contents = new T[max_size_];
}

/** Destruction **/
template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
    delete[] contents;
}

//! Método de empilhar os dados */
template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
      if (full()) {
        throw std::out_of_range("Pilha esta cheia");
    } else {
        top_++;
        contents[top_] = data;
    }
}


/** Desempilha **/
template<typename T>
T structures::ArrayStack<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Pilha vazia");
    } else {	 	  	 	     	    	   	  	     	   	     	 	
        top_ = top_-1;
        return contents[top_];
    }
}

//! Retorna o valor do topo
template<typename T>
T& structures::ArrayStack<T>::top() {
    if (empty()) {
        throw std::out_of_range("Pilha Vazia");
    }
    return contents[top_ -1];
}

/** Limpa a Pilha **/
template<typename T>
void structures::ArrayStack<T>::clear() {
    top_ = -1;
}

/** Pega  o tamanho da pilha **/
template<typename T>
std::size_t structures::ArrayStack<T>::size() {
    return top_;
}

/** Pega o tamanho maximo da pilha**/
template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
     return max_size_;
}
/** Verifica se a pilha esta vazia **/
template<typename T>
bool structures::ArrayStack<T>::empty() {
     return top_ == -1;
}	 	  	 	     	    	   	  	     	   	     	 	

/** Verifica se a pilha esta cheia **/
template<typename T>
bool structures::ArrayStack<T>::full() {
    return top_ == max_size_;
}

}  // namespace structures


#endif










