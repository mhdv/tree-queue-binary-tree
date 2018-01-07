#ifndef OTHERMETHODS_H
#define OTHERMETHODS_H

#include <iostream>

#include "queue.h"
#include "tree.h"

// metody pomocnicze dla kolejki priorytetowej
template <typename T>
void displayQueue(MyQueue<T>*& queue){
	if(!(queue->isEmpty())){
		MyQueue<T>* tmpq = queue;
		T tmp = queue->getSize();
		for(T i=0; i<tmp; i++){
			std::cout << i+1 << ") element o zawartosci: " << tmpq->removeMin() << "\n";
		}
	}else{ std::cout << "Kolejka jest pusta!\n"; return; }
}

template<typename T>
T* sortQueue(T*& tab, T y){
	MyQueue<T>* kolejka = new MyQueue<T>;
	for(int i=0; i<y; i++){
		kolejka->insert(tab[i], tab[i]);
	}
	for(int i=0; i<y; i++){
		tab[i]=kolejka->removeMin();
	}
	return tab;
}





#endif