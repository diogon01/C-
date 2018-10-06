//! Tarefa de Estruturas de Dados - Implementac�o de Pilha em vetor
/*
\author Diogo Henrique - Matr�cula 16203891
\since 29/08/2018
\version 1.0
\copyright @ Diogo Henrique
*/

	#ifndef STRUCTURES_ARRAY_QUEUE_H
	#define STRUCTURES_ARRAY_QUEUE_H

	#include <cstdint> // std::size_t
	#include <stdexcept> // C++ Exceptions

namespace structures {

	template<typename T>
	class ArrayQueue {
	public:
		ArrayQueue();

		ArrayQueue(std::size_t max);

		~ArrayQueue();

		void enqueue(const T& data);

		T dequeue();

		T& back();

		void clear();

		std::size_t size();

		std::size_t max_size();

		bool empty();

		bool full();

	private:
		T* contents;
		std::size_t size_;
		std::size_t max_size_;

		const static auto DEFAULT_SIZE = 10u;
	};

}

#endif

/*Construtor da classe */
template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max){
	size_ = 0;
	max_size_ = max
		contents = new T[max_size_];
}

/*Destruidor da classe XD*/
template<typename T>
structures::ArrayQueue<T>::~ArrayQueue(){
	delete[] contents;
}

/* Adicionar dados na fila*/
template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data){
	if(full()){
		throw std::out_of_range("A fila esta cheia");
	}
	return contents[size_++] = data;
}

/*Remove o dado da fila */
template <typename T>
T structures::ArrayQueue<T>::dequeue(){
	if(empty()){
		throw std::out_of_range("A fila esta vazia");
	}
	else{
		auto temp = contents[0];
		for (int i = 0; i < size_; i++){
			contents[i] = contents[i+1];
		}
		size_--;
		return temp;
	}

}

/* Remove o ultimo da fila */
template<typename T>
T& structures::ArrayQueue<T>::back(){
	if(empty()){
		throw std::out_of_range("Fila esta vazia");
	}
	return contents[size_--];
}

/*Limpa toda a data da fila */
template<typename T>
void structures::ArrayQueue<T>::clear(){
	size_ = 0;
}

/* Pega o tamanho da fila */
template<typename T>
std::size_t structures::ArrayQueue<T>::size(){
	return size_;
}

/* Pega o tamanho maximo da fila */
template<typename T>
std::size_t structures::ArrayQueue<T>::max_size(){
	return max_size_;
}

/* Verifica se a fila esta vazia*/
template<typename T>
bool structures::ArrayQueue<T>::empty(){
	return size_ == 0;
}

/*Metodo para verificar se sa fila esta cheia*/
template<typename T>
bool structures::ArrayQueue<T>::full(){
	return size_ == max_size_;
}




