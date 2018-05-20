/**
 * Desenvolvido por Diogo Henrique INE5609-03238B
 */


#include "array_list.h"


namespace structures {
    template<typename T>    class BinaryTree {
    public:

        BinaryTree() = default;


        virtual ~BinaryTree() {
            delete root;
            size_ = 0;
        }

        /**
         * Inseriando uma vertice nova na arvore
         * @param data e o dado que vai ser inserido
         */
        void insert(const T &data) {
            if (empty()) {
                root = new Node(data);
            } else {
                root->insert(data);
            }

            ++size_;
        }

        /**
         * Removendo uma vertice na Arvore
         * @param data
         */
        void remove(const T &data) {
            bool verif;
            if (empty()) {
                return;
            } else {
                verif = root->remove(data);
                if (verif) {
                    --size_;
                }
            }
        }

        /**
         * @brief Verifica se o dado esxite na vertice
         * @param data Dado que vai receber o metodo
         * @return Retorna um boleano true ou false
         */
        bool contains(const T &data) const {
            if (empty()) {
                return false;
            } else {
                return root->contains(data);
            }
        }

        /**
         * @brief Verifica se a arvore esta vazia
         * @return Retorna um boleano true ou false
         */
        bool empty() const {
            return size_ == 0;
        }


        /**
         *@brief   O numero de elementos da Arvore
         * @return O numero do de elementos da Arvore
         */
        std::size_t size() const {
            return size_;
        }

        /**
         * @brief   Metodo para retornar a lista ordenada
         * @return A lista de elementos ordenados
         */

        ArrayList<T> pre_order() const {
            structures::ArrayList<T> v{};
            if (!(empty())) {
                root->pre_order(v);
            }
            return v;
        }

        /**
         * @brief Metodo retorna a lista ordenada
         * @return Uma lista ordenada
         */

        ArrayList<T> in_order() const {
            structures::ArrayList<T> v{};
            if (!(empty())) {
                root->in_order(v);
            }
            return v;
        }

        /**
         * @brief Metodo retorna a lista ordenada
         * @return Uma lista ordenada
         */
        ArrayList<T> post_order() const {
            structures::ArrayList<T> v{};
            if (!(empty())) {
                root->post_order(v);
            }
            return v;
        }


    private:
        struct Node {
            /**
             * Construtor utiliza apenas um parametro
             * @param data
             */
            explicit Node(const T &data)
                    : data{data}, left{nullptr}, right{nullptr} {}


            T data; //Dado que vai ser adicionado no sistema
            Node *left; // Filho da esquerda
            Node *right; // Filho da direita

            /**
             * Insert necessita da data para inserir
             * @param data_
             */
            void insert(const T &data_) {

                Node *newNode;
                if (data_ > data) {
                    if (right == nullptr) {
                        newNode = new Node(data_);
                        right = newNode;
                    } else {
                        right->insert(data_);
                    }

                } else {
                    if (left == nullptr) {
                        newNode = new Node(data_);
                    } else {
                        left->insert(data_);
                    }
                }
            }


            /**
             * @brief Metodo construido para remover da arvore
             * @param data_ O dado que recebe no metodo
             * @return Retorna true se consegiu remover
             */
            bool remove(const T &data_) {
                if (data_ == data) {
                    if (left != nullptr && right != nullptr) {
                        auto it = mini(right);
                        data = it->data;
                        return right->remove(data);
                    } else {
                        if (right != nullptr) {
                            data = right->remove(data);
                        } else {
                            if (left != nullptr) {
                                data = left->data;
                                return left->remove(data);
                            } else {
                                delete this;
                                return true;
                            }
                        }
                    }
                } else {
                    if (right != nullptr && data < data_) {
                        return right->remove(data_);
                    } else {
                        if (left != nullptr && data > data_) {
                            return left->remove(data_);
                        }
                    }
                }
                return false;
            }

            /**
             * @brief Metodo
             * @param data_
             * @return
             */
            bool contains(const T &data_) const {

                if (data == data_) {
                    return true;
                } else {
                    if (right != nullptr && data_ > data) {
                        return right->contains(data_);
                    } else if (left != nullptr && data_ < data) {
                        return left->contains(data_);

                    }
                }
                return false;
            }


            /**
             * @brief  O Metodo que organiza da esquerda para direita
             * @param v Recebe uma Array de Vetores
             */
            void pre_order(ArrayList<T> &v) const {
                v.push_back(data);
                if (left != nullptr) {
                    left->pre_order(v);
                }
                if (right != nullptr) {
                    right->pre_order(v);
                }
            };


            /**
             * @brief   O Metodo que organiza da esquerda para direita
             * @param v Recebe uma Array de Vetores
             */
            void in_order(ArrayList<T> &v) const {
                if (left != nullptr) {
                    left->in_order(v);
                }

                v.push_back(data);
                if (right != nullptr) {
                    right->in_order(v);
                }
            };

            /**
             * @brief
             * @param v
             */

            void post_order(ArrayList<T> &v) const {
                if (left != nullptr) {
                    left->post_order(v);
                }
                if (right != nullptr) {
                    right->post_order(v);
                }
                v.push_back(data);
            }

            Node *mini(Node *node) {
                while (node->left != nullptr) {
                    node = node->left;
                }
                return node;
            }
        };

        Node *root{nullptr};
        std::size_t size_;
    };

}