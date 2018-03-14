/**
 * Created by diogo on 13/12/2018.
 */

#ifndef STRUCTURES_ARRAY_QUEUE_H
#define STRUCTURES_ARRAY_QUEUE_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ Exceptions

namespace structures {

template<typename T>
class ArrayQueue {
public:
    ArrayQueue();

    ArrayQueue(std::size_t max);

    ~ArrayQueue();

    void enqueue(const T& data);

    T dequeue();

    T& back();

    void clear();

    std::size_t size();

    std::size_t max_size();

    bool empty();

    bool full();

private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_SIZE = 10u;
};

}

#endif

/* constructor the class */
template<typename T>
structures::ArrayQueue<T>::ArrayQueue(std::size_t max){
    size_ = 0;
    max_size_ = max;
    contents = new T [max_size_];

}

/* unset de class */
template<typename T>
structures::ArrayQueue<T>::~ArrayQueue(){
    delete[] contents;
}

/* add data in queue */
template<typename T>
void structures::ArrayQueue<T>::enqueue(const T& data){
    if(full())
        throw std::out_of_range("Queue is full");
    else
        contents[size_++] = data;
}

/* remove data in queue */
template<typename T>
T structures::ArrayQueue<T>::dequeue(){
    if(empty()){
        throw std::out_of_range("Queue is empty");
    }
    else{
        auto temp = contents[0];
        for (int i = 0; i < size_; i++)
            contents[i] = contents[i+1];
        size_--;
        return temp;
    }
        

}

/* remove last in queue */
template<typename T>
T& structures::ArrayQueue<T>::back(){
    if(empty())
        throw std::out_of_range("Queue is empty");
    return contents[size_--];
}

/* clear all data queue */
template<typename T>
void structures::ArrayQueue<T>::clear(){
    size_ = 0;
}

/* get the queue size */
template<typename T>
std::size_t structures::ArrayQueue<T>::size(){
    return size_;
}

/* get the max size lenght queue */
template<typename T>
std::size_t structures::ArrayQueue<T>::max_size(){
    return max_size_;
}

/* boolen return true if queue is empty */
template<typename T>
bool structures::ArrayQueue<T>::empty(){
    return size_ == 0;
}

/* boolen return true if queue is full */
template<typename T> 
bool structures::ArrayQueue<T>::full(){
    return size_ == max_size_;
}

