#ifndef NO_TRIE_HPP
#define NO_TRIE_HPP

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
const int ALPHABET_SIZE = 26; 

using namespace std;

template<typename T>
/** Class NoTrie */
class NoTrie {
 public:
    //! Construtor da classe sem parametro
    explicit NoTrie();
    //! Destrutor da classe
    virtual ~NoTrie();
    //! Testando o trie 
    struct NoTrie *getNode(void);
    //! Metodo que insere na arvore
    void insert(struct NoTrie *root, string key, unsigned long position, unsigned long tamanho);
    //! Retorna verdadeiro true se a letra contem
    bool search(struct NoTrie *root, string key);

  private: 
    char           letra;        //opcional
    NoTrie        *children[ALPHABET_SIZE];   //pode ser uma 'LinkedList' de ponteiros
    unsigned long  position;
    unsigned long  tamanho;
};

template<typename T>
NoTrie<T>::NoTrie(){

}

template<typename T>
void NoTrie<T>::insert(struct NoTrie *root, string letra, unsigned long position, unsigned long tamanho) {

    NoTrie *pCrawl = root;

    for (int i = 0; i < letra.length(); i++) {
        int index = letra[i] - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = 
        }
    }

}

template<typename T>
NoTrie<T>::~NoTrie() {
    delete letra;
    delete filhos[];
    delete comprimento;
}

template<typename T>
bool NoTrie<T>::search(struct NoTrie *root, string key) {
    
    struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

template<typename T>
NoTrie<T>::*getNode(void) {
struct NoTrie *pNode = new NoTrie; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
}

#endif /* NO_TRIE_HPP */