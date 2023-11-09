//
// Created by AsusIran on 11/8/2023.
//

#ifndef PROJECT2_LINKEDLIST_H
#define PROJECT2_LINKEDLIST_H

#include "node.h"
template <typename T> class LinkedList{
public:
    LinkedList();
    ~LinkedList();
    int getSize();
    bool isEmpty();
    void removeFront();
    void removeBack();
    void remove(T object);
    void insertFront(T object);
    void insertBack(T object);
    T at(int);
    T begin();
    T end();
private:
    Node<T> * head;
    int size{};
};

template <typename T>
LinkedList<T>::LinkedList(){
    this->head = nullptr;
    this->size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    freeNodes(this->head);
}

template <class T>
int LinkedList<T>::getSize(){
    return this->size;
}

template <class T>
bool LinkedList<T>::isEmpty() {
    return this->size = 0;
}

template <class T>
void LinkedList<T>::removeFront() {
    if(this->head != nullptr){
        Node<T> * temp = this->head;
        this->head = head->next;
        this->size--;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::removeBack() {
    if(this->size == 1){
        Node<T> * temp = this->head;
        this->head = head->next;
        this->size--;
        delete temp;
    } else if(this->size > 1){
        Node<T> * headCopy = this->head;
        while (headCopy->next->next != nullptr){
            headCopy = headCopy->next;
        }
        delete headCopy->next;
        headCopy->next = nullptr;
        this->size--;
    }
}

template <class T>
void LinkedList<T>::remove(T object) {
    Node<T> * headCopy = this->head;
    if(this->size == 0){
        return;
    }
    if(this->head->data == object){
        this->head = this->head->next;
        this->size--;
        delete headCopy;
    } else {
        while (headCopy->next != nullptr){
            if(headCopy->next->data == object){
                Node<T>* temp = headCopy->next;
                headCopy->next = temp->next;
                delete temp;
                this->size--;
                break;
            }
            headCopy = headCopy->next;
        }
    }
}

template <class T>
void LinkedList<T>::insertBack(T object) {
    Node<T> *newObject = new Node<T>(object);
    if(head == nullptr){
        this->head = newObject;
    } else{
        Node<T> * copyHead = this->head;
        while (copyHead->next != nullptr){
            copyHead = copyHead->next;
        }
        copyHead->next = newObject;
    }
    this->size++;
}

template <class T>
void LinkedList<T>::insertFront(T object) {
    Node<T> * newObject = new Node<T>(object);

    if(head == nullptr){
        this->head = newObject;
    } else {
        newObject->next = this->head;
        this->head = newObject;
    }
    this->size++;
}

template <class T>
T LinkedList<T>::at(int i) {
    if(i >= this->size){
        throw "index out of bounds";
    }
    Node<T> * copyHead = this->head;
    while (i-- > 0){
        copyHead = copyHead->next;
    }
    return copyHead->data;
}
template <class T>
T LinkedList<T>::begin() {
    if(this->head == nullptr){
        throw "empty list";
    }
    return this->head->data;
}

template <class T>
T LinkedList<T>::end() {
    if(this->head == nullptr){
        throw "empty list";
    }
    Node<T> * headCopy = this->head;
    while (headCopy->next != nullptr){
        headCopy = headCopy->next;
    }
    return headCopy->data;
}

#endif //PROJECT2_LINKEDLIST_H
