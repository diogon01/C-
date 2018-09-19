//! Tarefa de Estruturas de Dados - Lista em Vetor
/*
\author Diogo Henrique - Matricula 16203891
\since 29/08/2018
\version 1.0
\copyright @ Diogo Henrique
*/
#ifndef STRUCTURES_STRING_LIST_H
#define STRUCTURES_STRING_LIST_H

#include <cstdint>
#include <stdexcept>
#include <cstring>
#include <algorithm>



namespace structures {


//! Declaração da classe ArrayList string.
template<typename T>
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
    //! Adiciona a posicao em ordem */
    void insert_sorted(const T& data);
    //! Remove o elmento da posicao  */
    T pop(std::size_t index);
    //! Remove o elemento da ultima posicao */
    T pop_back();
    //! Remove o elemento na primeira posicao  */
    T pop_front();
    //! Remove da lista usando o parametro data */
    void remove(const T& data);
    //! Retorna true se lista esta cheia */
    bool full() const;
    //! Retorna true se a lista esta vazia */.
    bool empty() const;
    //! Retorna true se contem a data na lista */
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

    static const auto DEFAULT_MAX = 10u;
};

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
        contents[index] = nullptr;
        for (int i = index; i < max_size_; i++)
            contents[i] = contents[i + 1];
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

/* Retorna o tamanho da lista*/
template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_;
}

/* Retorna o tamanho da lista*/
template<typename T>
std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}

/* Retorna o dado de acordo com a posiçao*/
template<typename T>
T& structures::ArrayList<T>::at(std::size_t index) {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

/* Retorna algo que eu nao entendi */
template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

/* Retorna o dado como constante de acordo com a posicao*/
template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (index > size_)
        throw std::out_of_range("Lista  vazia");
    return contents[index];
}

/* Retorna a constante de algo que eu nao entendi*/
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


/* Retorna se contem na lista passando o ponteiro dado por parâmetro */
template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const {
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data)
            return true;
    }
    return false;
}

//! ...
//! ArrayListString e' uma especializacao da classe ArrayList
class ArrayListString : public ArrayList<char *> {
 public:
    ArrayListString();
    explicit ArrayListString(std::size_t max_size);
    ~ArrayListString();

    //! ...
    void clear();
    //! ...
    void push_back(const char *data);
    //! ...
    void push_front(const char *data);
    //! ...
    void insert(const char *data, std::size_t index);
    //! ...
    void insert_sorted(const char *data);
    //! ...
    char *pop(std::size_t index);
    //! ...
    char *pop_back();
    //! ...
    char *pop_front();
    //! ...
    void remove(const char *data);
    //! ...
    bool contains(const char *data) const;
    //! ...
    std::size_t find(const char *data);

 private:
    ArrayList<char *> *list;
    static const auto DEFAULT_MAX = 100u;
};

/* Construtorda classe com parametro */
structures::ArrayListString::ArrayListString(std::size_t max_size) {
    list = new ArrayList<char*>(max_size);
}

/* Destrutor da classe */
structures::ArrayListString::~ArrayListString() {
    delete list;
}

/* Metodo que limpa a lista de String */
void structures::ArrayListString::clear() {
    list->clear();
}

/* Adiciona atraz da lista de String */
void structures::ArrayListString::push_back(const char *data) {
    list->push_back(const_cast<char*>(data));
}

/* Adiciona elemento na frente da lista */
void structures::ArrayListString::push_front(const char *data) {
    list->push_front(const_cast<char*>(data));
}

/* Adiciona na lista de String de acordo a posiçao index */
void structures::ArrayListString::insert(const char *data, std::size_t index) {
    list->insert(const_cast<char*>(data), index);
}

/* Adiciona o elemento em ordem */
void structures::ArrayListString::insert_sorted(const char *data) {
    list->insert_sorted(const_cast<char*>(data));
}

/* Remove a primeira string do elemento? */
char* structures::ArrayListString::pop(std::size_t index) {
    return list->pop(index);
}

/* Pega a primeiro char da string  */
char* structures::ArrayListString::pop_back() {
    return list->pop_back();
}

/* Pega ultimo char da string  */
char* structures::ArrayListString::pop_front() {
    return list->pop_front();
}

/* Remover String da Lista passando o ponteiro *data no parametro */
void structures::ArrayListString::remove(const char *data) {
    list->remove(const_cast<char*>(data));
}

/** Método que verifica se a lista contém o elemento dado por parâmetro */
bool structures::ArrayListString::contains(const char* data) const {
    return list->contains(const_cast<char*>(data));
}


/* Retorna o indice do dado de acordo com a posiçao */
std::size_t structures::ArrayListString::find(const char *data) {
    return list->find(const_cast<char*>(data));
}

}  // namespace structures

#endif
