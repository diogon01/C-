//! Tarefa de Estruturas de Dados - Implementacão de Pilha em vetor
/*
\author Diogo Henrique - Matrícula 16203891
\since 22/10/2018
\version 1.0
\copyright @ Diogo Henrique
    */
#ifndef  STRUCTURES_AVL_TREE_H
#define STRUCTURES_AVL_TREE_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "array_list.h"


namespace structures {
//!...
template<typename T>
class AVLTree {
public:
    //! Destrutor da classe */
    ~AVLTree();
    //! Metodo que insere na lista
    void insert(const T& data);
    //! Metodo que remove da lista
    void remove(const T& data);
    //! Método booleano que informa se a árvore contém dado específico */
    bool contains(const T& data) const;
    //! Método booleano que retorna true se a árvore contém dado específico */
    bool empty() const;
    //! Método que retorna o tamanho da árvore
    std::size_t size() const;
    //! Método que visita a raiz antes das subárvores */
    ArrayList<T> pre_order() const;
    //! Método que visita as subárvores */
    ArrayList<T> in_order() const;
    //! Método que visita a raiz depois das subarvores*/
    ArrayList<T> post_order() const;

private:
    struct Node {
        //! Construtor do nodo com a data
        Node(const T& data);
        //! Data a ser inserida no 
        T data;
        //! Altura da árvore
        std::size_t height;
        //! Elemento da esquerda
        Node* left;
        //! Elemento da direita
        Node* right;
        //! Método que insere o nodo na lista
        void insert(const T& data_);
        //! Método que remove o nodo da lista
        bool remove(const T& data_);
        //! Método que verifica se a árvore contém elemento dado por parâmetro
        bool contains(const T& data_) const;
        //! Método que aumenta a altura da árvore*
        void updateHeight();   
        //! Método que 
        Node* simpleLeft();

        Node* simpleRight();

        Node* doubleLeft();
        
        Node* doubleRight();

        void pre_order(ArrayList<T>& v) const;

        void in_order(ArrayList<T>& v) const;

        void post_order(ArrayList<T>& v) const;
    };

    Node* root;
    std::size_t size_;
};



}  // namespace structures

#endif