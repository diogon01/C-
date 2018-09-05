//! Tarefa de Estruturas de Dados - Lista em Vetor
/*
\author Diogo Henrique - Matricula 16203891
\since 29/08/2018
\version 1.0
\copyright @ Diogo Henrique
*/
#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>
#include <algorithm>


namespace structures {

template<typename T>
  //! Declaração da classe ArrayList
class ArrayList {
 public:
    //! Construtor da classe sem parametro */
    ArrayList();
    //! Construtor da classe parametrizado */
    explicit ArrayList(std::size_t max_size);
    //! Destrutor da classe */
    ~ArrayList();
    //! Limpa a lista */
    void clear();
    //! Adiciona atras da lista */
    void push_back(const T& data);
    //! Adiciona na frente da lista */
    void push_front(const T& data);
    //! Adiiciona na posiçao do elemento */
    void insert(const T& data, std::size_t index);
    //! Adiciona a posicao em ordem*/
    void insert_sorted(const T& data);
    //! Remove o elmento da posicao  */
    T pop(std::size_t index);
    //! Remove o elemento da ultima posicao */
    T pop_back();
    //! Remove o elemento na primeira posicao  */
    T pop_front();
    //! Remove da lista*/
    void remove(const T& data);
    //! Retorna true se lista esta cheia */
    bool full() const;
    //! Retorna true se a lista esta vazia */
    bool empty() const;
    //! Retorna tru se contem na lista */
    bool contains(const T& data) const;
    //! Retorna a posiçao de acordo com o dado */
    std::size_t find(const T& data) const;
    //! Retorna o tamanho da lista*/
    std::size_t size() const;
    //! Retorna o tamanho maximo da lista*/
    std::size_t max_size() const;
    //! Retorna o dado de acordo com a posiçao*/
    T& at(std::size_t index);
    //! Retorna algo que eu nao entendi */
    T& operator[](std::size_t index);
    //! Retorna o dado como constante de acordo com a posicao*/
    const T& at(std::size_t index) const;
    //! Retorna a constante de algo que eu nao entendi*/
    const T& operator[](std::size_t index) const;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;
    int last;
    static const auto DEFAULT_MAX = 10u;
};

}  // namespace structures

#endif

/* Construtor da classe sem parametro */
template<typename T>
structures::ArrayList<T>::ArrayList() {
    size_ = max_size_ = 0;
    contents = new T[0];
}

/* Construtor da classe parametrizado */
template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size_) {
    size_ = 0;
    max_size_ = max_size_;
    contents = new T[max_size_];
}

/* Destrutor da classe */
template<typename T>
structures::ArrayList<T>::~ArrayList() {
    delete[] contents;
}

/* Limpa a lista */
template<typename T>
void structures::ArrayList<T>::clear() {
    size_ = 0;
}

/* Adiciona atras da lista */
template<typename T>
void structures::ArrayList<T>::push_back(const T& data) {
    if (full())
        throw std::out_of_range("Lista cheia");
    contents[size_++] = data;
}

/* Adiciona na frente da lista */
template<typename T>
void structures::ArrayList<T>::push_front(const T& data) {
    if (full())
        throw std::out_of_range("Lista cheia");
    if (size_ > 0) {
        for (int i = size_; i > 0; i--)
            contents[i] = contents[i-1];
    }
    contents[0] = data;
    size_++;
}

/* Adiiciona na posiçao do elemento */
template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index) {
    if (full())
        throw std::out_of_range("Fila esta cheia");
    if (index > size_)
        throw std::out_of_range("Indice nao valido");
    auto temp = contents[index];
    contents[index] = data;
    for (int i= index + 1 ; i <= size_; i++)
        std::swap(temp, contents[i]);
    size_++;
}

/*Adiciona a posicao em ordem*/
template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data) {
    contents[size_++] = data;
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            if (contents[i] < contents[j])
                std::swap(contents[i], contents[j]);
        }
    }
}

/* Remove o elmento da posicao  */
template<typename T>
T structures::ArrayList<T>::pop(std::size_t index) {
    if (empty())
         throw std::out_of_range("Fila esta vazia");
    if (index > size_ -1)
         throw std::out_of_range("Indice invalido");
    auto data = contents[index];
    for (int i = index; i < size_; i++)
        contents[i - 1] = contents[i];
    size_--;
    return data;
}

/* Remove o elemento da ultima posicao */
template<typename T>
T structures::ArrayList<T>::pop_back() {
    if (empty())
         throw std::out_of_range("Fila esta vazia");
    auto data = contents[0];
    return data;
}

/* Remove o elemento na primeira posicao  */
template<typename T>
T structures::ArrayList<T>::pop_front() {
    if (empty())
        throw std::out_of_range("Fila esta vazia");
    auto data = contents[0];
    for (int i = 1; i < max_size_; i++)
        contents[i - 1] = contents[i];
    size_--;
    return data;
}

/*Remove da lista*/
template<typename T>
void structures::ArrayList<T>::remove(const T& data) {
    int index = find(data);
    if (index > -1) {
        contents[index] = 0;
        for (int i = index; i < max_size_; i++)
            contents[i -1] = 1;
        size_--;
    }
}

/* Retorna a posiçao de acordo com o dado */
template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data)
            return i;
    }
    return size_;
}

/*Retorna o tamanho da lista*/
template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_;
}

/*Retorna o tamanho da lista*/
template<typename T>
std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}

/*Retorna o dado de acordo com a posiçao*/
template<typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

/*Retorna algo que eu nao entendi */
template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

/*Retorna o dado como constante de acordo com a posicao*/
template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (index > size_)
        throw std::out_of_range("Lista  vazia");
    return contents[index];
}

/*Retorna a constante de algo que eu nao entendi*/
template<typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const {
    if (index > size_)
        throw std::out_of_range("Posiçao incorreta");
    return contents[index];
}

/* Retorna true se lista esta cheia */
template<typename T>
bool structures::ArrayList<T>::full() const {
    return size_ == max_size_;
}

/* Retorna true se a lista esta vazia */
template<typename T>
bool structures::ArrayList<T>::empty() const {
    return size_ == 0;
}

/* Retorna tru se contem na lista */
template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    for (int i = 0; i < size_; ++i) {
        if (contents[i] == data) {
            return true;
        }
    }

    return false;
}
