//! Tarefa de Estruturas de Dados - Lista Encadeada
/*
\author Diogo Henrique - Matricula 16203891
\since 19/09/2018
\version 1.0
\copyright @ Diogo Henrique
*/
#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>
#include <stdexcept>


namespace structures {

//! ...
template<typename T>
class LinkedList {
 public:
    //! Construtor da classe sem parametro */
    LinkedList();
    //! Destrutor da classe */
    ~LinkedList();
    //! Limpa a lista */
    void clear();
    //! inserir no fim
    void push_back(const T& data);
    //! inserir no início
    void push_front(const T& data);
    //! inserir na posição
    void insert(const T& data, std::size_t index);
    //! inserir em ordem
    void insert_sorted(const T& data);
    //! acessar um elemento na posição index
    T& at(std::size_t index);
    //! retirar da posição
    T pop(std::size_t index);
    //! retirar do fim
    T pop_back();
    //! retirar do início
    T pop_front();
    //! remover específico
    void remove(const T& data);
    //! lista vazia
    bool empty() const;
    //! contém
    bool contains(const T& data) const;
    //! posição do dado
    std::size_t find(const T& data) const;
    //! tamanho da lista
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

    Node* end() {  // último nodo da lista
        auto it = head;
        for (auto i = 1u; i < size(); ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head{nullptr};
    std::size_t size_{0u};
};

/* Construtor da classe sem parametro */
template<typename T>
structures::LinkedList<T>::LinkedList() {
    head = {nullptr};
    size_ = 0;
}

/* Destrutor da classe */
template<typename T>
structures::LinkedList<T>::~LinkedList() {
    clear();
}


/* Limpa a lista */
template<typename T>
void structures::LinkedList<T>::clear() {
    Node *atual, *anterior;
    atual = head;
    while (atual != nullptr) {
        anterior = atual;
        atual = atual->next();
        delete anterior;
    }
    head = nullptr;
    size_ = 0;
}

/* inserir no fim */
template<typename T>
void structures::LinkedList<T>::push_back(const T& data) {
    if (empty()) {
        push_front(data);
    } else {
        insert(data, size_);
    }
}

/* inserir no início */
template<typename T>
void structures::LinkedList<T>::push_front(const T& data) {
    Node* novo = new Node(data, head);
    if (novo == nullptr) {
        throw std::out_of_range("Lista Cheia!");
    }
    head = novo;
    size_++;
}

/* inserir na posição */
template<typename T>
void structures::LinkedList<T>::insert(const T& data, std::size_t index) {
    Node *novo, *anterior;
    if (index > size_) {
        throw std::out_of_range("Posição inválida!");
    } else if (index == 0) {
        push_front(data);
    } else {
        novo = new Node(data);
        if (novo == nullptr) {
            throw std::out_of_range("Lista cheia");
        }
        anterior = head;
        for (auto i = 1u; i < index; i++) {
            anterior = anterior->next();
        }
        novo->next(anterior->next());
        anterior->next(novo);
        size_++;
    }
}

/* inserir em ordem */
template<typename T>
void structures::LinkedList<T>::insert_sorted(const T& data) {
    Node *atual;
    std::size_t indice;
    if (empty()) {
        push_front(data);
    } else {
        atual = head;
        indice = 0;
        while (atual->next() != nullptr && data > atual->data()) {
            atual = atual->next();
            indice++;
        }
        if (data > atual->data()) {
            return insert(data, indice + 1);
        } else {
            return insert(data, indice);
        }
    }
}

/* Acessar um elemento na posição index */
template<typename T>
T& structures::LinkedList<T>::at(std::size_t index) {
    auto it = head;
    for (auto i = 0; i < index; i++) {
        if (it->next() == nullptr) {
            throw std::out_of_range("Posiçao invalida");
        }
       it = it->next();
    }
    return it->data();
}

/* retirar da posição */
template<typename T>
T structures::LinkedList<T>::pop(std::size_t index) {
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    }
    Node *anterior, *retirar;
    T retorno;
    if (index > size_ -1) {
        throw std::out_of_range("Posiçao invalida");
    } else if (index == 0) {
       return pop_front();
    } else {
        anterior = head;
        for (auto i = 0; i < index -1; i++) {
            anterior = anterior->next();
        }
        retirar = anterior->next();
        retorno = retirar->data();
        anterior->next(retirar->next());
        size_--;
        delete retirar;
        return retorno;
    }
}

/* Retirar do fim */
template<typename T>
T structures::LinkedList<T>::pop_back() {
    return pop(size_ -1);
}

/* retirar do início */
template<typename T>
T structures::LinkedList<T>::pop_front() {
    Node *retira;
    T retorno;
    if (empty()) {
        throw std::out_of_range("Lista vazia");
    } else {
        retira = head;
        retorno = retira->data();
        head = retira->next();
        size_--;
        delete(retira);
        return retorno;
    }
}

/* Remover específico */
template<typename T>
void structures::LinkedList<T>::remove(const T& data) {
    pop(find(data));
}


/* lista vazia */
template<typename T>
bool structures::LinkedList<T>::empty() const {
    return size_ == 0;
}

/* Retorna true se  contains */
template<typename T>
bool structures::LinkedList<T>::contains(const T& data) const {
    if (empty()) {
        throw std::out_of_range("Lista Vazia");
    }
    auto inicio = head;
    while (inicio != nullptr) {
        if (inicio->data() == data) {
            return true;
        }
        inicio = inicio->next();
    }
    return false;
}

/* Retorna a posicao do dado */
template<typename T>
std::size_t structures::LinkedList<T>::find(const T& data) const {
    if (empty()) {
        return -1;
    }

    auto inicio = head;
    auto indice = 0;
    while (inicio->data() != data) {
        inicio = inicio->next();
        indice++;
        if (inicio == nullptr) {
            break;
        }
    }
    return indice;
}

/* Retorna do tamanho da lista */
template<typename T>
std::size_t structures::LinkedList<T>::size() const {
    return size_;
}

}  // namespace structures

#endif
