#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "bintreenode.h"

// dokladne opisy metod w pliku .cpp

template <typename T>
class MyBinTree{
private:

	int size; // wielkosc drzewa
	MyBinTreeNode<T>* root; // korzen drzewa

public:

	MyBinTree(); // konstruktor
	~MyBinTree(); // destruktor 

	MyBinTreeNode<T>* find(const T& elem, MyBinTreeNode<T>* start); // funkcja wyszukujaca dany element od wskazanego wezla
	MyBinTreeNode<T>* remove(const T& elem); // funkcja usuwajaca dany element

	// T remove(T& elem); // to zla funkcja
	MyBinTreeNode<T>* getRoot(){return root;} // zwraca korzen

	bool isEmpty(); // zwraca prawde jesli drzewo jest puste
	void add(const T& elem, const T& where); // dodaje element we wskazanym miejscu do drzewa
	int getHeight(MyBinTreeNode<T>* start); // zwraca wysokosc drzewa od wskazanego wezla (domyslnie powinien byc root)
	int getSize() {return size;} // zwraca rozmiar drzewa (ilsoc wszystkich elementow drzewa)


};



#endif