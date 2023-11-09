#ifndef PROJECT2_QUEUE_H
#define PROJECT2_QUEUE_H

#include "node.h"

template <typename T> class Queue{
public:
    Queue();
    ~Queue();
    T deQueue();
    T getFront();
    void enQueue(T object);
    bool isEmpty();
    int getSize();
private:
    Node<T> * front;
    int size;
};

template <typename T> Queue<T>::Queue() {
    this->size = 0;
    this->front = nullptr;
}

template <typename T> Queue<T>::~Queue() {
    freeNodes(this->front);
}

template <typename T> T Queue<T>::deQueue() {
    if(this->front == nullptr){
        throw "empty stack";
    }
    T retNode = this->front->data;
    Node<T> * temp = this->front;
    this->front = this->front->next;
    delete temp;
    this->size--;
    return retNode;
}

template <typename T> T Queue<T>::getFront() {
    if(this->front == nullptr){
        throw "empty queue";
    }
    return this->front->data;
}

template <typename T> void Queue<T>::enQueue(T object) {
    Node<T> * newOBJ = new Node<T>(object);
    this->size++;
    if(this->front == nullptr){
        this->front = newOBJ;
    } else{
        Node<T> * temp = this->front;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newOBJ;
    }
}

template <typename T> bool Queue<T>::isEmpty() {
    return this->front == nullptr;
}

template <typename T> int Queue<T>::getSize() {
    return this->size;
}
#endif //PROJECT2_QUEUE_H
