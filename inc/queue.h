#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "node.h"

// opisy poszczegolnych metod w pliku .cpp
// wyswietlanie calej kolejki jako zewnetrzna metoda

template <typename T>
class MyQueue{
protected:

	int size;
	MyNode<T>* head;
	MyNode<T>* tail;

public:

	MyQueue();
	~MyQueue();

	int getSize();
	T min();
	void insert(int k, const T& elem);
	bool isEmpty();
	T removeMin();
	MyNode<T>* getHead() {return head;}
	MyNode<T>* getTail() {return tail;}

};

#endif