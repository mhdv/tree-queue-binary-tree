#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <cstdlib>

template <typename T>
class MyQueue;
template <typename T>
class MyNode{
private:
	int key; // klucz do kolejki priorytetowej
    T element; // zawartosc elementu
    MyNode<T>* next; // wskaznik na nastepny element
    MyNode<T>* previous; // wskaznik na poprzedni element
    friend class MyQueue<T>;
public:
    T getElement() {return element;} // zwraca element
    MyNode<T>* getPrevious() {return previous;} // zwraca previous
    MyNode<T>* getNext() {return next;} // zwraca next
    int getKey() {return key;} // zwraca key
    void setElement(T newE) {element=newE;} // ustala element
    void setNext(MyNode<T>* newN) {next=newN;} // ustala next
    void setPrevious(MyNode<T>* newP) {previous=newP;} // ustala previous
    void setKey(unsigned int k) {key=k;}
};


#endif