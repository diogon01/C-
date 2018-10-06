//! Trabalho de Implementação I - processamento de XML com imagens binárias
/*
\author Diogo Henrique - Matricula 16203891
\since 29/09/2018
\version 1.0
\copyright @ Diogo Henrique
*/

#ifndef VALIDATOR_TAG
#define VALIDATOR_TAG

#include <cstdint>

namespace structures {
    //! Classe generica para validar as tags
    template<typename T>
    class ValidarTag {
    public:
        //! Construtor da classe sem parametro */
        ValidarTag();
        //! Construtor da classe com parametro */
        explicit ValidarTag(std::size_t max);
        //! Destrutor da classe */
        ~ValidarTag();
        //! Método de empilhar as tags XMLS */
        void push(const T& data);
        //! Método de desempilhar */
        T pop();
        //! Método que retorna o valor no topo da pilha */
        T& top();
        //! Método que limpa a pilha de tags XMLS */
        void clear();
        //! Retorna true se a pilha estiver vazia */
        bool empty();
        //! Retorna true ou false se a pilha estiver cheia */
        bool full();
        
    private:
        T* contents;
        int top_;
        std::size_t max_size_;

        static const auto DEFAULT_SIZE = 100u;
    };

    //! Construtor da classe sem parametro */
template<typename T>
structures::ValidarTag<T>::ValidarTag() {
    contents = new T[DEFAULT_SIZE];
    top_ = -1;
}

//! Construtor da classe com parametro */
template<typename T>
structures::ValidarTag<T>::ValidarTag(std::size_t max) {
    max_size_ = max;
    contents = new T[max];
    top_ = -1;
}

//! Destrutor da classe */
template<typename T>
structures::ValidarTag<T>::~ValidarTag() {
    delete[] contents;
}

//! Método de empilhar as tags XMLS */
template<typename T>
void structures::ValidarTag<T>::push(const T& data) {
    if (full()) {
        throw std::out_of_range("Pilha Cheia");
    } else {
        top_++;
        contents[top_] = data;
    }

}
//! Método que retorna o valor no topo da pilha */
template<typename T>
T& structures::ValidarTag<T>::top() {
    return contents[top_];
}
//! Método de desempilhar */
template<typename T>
T structures::ValidarTag<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Pilha vazia");
    } else {
        top_--;
        return contents[top_];
    }
}

//! Método que limpa a pilha de tags XMLS */
template<typename T>
void structures::ValidarTag<T>::clear() {
    top_ = 1;
}

//! Retorna true se a pilha de tags XMLS estiver cheia */
template<typename T>
bool structures::ValidarTag<T>::empty() {
    return top_ == -1u;
}

//! Retorna true ou false se a pilha estiver cheia */
template<typename T>
bool structures::ValidarTag<T>::full() {
    return top_ == max_size_ -1u;
}

} // namespace structures

#endif