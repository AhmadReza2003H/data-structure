//
// Created by AsusIran on 11/8/2023.
//

#ifndef PROJECT2_VECTOR_H
#define PROJECT2_VECTOR_H

template <typename T> class Vector{
public:
    Vector();
    ~Vector();
    T operator[](int);
    T at(int);
    void add(T);
    void remove(T);
    void removeBack();
    int getSize();
    Vector<T> begin();
    Vector<T> end();
private:
    T * arr;
    int size;
    int capacity;
    void resize();

};

template <typename T>
Vector<T>::Vector(){
    this->capacity = 1;
    this->size = 0;
    this->arr = new T[this->capacity];
}

template <typename T>
Vector<T>::~Vector(){
    delete[] this->arr;
}

template <typename T>
T Vector<T>::operator[](int i) {
    if(i >= this->size){
        throw "index out of bounds";
    }
    return this->arr[i];
}

template <typename T>
T Vector<T>::at(int i) {
    if(i >= this->size){
        throw "index out of bounds";
    }
    return this->arr[i];
}

template <typename T>
void Vector<T>::add(T object) {
    this->arr[this->size++] = object;
    this->resize();
}

template <typename T>
void Vector<T>::resize() {
    if(this->size >= (this->capacity * 75)/100){
        this->capacity *= 2;
        this->arr = (T*) realloc(this->arr , this->capacity);
    } else if(this->size <= (this->size * 25)/100){
        this->capacity /= 2;
        this->arr = (T*) realloc(this->arr , this->capacity);
    }
}

template <typename T>
void Vector<T>::remove(T object) {
    for(int i = 0 ; i < this->size ; i++){
        if(this->arr[i] == object){
            for(int j = i + 1 ; j < this->size ; j++){
                this->arr[j-1] = this->arr[j];
            }
            this->size--;
            this->resize();
            break;
        }
    }
}

template <typename T>
void Vector<T>::removeBack() {
    if(this->size == 0){
        throw "under flow";
    }
    this->size--;
    this->resize();
}

template <typename T>
int Vector<T>::getSize() {
    return this->size;
}

#endif //PROJECT2_VECTOR_H
