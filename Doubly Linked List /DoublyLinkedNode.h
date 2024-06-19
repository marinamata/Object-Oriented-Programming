//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLELINKEDNODE_H
#define LINKEDLIST_DOUBLELINKEDNODE_H
#include <iostream>

template<typename T>
class DoublyLinkedNode {
private:
    T data;
    DoublyLinkedNode<T>* next;
    DoublyLinkedNode<T>* prev;
public:
    DoublyLinkedNode<T>();
    DoublyLinkedNode<T>(const T& data);
    T& getData();
    const T& getData() const;
    DoublyLinkedNode<T>* getNext() const ;
    DoublyLinkedNode<T>* getPrev() const;
    void setNext(DoublyLinkedNode<T>* ptr);
    void setPrev(DoublyLinkedNode<T>* ptr);
};
template<typename T>
DoublyLinkedNode<T>::DoublyLinkedNode(){
    this->next = NULL;
    this->prev = NULL;
}
template<typename T>
DoublyLinkedNode<T>::DoublyLinkedNode(const T& data){
    this->data = data;
    this->next = NULL;
    this->prev = NULL;
}
template<typename T>
T& DoublyLinkedNode<T>::getData(){
    return this->data;
}

template<typename T>
const T& DoublyLinkedNode<T>::getData() const{
    return this->data;
}
template<typename T>
DoublyLinkedNode<T>* DoublyLinkedNode<T>::getNext() const{
    return this->next;
}
template<typename T>
DoublyLinkedNode<T>* DoublyLinkedNode<T>::getPrev() const{
    return this->prev;
}
template<typename T>
void DoublyLinkedNode<T>::setNext(DoublyLinkedNode<T>* ptr){
    this->next = ptr;
}
template<typename T>
void DoublyLinkedNode<T>::setPrev(DoublyLinkedNode<T>* ptr){
    this->prev = ptr;
}
#endif //LINKEDLIST_DOUBLELINKEDNODE_H
