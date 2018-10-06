#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {
//! Classe Template
template<typename T>
class ArrayQueue {
 public:
	//! Construtor sem parametro
    ArrayQueue();
	//! Construtor com parametro
    ArrayQueue(std::size_t max);
	//! Destrutor da classe
    ~ArrayQueue();
	//! Metodo que adiciona na fila
    void enqueue(const T& data);
	//! Metodo que remove da fila
    T dequeue();
	//! Retona o primeiro da fila
    T& back();
	//! Metodo que limpa a fila
    void clear();
	//! Metodo que retorna o tamanho da fila
    std::size_t size();
	//! Metodo que retorna o tamanho maximo da fila
    std::size_t max_size();
	//! Retorna True se a fila esta vazia
    bool empty();
	//! Retorna true de fila esta cheia;
    bool full();

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_SIZE = 10u;
};

template<typename T>
structures::ArrayQueue<T>::ArrayQueue() {
	size_ = -1u;
	max_size_ = DEFAULT_SIZE;
	contents = new T[max_size_];
}

template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max) {
	size_ = -1u;
	max_size_ = max;
	contents = new T[contents];
}

template<typename T>
structures::ArrayQueue<T>::~ArrayQueue() {
	delete	contents[];
}

template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data) {
	if (full()) {
		throw std::out_of_range("Lista Cheia");
	} else {
		size_++;
		contents[size_] = data;
	}
}

template<typename T>
T structures::ArrayQueue<T>::dequeue() {
	if(empty()) {
		throw std::out_of_range("Fila Vazia");
	} else {
		size_--;
		auto aux = contents[0];
		
		for( int i = 0; size_ > max_size_; i++) {
			contents[i] = contents[i + 1] 
		}
		return aux;
	}
}

template<typename T>
T& structures::ArrayQueue<T>::back() {
	if(empty()) {
		throw std::out_of_range("Fila Vazia");
	} else {
		return contents[0];
	}
}

template<typename T>
void structures::ArrayQueue<T>::clear() {
	size_ = -1u;
}

template<typename T>
std::size_t structures::ArrayQueue<T>::size() {
	return size_;
}

template<typename T>
std::size_t structures::ArrayQueue<T>::max_size() {
	return max_size_;
}

template<typename T>
bool structures::ArrayQueue<T>::full() {
	return size_ == max_size_ -1;
}

template<typename T>
bool structures::ArrayQueue<T>::empty() {
	return size_ == -1u;
}

}  //namespace structures

#endif
