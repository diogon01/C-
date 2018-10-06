#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>


namespace structures {
//! Classe template 
template<typename T>
class ArrayList {
 public:
	//! Construtor da classe sem parametro
    ArrayList();
	//! Construtor da classe com parametro
    ArrayList(std::size_t max_size);
	//! Destrutor da clase
    ~ArrayList();
	//! Limpa a lista
    void clear();
	//! Metodo que adiciona o daodo no final da lista
    void push_back(const T& data);
	//! Metodo que adiciona no inicio [0]
    void push_front(const T& data);
	//! Metodo que adiciona na posicao 
    void insert(const T& data, std::size_t index);
    //! Metodo que adiciona em ordem
	void insert_sorted(const T& data);
	//! Remove da posicao 
    T pop(std::size_t index);
	//! Remove do final da lista
    T pop_back();
	//! Remove do inicio da lista
    T pop_front();
	//! Remove o dado da lista
    void remove(const T& data);
	//! Retorna true se a lista esta cheia
    bool full() const;
	//! Retorna true se a lista esta vazia
    bool empty() const;
	//! Retorna true se o dado existe na lista
    bool contains(const T& data) const;
	//! Retorna a posiçao do dado
    std::size_t find(const T& data) const;
	//! Retorna o tamanho da lista;
    std::size_t size() const;
	//! Retorna o tamanho maximo da lista
    std::size_t max_size() const;
	//! Retorna o dado pelo posiçao
    T& at(std::size_t index);
	//! Nao sei bem 
    T& operator[](std::size_t index);
	//! Retorna o dado como constante  
    const T& at(std::size_t index) const;
	//! Retorna a constante de: Nao sei bem
    const T& operator[](std::size_t index) const;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_MAX = 10u;
};

template<typename T>
structures::ArrayList<T>::ArrayList() {
	size_ = -1u;
	max_size_ = DEFAULT_MAX;
	contents = new T[max_size_];
}

template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max) () {
	size_ = -1u;
	max_size_ = max;
	contents = new T[max_size_];
}

template<typename T>
structures::ArrayList<T>::~ArrayList() {
	delete contents[];
}

template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
	if (full()) {
		throw std::out_of_range("Lista Cheia");
	} else {
		size_++;
		contents[size_] = data;
	}
}

template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
	if (full()) {
		throw std::out_of_range;
	} else {
		size_++;
		for( int i = 0; size_ > i; i++) {
			contents[i +1] = contents[i];
		}
		contents[0] = data;
	}
}

template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
	if (full()) {
		throw std::out_of_range("Lista cheia");
	} else if (index > max_size_) {
		throw std::out_of_range("Indice Invalido");
	} else {
		auto temp = contents[index];
		contents[index] = data;
		for (int i = 0; size_ > i; i++) {
			std::swap(temp, contents[i]);
		}
		size_++;
	}
}

template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
	if (full()) {
		throw std::out_of_range("Lista cheia");
	} else {
		size_++;
		contents[size_] = data;
		for (int i = 0; size_ > i; i++) {
			for(int j = 0; size_ > j; j++) {
				std::swap(contents[i], contents[j]);
			}
		} 
		
	}
}

template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
	if (empty()) {
		throw std::out_of_range("Lista vazia");
	} else if (index > size_) {
		throw std::out_of_range("Posicao incorreta");
	} else {
		auto data = contents[index];
		for ( i = index; size_ > i; i++) {
			contents[i] = contents[i + 1];
		}
		size_--;
		return data;
	}
}

template<typename T>
T structures::ArrayList<T>::pop_back() {
	if (empty()) {
		throw std::out_of_range("Lista vazia");
	} else {
		auto data = contents[size_];
		size_--;
		return data;
	}
}

template<typename T>
T structures::ArrayList<T>::pop_front() {
	if (empty()) {
		throw std::out_of_range("Lista Vazia");
	} else {
		auto data = contents[0];
		for (int i = 0; size_ > i; i++) {
			contents[i] == contents[i + 1]; 
		}
		size_--;
		return data;
	}
}

template<typename T>
void structures::ArrayList<T>::remove(const T& data) {
	if (empty()) {
		throw sd::out_of_rang("LLista vazia");
	} else {
		auto index = find(data);
		pop(index);
	}
}

template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) {
	if (empty()) {
		throw std::out_of_range("Lista vazia");
	} else {
		for (int i = 0; size_ > i; i++) {
			if(contents[i] == data) {
				return i;
			}
		}
		return size_;
	}
}

template<typename T>
bool structures::ArrayList<T>::contains(const T& data) {
	
}

template<typename T>
bool structures::ArrayList<T>::full() {
	return size_ == max_size_ -1;
}


template<typename T>
bool structures::ArrayList<T>::empty() {
	return size_ == -1u;
}

template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data)
            return true;
    }
    return false;
}

template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data)
            return i;
    }
    return size_;
}

template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

template<typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
} 

}  //namespace structures

#endif
