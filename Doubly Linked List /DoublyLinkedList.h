//
// Created by mfbut on 2/11/2019.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#include <vector>
#include <memory>
#include "DoublyLinkedNode.h"
#include "DoublyLinkedListEmptyError.h"
#include "DoublyLinkedListOutOfBoundsError.h"
#include "ConstDoublyLinkedListIterator.h"
#include "DoublyLinkedListIterator.h"
#include "ConstReverseDoublyLinkedIterator.h"
#include "ReverseDoublyLinkedListIterator.h"

template<typename T>
class DoublyLinkedList {
 public:
  using Node_Ptr = DoublyLinkedNode<T>*;

  using iterator = DoublyLinkedListIterator<T>; //put the type of your iterator here
  using const_iterator = ConstDoublyLinkedListIterator<T>; //put the type of your const iterator here
  using reverse_iterator =ReverseDoublyLinkedListIterator<T>; //put the type of your reverse iterator here
  using const_reverse_iterator = ConstReverseDoublyLinkedListIterator<T>; //put the type of your const reverse iterator here

  //create a Doubly Linked List that has the same values
  //as in the vector and in the same order
  explicit DoublyLinkedList(const std::vector<T>& values);

  //create an empty DoublyLinkedList
  DoublyLinkedList();


  //destructor
  virtual ~DoublyLinkedList();

  //remove all of the elements from your list
  void clear();

  //get a reference to the front element in the list
  const T& front() const;
  T& front();

  //get a reference to the last element in the list
  const T& back() const;
  T& back();

  //add a value to the front of the list
  void push_front(const T& value);

  //add a value to the back of the list
  void push_back(const T& value);

  //is the list empty?
  bool empty() const;

  //return the number of elements in the list
  int size() const;

  //return a constant bidirectional iterator to the front of the list
  const_iterator begin() const;
  const_iterator end() const;

  //return a nonconstant bidirectional iterator to the front of the list
  iterator begin();
  iterator end();

  const_reverse_iterator crbegin() const;
  const_reverse_iterator crend() const;

  reverse_iterator rbegin();
  reverse_iterator rend();

  //insert the value at the position in the list
  //I promise not to use the iterator again after the insertion is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And the iterator was pointing to the 9 and we wanted to
  //insert -22 the result would be
  //1 <-> 22 <-> 9 <-> 17
  void insert(iterator& position, const T& value);

  //remove the element at the position pointed to
  //by the iterator.
  //I promise not to use the iterator again after the erase is done
  //An example if we had the list 1 <-> 9 <-> 17
  //And when the wanted to erase the iterator was at the 9
  //1 <-> 17
  void erase(iterator& position);

 private:
    Node_Ptr head;
    Node_Ptr tail;
};
/*
template<typename T>
DoublyLinkedNode<T>* DoublyLinkedList<T>::getHead(){
    return head;
}*/

//write to the stream each element in the list in order
//with a space in between them
template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList);

//read elements from the stream as long as it is good
// or until a newline (\n) is encountered
//if a newline is encountered it should be consumed
template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList);

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()  {
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const std::vector<T>& values)  {
    head = nullptr;
    tail = nullptr;
    Node_Ptr ptr ;
    for(int i =0;i<(int)values.size();i++){
        //DoublyLinkedNode<T> placer(values[i]);
        ptr = new DoublyLinkedNode<T>(values[i]);
        if(this->head == nullptr){
            head = ptr;
            tail = ptr;
            //std::cout<<"1."<<this->head->getData()<<std::endl;
        }
        else{
            tail->setNext(ptr);
            ptr->setPrev(tail);
           tail = ptr;
           // std::cout<<"2."<<tail->getData()<<std::endl;
        }
    }
}

template<typename T>
bool DoublyLinkedList<T>::empty() const {
    if(head==nullptr){
        return true;
    }
    return false;
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    int count = 0;
    //std::cout<<this->head->getData()<<std::endl;
    DoublyLinkedNode<T>* ptr = head;
    while(ptr != nullptr){
        count++;
        ptr = ptr -> getNext();
    }
   // std::cout<<"count = "<<count<<std::endl;
    return count;
}

template<typename T>
const T& DoublyLinkedList<T>::front() const {
    return head->getData();
}

template<typename T>
T& DoublyLinkedList<T>::front() {
   // std::cout<<head->getData();
    return (T&)head->getData();
}

template<typename T>
const T& DoublyLinkedList<T>::back() const {
    //std::cout<<head->getData();
    return (T&)tail->getData();
}

template<typename T>
T& DoublyLinkedList<T>::back() {
    return tail->getData();
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value) {
    Node_Ptr newNode ;
    newNode = new DoublyLinkedNode<T>(value);
    newNode->setPrev(nullptr);
    newNode->setNext(head);
    head = newNode;
    if(tail == nullptr){
        tail = newNode;
    }
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
    Node_Ptr newNode ;
    newNode = new DoublyLinkedNode<T>(value);
    newNode->setPrev(tail);
    newNode->setNext(nullptr);
    tail = newNode;
    if(head == nullptr){
        head = newNode;
    }
}

template<typename T>
void DoublyLinkedList<T>::clear() {
    Node_Ptr a = head;
    while(a != nullptr){
        Node_Ptr temp = a->getNext();
        free(a);
        a = temp;

    }
    //head = nullptr;
    //tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::begin() const {
    return const_iterator(head);
}

template<typename T>
typename DoublyLinkedList<T>::const_iterator DoublyLinkedList<T>::end() const {
    return const_iterator(tail->getNext());//error
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::begin() {
    return iterator(head);
}

template<typename T>
typename DoublyLinkedList<T>::iterator DoublyLinkedList<T>::end() {
    return iterator(tail->getNext());//error
}

template<typename T>
void DoublyLinkedList<T>::insert(iterator& position, const T& value) {
    iterator count = begin();
    Node_Ptr a = new DoublyLinkedNode<T>(value);
    Node_Ptr ptr = head;
    while(ptr != nullptr){
        if(count == position){
            a->setPrev(ptr);
            a->setNext(ptr->getNext());
            ptr->setNext(a);
            break;
        }
        count++;
        ptr = ptr->getNext();
    }
}

template<typename T>
void DoublyLinkedList<T>::erase(iterator& position) {
    iterator count(head);
    Node_Ptr ptr;
    try{
        ptr = head;
        while(ptr != nullptr){
            if(count == position){
                ptr->getPrev()->setNext(ptr->getNext());
                ptr->getNext()->setPrev(ptr->getPrev());
                free(ptr);
                break;
            }
            count++;
            ptr = ptr->getNext();
        }
    }
    catch(DoublyLinkedListEmptyError& e){
        std::cout<<e.errorMessage();
    }

}

template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crbegin() const {
    return const_reverse_iterator(tail);
}


template<typename T>
typename DoublyLinkedList<T>::const_reverse_iterator DoublyLinkedList<T>::crend() const {
    return const_reverse_iterator(head->getPrev());

}

template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rbegin() {
    return reverse_iterator(tail);
}


template<typename T>
typename DoublyLinkedList<T>::reverse_iterator DoublyLinkedList<T>::rend() {
    return reverse_iterator(head->getPrev());
}


template<typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& doublyLinkedList) {
    DoublyLinkedListIterator<T> ptr =doublyLinkedList.begin();
    while(ptr != doublyLinkedList.end()){
        out << *ptr;
        ptr++;
    }
    return out;

}

template<typename T>
std::istream& operator>>(std::istream& in, DoublyLinkedList<T>& doublyLinkedList) {
    DoublyLinkedListIterator<T> ptr = doublyLinkedList.begin();
    while(ptr != doublyLinkedList.end()){
        in >> *ptr;
        ptr++;
    }
    return in;

}

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H
