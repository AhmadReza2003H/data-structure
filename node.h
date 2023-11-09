//
// Created by AsusIran on 11/8/2023.
//

#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H
template <typename T> class Node{
public:
    Node(T data) : data(data) , next(nullptr){}
    T data;
    Node<T>* next;
};

template<typename T>

void freeNodes(Node<T> *node) {
    if(node == nullptr){
        return;
    }
    freeNodes(node->next);
    delete node;
}

template class Node<int>;
#endif //PROJECT2_NODE_H
