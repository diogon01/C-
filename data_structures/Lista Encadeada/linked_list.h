#ifndef STRUCTURES_LINKED_LIST_H
#define STRUCTURES_LINKED_LIST_H

#include <cstdint>


namespace structures {

    template<typename T>
    class LinkedList {
    public:
        /**
         * @brief Construtor padrao
         * @details Nao entendi bem esse construtor
         */
        LinkedList() = default; // construtor padrão
        ~LinkedList() {
            clear();
        } // destrutor


        /**
         * @brief Nao sei bem esse metodo
         */

        void clear() {
            Node it = head;
            while (it != nullptr) {
                it = it.next();
                pop_front();
            }
            size_ = 0;

        }

        /**
         * @brief Inserir o dado no final da lista
         * @param data Valor a ser inserido
         * @details Esse metodo serve para inserir no final da lista
         */
        void push_back(const T &data) {
            insert(data, size_);
        }

        /**
         * @brief Inserir no comeco
         * @param data Valor a ser inserido
         * @details Esse metodo serve para inserir no comeco da lista
         */
        void push_front(const T &data) {
            Node *new_ = new Node(data, size_);
            head = new_;
            size_++;
        }

        /**
         * @brief Inserir na lista pela poisicao
         * @param data valor a ser inserido na lista
         * @param index Posicao a ser adicionado
         * @details Esse metodo e utilizado a posicao para inserir e depois organizar
         */
        void insert(const T &data, std::size_t index) {
            if (index > size_ || index < 0) {

                throw std::out_of_range("ERRO POSIÇÃO INVÁLIDA");

            } else {
                if (index == 0) {
                    pop_front(data);
                } else {
                    Node *it = head;
                    Node *new_ = new Node(data);
                    for (int i = 0; i < (index); i++) {
                        it = it->next();
                    }
                    new_->next(it->next());
                    it->next(new_);
                    size_++;
                }
            }

        }

        /**
         * @brief Inserir elemento em ordem
         * @param data valor que vai ser inserido na lista
         * @details Metodo feito para inserir na lista em oredm ascedente
         */
        void insert_sorted(const T &data) {
            if (empty()) {
                push_front(data);
            } else {
                Node *i = head;
                int index = 0;
                while (it != nullptr && data > (it->data())) {
                    it = it->next();
                    index++;
                }
                insert(data, index);
            }

        }

        /**
         * @brief Motodo pegar o valor da lista
         * @param index Parametro que aponta qual posicao o valor se encontra
         * @return Retorna o valor encontrado na lista
         * @details O valor retorna de acordo com o index que e passado
         */
        T &at(std::size_t index) {
            if (index < size_) {
                Node *it = head;
                for (int i = 0; i < index; i++) {
                    it = it->next();
                }
            }
            throw std::out_of_range("POSIÇÃO INVÁLIDA");
        }

        /**
         * @brief Metdo que remove o item da lista
         * @param index Parametro que aponta qual posicao o valor se encontra
         * @return A lista com o valor removido
         * @details Metodo que remove o elemento de acordo com index e retorna a lista atualizada
         */
        T pop(std::size_t index) {
            if (empty()) {
                throw std::out_of_range("ERRO LISTA VAZIA");
            }
            if (index > size_ - 1 || index < 0) {
                throw std::out_of_range("ERRO POSIÇÃO INVÁLIDA");
            } else {
                if (index == 0) {
                    return pop_front();
                } else {
                    Node *prev = head;
                    Node *delete_;
                    for (int i = 0; i < (index - 1); ++i) {
                        prev = prev->next();
                    }
                    delete_ = prev->next();
                    T back = delete_->data();
                    prev->next(delete_->next());
                    delete delete_;
                    size_--;
                    return back;
                }
            }

        }

        /**
         * @brief Metodo que remove no fim da lista
         * @return A lista com o ultimo item removido
         */
        T pop_back() {
            return pop(size_ - 1);
        }

        /**
         * @brief Metodo que remove no primeiro item da lista
         * @return A lista com primeiro item da fila removido
         */
        T pop_front() {
            if (empty()) {
                throw std::out_of_range("ERRO LISTA VAZIA");
            } else {
                Node *it = head;
                T back = it->data();
                head = it->next();
                delete it;
                size_--;
                return back;
            }
        }


        /**
         * @brief Remove item da lista de acordo com a data do parametro
         * @param data Valor que vai ser removido da lista
         */
        void remove(const T &data) {
            pop(find(data));
        }

        /**
         * @brief Metodo para verificar se a lista esta vazia
         * @return true se a lista esta vazia
         */
        bool empty() {
            return size_ == 0;
        }

        /**
         * @brief Metodo construindo para verificar
         * @param data Parametro para verificar se o valor existe
         * @return true se olemento passado na data e encontrado
         */
        bool contains(const T &data) const {
            if (empty()) {
                throw std::out_of_range("ERRO LISTA VAZIA");
            } else {
                Node *it = head;
                for (int i = 0; i < size_; i++) {
                    if (data == (it->data())) {
                        return true;
                    } else {
                        it = it->next();
                    }
                }
                return false;
            }
        }

        /**
         * @brief Metodo retorna a posicao data na lista
         * @param data Elemento usado de comparacao
         * @return Retorna indice onde a data esta inserida
         */
        std::size_t find(const T &data) const {
            Node *it = head;
            for (int i = 0; i < size_; i++) {
                if (data == (it->data())) {
                    return i;
                }
            }

            return size_;

        }

        /**
         * @brief Metodo para retornar o tamanho da lista
         * @return o tamanho da lista
         */
        std::size_t size() const {
            return size_;
        }

    private:
        class Node { // Representa um Nodo da Lista
        public:

            /**
             * @brief Construtor quando passa somente a data como parametro
             * @param data
             */
            Node(const T &data) :
                    data_{data} {}

            /**
             * @brief Construtor com next
             * @param data Dado a ser gravado na lista
             * @param next Valor do proximo nodo a ser gravado
             * @details Constroi um nodo com a data e valor do proximo nodo
             */
            Node(const T &data, Node *next) :
                    data_{data},
                    next_{next} {}

            /**
             * @brief Getter do dado
             * @return retorna o valor do nodo
             */
            T &data() { // getter: dado
                return data_;
            }

            /**
             * @brief Getter do constante dado
             * @return o dado como constante do Nodo
             * @details Eu nao sei bem por que usas as constantes
             */

            const T &data() const { // getter const: dado
                return data_;
            }

            /**
             * @brief Getter do proximo Nodo
             * @return Retorna o proximo Node
             */

            Node *next() { // getter: próximo
                return next_;
            }

            /**
             * @brief Gettter Constante do Proximo Node
             * @return Retorna a constante do proximo node
             */
            const Node *next() const { // getter const: próximo
                return next_;
            }

            /**
             * @brief Set do proximo nodo
             * @param node Valor do proximo Nodo
             */

            void next(Node *node) { // setter: próximo
                next_ = node;
            }

        private:
            T data_;
            Node *next_{nullptr};
        };

        Node *end() { // último nodo da lista
            auto it = head;
            for (auto i = 1u; i < size(); ++i) {
                it = it->next();
            }
            return it;
        }

        Node *head{nullptr};
        std::size_t size_{0u};
    };

}

#endif

