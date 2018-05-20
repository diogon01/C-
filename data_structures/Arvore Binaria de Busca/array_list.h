#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>


namespace structures {

template<typename T>

/**
 * @brief       Classe array lis do curso de em C++
 * @tparam T
 * @param  size_    Tamanho atual da lista
 * @param  max_size_ Armazena o tamanho da lista
 */


class ArrayList {
public:
    ArrayList(){

        size_ = -1;
        max_size_ = DEFAULT_MAX;
        contents = new T[max_size_];

    }

    /**
     * @brief       Construtor da Classe
     * @param max_size
     * @details     Valor max_seize e informado no cabecalho do metodo
     */
    explicit ArrayList(std::size_t max_size){
        size_ = -1;
        max_size_ = max_size;
        contents = new T[max_size];

    }
    /**
     * @brief Metodo para deletar a lista
     * @details Esse metodo nao e necessario entrada
     */
    ~ArrayList(){
        delete [] contents;
    }

    /**
     * @brief Metodo que limpa a lista
     * @details Nao entendi muito essa e metodo mas isso e normal na UFSC
     */
    void clear(){
        delete [] contents;
        size_ = -1;
        contents = new T[max_size_];
    }

    /**
     * @brief Coloca o elemento no final da Lista
     * @param data   e o valor recebido no vetor
     * @details E reutilizado o metodo insert e adicionado mais 1 no size
     */
    void push_back(T data){
        insert(data, size_+1);
    }

    /**
     * @brief   Adiciona o elemento no comeco da Lista
     * @param data  Elemento que vai ser adicionado na lista
     */
    void push_front(T data){
        insert(data,0);
    }

    /**
     * @brief   Coloca elemento no inicio da lista
     * @param data  Valor que vai ser adicionado na lista
     * @param index Indice que indica a posicao do vetor
     */
    void insert(T data, std::size_t index){
        if(full()){

            throw std::out_of_range("ERRO LISTA CHEIA");

        } else{
            if(index > size_ + 1 || index < 0){

                throw std::out_of_range("POSICAO INVALIDA");
            } else {
                size_++;
                int i = size_;
                while (i > index){
                    contents[i] = contents[i-1];
                    i--;
                }
            }
        }

    }


    /**
     * @brief Inseri de forma ordenada o dado
     * @param data Parametro que recebe a data que vai ser inserida
     * @details O dado e inserido de forma ascedente do menor para o maior
     */
    void insert_sorted(T data){
        if(full()){
            throw std::out_of_range("ERRO LISTA CHEIA");
        } else{
            int i = 0;
            while (i < size_ +1 && data > contents[i]){
                i++;
            }
            insert(data, i);
        }
    }

    /**
     * @brief   Remove o dado na possicao index
     * @param index  O parametro que diz a posicao na lista
     * @return Retorna a lista com o item removido e as posicoes ajustadas;
     */
    T pop(std::size_t index){
        if(index > size_ || index < 0){
            throw std::out_of_range("POSICAO INVALIDA");
        } else {
            if(empty()){
                throw std::out_of_range("A lista esta vazia");
            } else{
                size_--;
                T data_aux = contents[index];
                int i = index;
                while (i < size_+1){
                    contents[i] = contents[i+1];
                    ++i;
                }

                return data_aux;
            }
        }
    }

    /**
     * @brief Remove o dado no final da lista
     * @return Retorna a lista com a ultima posicao da lista removida
     * @details nesse caso nao precisa do index da lista basta o size_ da lista
     */
    T pop_back(){
        return pop(size_);
    }

    /**
     * @brief Remove o dado do inicio da lista
     * @return Retorna a lista com a ultima posicao da lista removida
     * @details Passamos o valor de index 0 ja que e pedido para remover no inicio
     */
    T pop_front(){
        return pop(0);
    }

    /**
     * @brief Retira o elemento que for passado com parametro
     * @param data  O elemento que vai ser retirado da lista
     * @details Nesse caso vou utilizar o metodo find() para comparar e romever as dats iguais
     */
    void remove(T data){
        pop(find(data));
    }

    /**
     * @brief Verifca se a lista esta cheia
     * @return true caso a lista esteja cheia
     */
    bool full() const{
        return size_ == max_size_-1;
    }

    /**
     * @brief Verifica se a lista esta vazia
     * @return true caso esteja vazia a lista
     */
    bool empty() const{
        return size_ == -1;
    }

    /**
     * @brief Metodo para verificar se a data existe na lista
     * @param data O valor que vai ser verifica da lista
     * @return true casa o dado data se encontra na lista
     */
    bool contains(const T& data) const{
        return find(data) != size_+1;

    }

    /**
     * @brief Metodo feito para verificar o indice de posicao do elemento
     * @param data Elemento que vai retornar o indice
     * @return Retorna o indice da lista que a data pertence
     */
    std::size_t find(const T& data) const{
        for(int i = 0; i <= size_; i++){
            if(data == contents[i]){
                return i;
            }
        }
        return size_+1;
    }


    /**
     * @return o Numero de elementos da lista
     * @details Como a lista comeca em -1 e necessario adicionar mais +1 no resultado
     */
    std::size_t size() const{
        return size_+1;
    }

    /**
     * @brief Metodo para verificar o tamanho maximo da lista
     * @return Retorna o tamanho maximo da lista
     */
    std::size_t max_size() const{
        return max_size_;
    }

    /**
     * @brief Metodo que retorna o lemento da lista passando indice como paramatro
     * @param index Paramentro necessario para localizar a posicao na listta
     * @return  Retorna o valor que esta na lista se o mesmo existir senao retorna erro
     */
    T& at(std::size_t index){
        if(index <= size_){
            return contents[index];
        } else{
            throw std::out_of_range("POSICAO INVALIDA");
        }
    }

    /**
     * @brief Acesso o elemento que foi passado no indice
     * @param index Indice da posicao do elemento a ser acessado.
     * @return  Retorna o elemento que esta na posicao indice passado com parametro sem verificar a posicao
     */
    T& operator[](std::size_t index){
        return contents[index];
    }

    /**
     * @brief Acessa o elemento que esta no indice para atende as constante(Nao sei bem pq)
     * @param index Indice da lista a ser acessado
     * @return  Retorna o elemento que esta na posicao do indice a ser acessado
     */
    const T& at(std::size_t index) const{
        return at(index);
    }

    /**
     * @brief Acessa o elemento que esta no indice para atende as constante(Nao sei bem pq)
     * @param index Indice da lista a ser acessado
     * @return  Retorna o elemento que esta na posicao do indice a ser acessado
     */
    const T& operator[](std::size_t index) const{
        return contents[index];
    }


private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_MAX = 10u;
};

}

#endif
