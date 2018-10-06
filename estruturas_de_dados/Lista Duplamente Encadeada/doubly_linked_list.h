//! Tarefa de Estruturas de Dados - Lista Duplamente Encadeada
/*
\author Diogo Henrique - Matricula 16203891
\since 28/09/2018
\version 1.0
\copyright @ Diogo Henrique
*/
#ifndef STRUCTURES_DOUBLY_LINKED_LIST_H
#define STRUCTURES_DOUBLY_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

//!...
template<typename T>
class DoublyLinkedList {
 public:
    //! Construtor da classe sem parametro */
    DoublyLinkedList();
    //! Destrutor da classe */
    ~DoublyLinkedList();
    //! limpa lista */
    void clear();
    //! insere no fim
    void push_back(const T& data);
    //! insere no início
    void push_front(const T& data);
    //! insere na posição
    void insert(const T& data, std::size_t index);
    //! insere em ordem
    void insert_sorted(const T& data);
    //! retira da posição
    T pop(std::size_t index);
    //! retira do fim
    T pop_back();
    //! retira do início
    T pop_front();
    //! retira específico
    void remove(const T& data);
    //! Retorna true se lista esta  vazia
    bool empty() const;
    //! Retorna true se o dado contém
    bool contains(const T& data) const;
    //! Acesso um elemento da posição (checando limites)
    T& at(std::size_t index);
    //! getter constante a um elemento
    const T& at(std::size_t index) const;
    //! Retorna a posição de um dado
    std::size_t find(const T& data) const;
    //! Retorna o tamanho da lista
    std::size_t size() const;
private:

    class Node {
    public:
        Node(const T& data);
        Node(const T& data, Node* next);
        Node(const T& data, Node* prev, Node* next);

        T& data()
        const T& data() const

        Node* prev()
        const Node* prev() const

        void prev(Node* node)

        Node* next()
        const Node* next() const

        void next(Node* node)
    private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    Node* head;  // primeiro da lista
    Node* tail;  // ultimo da lista
    std::size_t size_;
};

//! Construtor da classe sem parametro */
template<typename T>
structures::DoublyLinkedList<T>::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size_ = 0;
}

//! Destrutor da classe */
template<typename T>
structures::DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

//! limpa lista */
template<typename T>
void structures::DoublyLinkedList<T>::clear() {
    Node *atual, *anterior;
        atual = head;
        while (atual != nullptr) {
            anterior = atual;
            atual = atual->next();
            delete anterior;
        }
        size_ = 0u;
        head = nullptr;
}

//! insere no fim
template<typename T>
void structures::DoublyLinkedList<T>::push_back(const T& data) {
    insert(data, size_);
}

//! insere no início
template<typenameT>
void structures::DoublyLinkedList<T>::push_front(const T& data) {
    Node *novoElemento = new Node(data, nullptr, this.head);
    if(novoElemento == nullptr) {
        throw std::out_of_range("A lista está cheia")
    }
    head = novoElemento;
    if(novoElemento->next() != nullptr) {
        novoElemento->next()->prev();
    }
    size_++;
}

//! insere na posição
template<typenameT>
void structures::DoublyLinkedList<T>::insert(const T& data, std::size_t index) {
    Node *anterior, *novoElemento;
    if (index > size_) {
        throw std::out_of_range("posiçao invalida")
    } 
    else if (index == 0) {
      novoElemento = new Node(data);
      if(novoElemento == nullptr) {
          throw std::out_of_range("A lista está cheia");
      } else {
          anterior = head;
          for (auto i = 1u; i < index; ++i) {
              anterior = anterior->next();
          }
          novoElemento->next(anterior->next(novoElemento));
          if(novoElemento != nullptr) {
              novoElemento->next()->prev(novoElemento);
          }
          anterior->next(novoElemento);
          size_++;
        }  
    }
}

//! insere em ordem
template<typename T>
void structures::DoublyLinkedList<T>::insert_sorted(const T& data) {
    Node *atual;
    std::size_t indice;
    if(empty()) {
        return push_front(data);
    } else {
        atual = head;
        indice = 0;
        while(atual->next() !=nullptr && data > atual->data()) {
            atual = atual->next();
            indice++;
        }
        if(data > atual->data()) {
            return insert(data, indice +1);
        } else {
            return insert(data, indice);
        }
    }
}

//! retira da posição
template<typename T>
T structures::DoublyLinkedList<T>::pop(std::size_t index) {
    Node *anterior, *deleta;
    T elementoRetirado;
    if(index >= size_) {
        throw std::out_of_range("Posição inválida.");
    } else if (empty()) {
        throw std::out_of_range("Lista vazia.");
    } else if (index == 0) {
        return pop_front();
    } else {
        anterior = head;
        for (auto i = 1u; i < index; i++) {
           anterior = anterior->next();
        }
        deleta = anterior->next();
        elementoRetirado = deleta->data();
        anterior->next(deleta->next());
        if(deleta->next() != nullptr) {
            deleta->next()->prev(anterior);
        }
        size__;
        delete deleta;
        return elementoRetirado;
    }
    
}

//! retira do fim
template<typename T>
T structures::DoublyLinkedList<T>::pop_back() {
    return pop(size() -1);
}

//! retira do início
template<typename T>
T structures::DoublyLinkedList::pop_front() {
    Node *esquerda = head;
    T dadoRetirado;
    if(empty()) {
        throw std::out_of_range("A lista esta vazia")
    }
    dadoRetirado = esquerda->data();
    head = esquerda->next();
    if(head != nullptr) {
        head->prev(nullptr);
    }
    size_--;
    delete esquerda;
    return dadoRetirado;
}

//! retira específico
template<typename T>
void structures::DoublyLinkedList<T>::remove(const T& data) {
    pop(find(data));
}


//! Retorna true se lista esta  vazia
template<typename T>
bool structures::DoublyLinkedList<T>::empty() const {
    return size_ == 0;
}

//! Retorna true se o dado contém
template<typename T>
bool structures::DoublyLinkedList<T>::contains(const T& data) const {
    if (empty()) {
            throw std::out_of_range("A lista está vazia");
    }
    auto aux = head;
    while (aux != nullptr) {
        if(aux->data() == data) {
            return true;
        }
        aux = aux->next();
    }
    return false;
}

//! Acesso um elemento da posição (checando limites) 
T& structures::DoublyLinkedList<T>::at(std::size_t index) {
    auto aux = head;
    if(empty()) {
        throw std::out_of_range("A lista esta vazia");
    } else if (index > size() - 1) {
        throw std::out_of_range("Posição inválida.");
    }

    for (auto i = 0u; i < index; ++i) {
       aux = aux->next();
    }

    return aux->data();
}

//! getter constante a um elemento
const T& structures::DoublyLinkedList<T>::at(std::size_t index) const {
    auto aux = head;
    if(empty()) {
        throw std::out_of_range("A lista esta vazia");
    } else if (index > size() - 1) {
        throw std::out_of_range("Posição inválida.");
    }

    for (auto i = 0u; i < index; ++i) {
       aux = aux->next();
    }

    return aux->data();
}

//! Retorna a posição de um dado
std::size_t structures::DoublyLinkedList<T>::find(const T& data) const {
    if (empty()) {
        return -1;
    }
    auto aux = head;
    auto indice = 0u;
    while (aux->data() != data) {
        aux = aux->next();
        indice++;
        if(aux == nullptr) {
            break;
        }
    }
    return indice;
}

//! Retorna o tamanho da lista
template<typename T>
std::size_t structures::DoublyLinkedList<T>::size() const {
    return size_;
}

}  // namespace structures

#endif