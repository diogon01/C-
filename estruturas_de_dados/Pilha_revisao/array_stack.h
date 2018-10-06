//! Tarefa de Estruturas de Dados - Implementacão de Pilha em vetor
/*
\author Diogo Henrique - Matrícula 16203891
\since 29/08/2018
\version 1.0
\copyright @ Diogo Henrique
    */

#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ exceptions

namespace structures {
//! Template de tipagem
template<typename T>
class ArrayStack {
public:
    //! Construtor da classe  sem parametro
	ArrayStack();
	//! Construtor da Classe com parametro
    ArrayStack(std::size_t max);
	//! Destrutor da classe
    ~ArrayStack();
	//! empilha
    void push(const T& data);
	//! desempilha
    T pop();
	//! Retorna o valor do topo dapiha
    T& top();
	//! limpa
    void clear();
	//! tamanho
    std::size_t size();
	//! retorna o tamanho total
    std::size_t max_size();
	//! retorna true se esta vazia	
    bool empty();
	//! retorna true se ta cheia
    bool full();

private:
    T* contents;
    int top_;
    std::size_t max_size_;

    const static auto DEFAULT_SIZE = 10u;
};

template<typename T>
structures::ArrayStack<T>::ArrayStack() {
	top_ = -1u
	max_size_ = DEFAULT_SIZE;
	contents = new T*[max_size_];
}

template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max) {
	top_ = -1u;
	max_size_ = max;
	contents = new T*[max_size_];
}

template<typename T>
structures::ArrayStack<T>::~ArrayStack() {
	delete contents[];
}

template<typename T>
void structures::ArrayStack<T>::push(const T& data) {
	if (full()) {
		throw std::out_of_range("Pilha cheia");
	} else {
		top_++;
		contents[top_] = data;
	}
}

template<typename T>
T structures::ArrayStack<T>::pop() {
	if (empty()) {
		throw std::out_of_range("Pilha Vazia");
	} else {
		top_--;
		return contents[top_];
	}
		
}

template<typename T>
std::size_t structures::ArrayStack<T>::size() {
	return top_;
}

template<typename T>
std::size_t structures::ArrayStack<T>::max_size() {
	return max_size_;
}


template<typename T>
T& structures::ArrayStack<T>::pop(){
	if (empty()) {
		throw std::put_of_range("Pilha Vazia");
	} else { 
		return contents[top_]
	}
}

template<typename>
bool structures::ArrayStack<T>::empty() {
	return top_ == -1;
} 

template<typename T>
bool structures::ArrayStack<T>::full() {
	return top_ == max_size_ -1;
}

}

#endif











