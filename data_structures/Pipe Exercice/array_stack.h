/**
 * Created by diogo on 13/12/2018.
 */

#ifndef STRUCTURES_ARRAY_STACK_H
#define STRUCTURES_ARRAY_STACK_H

#include <cstdint> // std::size_t
#include <stdexcept> // C++ exceptions

namespace structures {

template<typename T>
class ArrayStack {
public:
    ArrayStack();

    ArrayStack(std::size_t max);

    ~ArrayStack();

    void push(const T& data); // push in array

    T pop(); 

    T& top();

    void clear(); // clear the stack

    std::size_t size(); // return size the stack

    std::size_t max_size(); // return the stack max size value

    bool empty(); // boolean return true if stack is empty()

    bool full(); // boolean return true if stack is full()

private:
    T* contents;
    int top_;
    std::size_t size_;
    std::size_t max_size_;

    const static auto DEFAULT_SIZE = 10u;
};

}

#endif

/** New Construction **/
template<typename T>
structures::ArrayStack<T>::ArrayStack(std::size_t max){
    
    size_ = 0;
    max_size_ = max;
    contents = new T[max_size_];
}

/** Destruction **/
template<typename T>
structures::ArrayStack<T>::~ArrayStack(){
    delete[] contents;
}

/* Push  on Stack */
template<typename T> 
void structures::ArrayStack<T>::push(const T& data){
    if(full())
        throw std::out_of_range("Stack is full");
    else
        contents[size_++] = data;
}

/* Remove the Stack */
template<typename T>
T structures::ArrayStack<T>::pop(){
    if(empty()){
        throw std::out_of_range("Stack is empty");
    } else {
        
        auto temp = contents[0];
        for (int i = 0; i < size_; i++)
            contents[i] = contents[i++];
        size_--;
        return temp;
    }
}

/* remove the last data on stack */
template<typename T>
 T& structures::ArrayStack<T>::top(){
    if(empty())
        throw std::out_of_range("Stack is empty");
    return contents[size_ -1];
}


/* Clear Stack */
template<typename T>
void structures::ArrayStack<T>::clear(){
    size_ = 0;
}

/* Get the stack lenght */
template<typename T>
std::size_t structures::ArrayStack<T>::size(){
    return size_;
}

/* Get the maximum stack size */
template<typename T>
std::size_t structures::ArrayStack<T>::max_size(){
    return max_size_;
}

/* Verify the stack is empty */

template<typename T>
bool structures::ArrayStack<T>::empty(){
    return  top_ == -1;
}


/* Veriy the stack is full */
template<typename T>
bool structures::ArrayStack<T>::full(){
    return size_ == max_size_;
}



