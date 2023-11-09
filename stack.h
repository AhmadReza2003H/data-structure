#ifndef PROJECT2_STACK_H
#define PROJECT2_STACK_H

#include "node.h"

template <typename T> class Stack{
public:
    Stack();
    ~Stack();
    T getTop();
    T pop();
    void push(T object);
    bool isEmpty();
    int getSize();
private:
    Node<T> * top;
    int size;
};

template <typename T> Stack<T>::Stack() {
    this->size = 0;
    this->top = nullptr;
}

template<typename T> Stack<T>::~Stack() {
    freeNodes(this->top);
}

template <typename T> void Stack<T>::push(T object){
    Node<T> * newOBJ = new Node<T>(object);
    this->size++;
    newOBJ->next = this->top;
    this->top = newOBJ;
}

template <typename T> T Stack<T>::pop(){
    if(this->top == nullptr){
        throw "empty stack";
    }
    T retNode = this->top->data;
    Node<T> * temp = this->top;
    this->top = this->top->next;
    delete temp;
    this->size--;
    return retNode;
}

template <typename T> T Stack<T>::getTop(){
    if(this->top == nullptr){
        throw "empty stack";
    }
    return this->top->data;
}

template <typename T> bool Stack<T>::isEmpty(){
    return this->top == nullptr;
}

template<typename T> int Stack<T>::getSize() {
    return this->size;
}

#endif //PROJECT2_STACK_H
