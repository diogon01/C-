//! Tarefa de Estruturas de Dados - Fila Encadeada
/*
\author Diogo Henrique - Matricula 16203891
\since 20/09/2018
\version 1.0
\copyright @ Diogo Henrique
*/
#ifndef  STRUCTURES_LINKED_QUEUE_H
#define STRUCTURES_LINKED_QUEUE_H

#include <cstdint>
#include <stdexcept>

namespace structures {
//!...
template<typename T>
class LinkedQueue {
 public:
    //! Construtor da classe sem parametro */
    LinkedQueue();
    //! Destrutor da classe */
    ~LinkedQueue();
    //! Limpa fila encadeada */
    void clear();
    //! Adiciona na fila */
    void enqueue(const T& data);
    //! Remove da fila */
    T dequeue();
    //! Primeiro dado da fila */
    T& front() const;
    //! Ultimo dado da fila */
    T& back() const;
    //! Retorna true se a fila esta vazia */
    bool empty() const;
    //! Retorna o tamanho da fila */
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

    Node* head;  // nodo-cabeça
    Node* tail;  // nodo-fim
    std::size_t size_;  // tamanho
};

/* Construtor da classe sem parametro */
template<typename T>
structures::LinkedQueue<T>::LinkedQueue() {
    head = nullptr;
    tail = nullptr;
    size_ = 0u;
}

/* Destrutor da classe */
template<typename T>
structures::LinkedQueue<T>::~LinkedQueue() {
    clear();
}

/*  Limpa fila encadeada */
template<typename T>
void structures::LinkedQueue<T>::clear() {
    Node *anterior, *atual;
    atual = head;
    while (atual != nullptr) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
    }
    size_ = 0;
    head = nullptr;
    tail = nullptr;
}

/* Adiciona na fila encadeada */
template<typename T>
void structures::LinkedQueue<T>::enqueue(const T& data) {
    Node *novoElemento = new Node(data, nullptr);
    if (empty()) {
        head = novoElemento;
        tail = novoElemento;
    } else {
        tail->next(novoElemento);
    }
    tail = novoElemento;
    size_++;
}

/* Remove da fila */
template<typename T>
T structures::LinkedQueue<T>::dequeue() {
    T retorno;
    Node *elimina;
    if (empty()) {
        throw std::out_of_range("Fila vazia");
    } else {
        elimina = head;
        retorno = elimina->data();
        head = elimina->next();
        if (size_ == 1) {
            tail = nullptr;
        }
        --size_;
        delete elimina;
        return retorno;
    }
}

/* Primeiro dado da fila */
template<typename T>
T& structures::LinkedQueue<T>::front() const {
    if (empty()) {
        throw std::out_of_range("Fila esta vazia");
    }
    return head->data();
}

/* Ultimo dado da fila */
template<typename T>
T& structures::LinkedQueue<T>::back() const {
    if (empty()) {
        throw std::out_of_range("Fila esta vazia");
    }
    return tail->data();
}
/* Retorna true se a fila esta vazia */
template<typename T>
bool structures::LinkedQueue<T>::empty() const {
    return size_ == 0;
}

/* Retorna o tamanho da fila */
template<typename T>
std::size_t structures::LinkedQueue<T>::size() const {
    return size_;
}

}  // namespace structures

#endif

