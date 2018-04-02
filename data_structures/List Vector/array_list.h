/**
 * Created by diogo on 21/03/2018.
 */

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>
#include <algorithm>


namespace structures {

template<typename T>
class ArrayList {
public:
    ArrayList();
    explicit ArrayList(std::size_t max_size);
    ~ArrayList();

    void clear();
    void push_back(const T& data);
    void push_front(const T& data);
    void insert(const T& data, std::size_t index);
    void insert_sorted(const T& data);
    T pop(std::size_t index);
    T pop_back();
    T pop_front();
    void remove(const T& data);
    bool full() const;
    bool empty() const;
    bool contains(const T& data) const;
    std::size_t find(const T& data) const;
    std::size_t size() const;
    std::size_t max_size() const;
    T& at(std::size_t index);
    T& operator[](std::size_t index);
    const T& at(std::size_t index) const;
    const T& operator[](std::size_t index) const;

private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_MAX = 10u;
};




/* Constructor empty params */
template<typename T>
structures::ArrayList<T>::ArrayList(){
    size_ = max_size_ = 0;
    contents = new T[0];
}

/** Constructor witch max size **/
template<typename T>
structures::ArrayList<T>::ArrayList(std::size_t max_size_){
    size_ = 0;
    max_size_ = max_size_;
    contents = new T [max_size_];

}

/** Destruction **/
template<typename T>
structures::ArrayList<T>::~ArrayList(){
    delete[] contents;
}

/** Clear the list **/
template<typename T>
void structures::ArrayList<T>::clear(){
    size_ = 0;
}

/** Push element in last position **/
template<typename T>
void structures::ArrayList<T>::push_back(const T& data){
    if(full())
        throw std::out_of_range("Lista cheia");
    contents[size_++] = data;
}

/** Push element if first position **/
template<typename T>
void structures::ArrayList<T>::push_front(const T& data){
    if(full())
        throw std::out_of_range("Lista cheia");
    if(size_ > 0){
        for (int i = size_; i > 0; i--)
            contents[i] = contents[i-1]; 
    }
    contents[0] = data;
    size_++;
} 

/** Push in index position of list **/
template<typename T>
void structures::ArrayList<T>::insert(const T& data, std::size_t index){
    if(full())
        throw std::out_of_range("Lista cheia");
    if(index > size_)
        throw std::out_of_range("Indice incorreto");
    auto temp = contents[index];
    contents[index] = data;
    size_++;
}



/** Set list in alphabetical order **/
template<typename T>
void structures::ArrayList<T>::insert_sorted(const T& data){
    contents[size_++] = data;
    for (int i =  0; i < size_; i++){
        for(int j = 0; j < size_; j++){
            if(contents[i] < contents[j])
                std::swap(contents[i], contents[j]);
        }
    }
}

/** Remove element wicth position **/
template<typename T>
T structures::ArrayList<T>::pop(std::size_t index){
    if(empty())
        throw std::out_of_range("Lista esta vazia");
    if(index > size_ -1)
        throw std::out_of_range("Indice Invalido");
    auto data = contents[index];
    for (int i = index; i < size_; i++)
        contents[i - 1] = contents[i];
    size_--;

    return data;
}

/** Get last element in position **/
template<typename T>
T structures::ArrayList<T>::pop_back(){
    if(empty())
        throw std::out_of_range("Lista esta vazia");
    auto data = contents[size_--];
    contents[size_] = 0;
    return data;
}

/** Get first element in list **/
template<typename T>
T structures::ArrayList<T>::pop_front(){
    if(empty())
        throw std::out_of_range("Lista esta vazia");
    auto data = contents[0];
    for(int i = 1; i < max_size_; i++){
        contents[i - 1] = contents[i];
    }
    size_--;
    return data;
}
/** Get the index element in list **/
template<typename T>
void structures::ArrayList<T>::remove(const T& data){
    
    int index = find(data);
    
    if (index > -1) {
        contents[index] = 0;
        for (int i = index; i < max_size_; i++)
            contents[i - 1] = 1;
        size_--;
    }
}

/** Return true if list is full **/
template<typename T>
bool structures::ArrayList<T>::full() const{
    return size_ == max_size_;
}

/** Return true if list is empty **/
template<typename T>
bool structures::ArrayList<T>::empty() const{
    return size_ == 0;
}

/** Return true if element existis in list **/
template<typename T>
bool structures::ArrayList<T>::contains(const T& data) const{
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data)
            return true;
    }
    return false;
}




//TODO: Code Review  in code

/** Retorna o índica do elemento param */
template<typename T>
std::size_t structures::ArrayList<T>::find(const T& data) const {
    for (int i = 0; i < size_; i++) {
        if (contents[i] == data)
            return i;
    }	 	  	 	     	     	      	    	      	     	  	 	
    return size_;
}

/** Retorna o tamanho atual da lista */
template<typename T>
std::size_t structures::ArrayList<T>::size() const {
    return size_;
}

/** Retorna o tamanho máximo da lista */
template<typename T> std::size_t structures::ArrayList<T>::max_size() const {
    return max_size_;
}

/** Retorna o elemento do índice param */
template<typename T> T& structures::ArrayList<T>::at(std::size_t index) {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

/** Retorna o elemento na posição param */
template<typename T>
T& structures::ArrayList<T>::operator[](std::size_t index) {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}

/** Retona o elemento na posicação param */
template<typename T>
const T& structures::ArrayList<T>::at(std::size_t index) const {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}	 	  	 	     	     	      	    	      	     	  	 	

/** Retorna o elemento da poisção param */
template<typename T>
const T& structures::ArrayList<T>::operator[](std::size_t index) const {
    if (index > size_)
        throw std::out_of_range("Lista vazia");
    return contents[index];
}


//-------------------------------------


class ArrayListString {
 public:
    ArrayListString();
    explicit ArrayListString(std::size_t max_size);
    ~ArrayListString();

    void clear();
    void push_back(const char *data);
    void push_front(const char *data);
    void insert(const char *data, std::size_t index);
    void insert_sorted(const char *data);
    char *pop(std::size_t index);
    char *pop_back();
    char *pop_front();
    void remove(const char *data);
    bool full() const;
    bool empty() const;
    bool contains(const char *data) const;
    std::size_t find(const char *data) const;
    std::size_t size() const;
    std::size_t max_size() const;
    char *at(std::size_t index);
    char *operator[](std::size_t index);
    const char *at(std::size_t index) const;
    const char *operator[](std::size_t index) const;

 private:
    ArrayList<char *> *list;
    static const auto DEFAULT_MAX = 100u;
};


/** Constructor */
structures::ArrayListString::ArrayListString(std::size_t max_size){
    list = new ArrayList<char *>(max_size);
}

/** Destructor */
structures::ArrayListString::~ArrayListString(){
    delete list;
}

/** Clear the array list */
void structures::ArrayListString::clear(){
    list->clear();
}

/** Add element in last position to array */
void structures::ArrayListString::push_back(const char *data){
    list->push_back(const_cast<char*>(data));
}

/** Add element in first position to array */
void structures::ArrayListString::push_front(const char *data){
    list->push_front(const_cast<char*>(data));
}

/** Insert element in index position */
void structures::ArrayListString::insert(const char *data, std::size_t index){
    list->insert(const_cast<char*>(data), index);
}

/** Insert in order asc in list */
void structures::ArrayListString::insert_sorted(const char *data){
    list->insert_sorted(const_cast<char*>(data));
}

/** Remove char in index position */
char* structures::ArrayListString::pop(std::size_t index) {
    return list->pop(index);
}

/** Remove char in last position in Array */
char* structures::ArrayListString::pop_back(){
    return list->pop_back();
}

/** Remove char in first position in Array */
char* structures::ArrayListString::pop_front(){
    return list->pop_front();
}

/** Remove data in array */
void structures::ArrayListString::remove(const char *data){
    list->remove(const_cast<char*>(data));
}

/** Return true if list is full */
bool structures::ArrayListString::full() const{
    return list->full();
}

/** Return true if list is empty */
bool structures::ArrayListString::empty() const{
    return list->empty();
}

/** Return true if data contains in list */
bool structures::ArrayListString::contains(const char *data) const{
    return list->contains(const_cast<char*>(data));
}

/** Return data position in Array */
std::size_t structures::ArrayListString::find(const char *data) const{
    return list->find(const_cast<char*>(data));
}

/** Return size Array */
std::size_t structures::ArrayListString::size() const{
    return list->size();
}

/** Return max size Array */
std::size_t structures::ArrayListString::max_size() const{
    return list->max_size();
}

/** Return char in index position */ 
char* structures::ArrayListString::at(std::size_t index){
    return list->at(index);
}

/** I not Understant */
char* structures::ArrayListString::operator[](std::size_t index){
    return list->at(index);
}

/** Set const char* */
const char* structures::ArrayListString::at(std::size_t index) const{
    return list->at(index);
}

/** Set const operator[] */
const char* structures::ArrayListString::operator[](std::size_t index) const{
    return list->at(index);
}

}  // namespace structures

#endif
