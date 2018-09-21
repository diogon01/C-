//! Tarefa de Estruturas de Dados - Pilha Encadeada
/*
\author Diogo Henrique - Matricula 16203891
\since 20/09/2018
\version 1.0
\copyright @ Diogo Henrique
*/
#ifndef STRUCTURES_LINKED_STACK_H
#define STRUCTURES_LINKED_STACK_H

#include <cstdint>
#include <stdexcept>

namespace structures {
//!...
template<typename T>
class LinkedStack {
 public:
    //! Construtor da classe sem parametro */
    LinkedStack();
    //! Destrutor da classe */
    ~LinkedStack();
    //! limpa pilha */
    void clear();
    //! empilha */
    void push(const T& data);
    //! desempilha
    T pop();
    //! dado no topo
    T& top() const;
    //! pilha vazia
    bool empty() const;
    //! tamanho da pilha
    std::size_t size() const;

 private:
    class Node {  // Elemento
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* top_;  // nodo-topo
    std::size_t size_;  // tamanho
};

/* Construtor da classe sem parametro */
template<typename T>
structures::LinkedStack<T>::LinkedStack() {
    size_ = 0;
    top_ = nullptr;
}

/* Destrutor da classe */
template<typename T>
structures::LinkedStack<T>::~LinkedStack() {
    clear();
}

/* limpa a pilha */
template<typename T>
void structures::LinkedStack<T>::clear() {
     Node *atual, *anterior;
     atual = top_;
     while (atual != nullptr) {
         anterior = atual;
         atual = atual->next();
         delete anterior;
     }
     size_ = 0u;
     top_ = nullptr;
}

/* Adciona na pilha */
template<typename T>
void structures::LinkedStack<T>::push(const T& data) {
     Node *novoElemento = new Node(data, top_);
      if (novoElemento == nullptr) {
                throw std::out_of_range("Erro: a pilha está cheia!");
            } else {
                top_ = novoElemento;
                size_ += 1;
            }
}

/* Remove da pilha */
template<typename T>
T structures::LinkedStack<T>::pop() {
    if (empty()) {
            throw std::out_of_range("Erro: a pilha está vazia!");
        } else if (size() == 1) {
            Node* retirado = top_;
            T valor = retirado->data();
            top_ = nullptr;
            delete retirado;
            size_ -= 1;
            return valor;
            } else {
                Node *retirado, *anterior;
            T valor;
            retirado = top_;
            anterior = retirado->next();
            valor = retirado->data();
            top_ = anterior;
            size_ -= 1;
            delete retirado;
            return valor;
        }
}

/* Retorna o dado no topo da pilha */
template<typename T>
T& structures::LinkedStack<T>::top() const {
     if (empty()) {
         throw std::out_of_range("Pilha vazia");
     }
     return top_->data();
}

/* Retorna true se a pilha esta vazia */
template<typename T>
bool structures::LinkedStack<T>::empty() const {
     return size_ == 0u;
}

/* Retorna o tamanho da pilha */
template<typename T>
std::size_t structures::LinkedStack<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
