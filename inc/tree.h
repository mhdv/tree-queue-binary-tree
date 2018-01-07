#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

#include "treenode.h"

// dokladne opisy metod w pliku .cpp

template <typename T>
class MyTree{
private:

	int size; // wielkosc drzewa
	int height; // wysokosc drzewa
	MyTreeNode<T>* root; // korzen drzewa

public:

	MyTree(); // konstruktor
	~MyTree(); // destruktor 

	MyTreeNode<T>* find(const T& elem, MyTreeNode<T>* start); // funkcja wyszukujaca dany element od wskazanego wezla
	MyTreeNode<T>* remove(const T& elem); // funkcja usuwajaca dany element

	// T remove(T& elem); // to zla funkcja
	MyTreeNode<T>* getRoot(){return root;} // zwraca korzen

	bool isEmpty(); // zwraca prawde jesli drzewo jest puste
	bool isExternal(MyTreeNode<T>* node); // sprawdza czy wezel jest lisciem
	void add(const T& elem, const T& where); // dodaje element we wskazanym miejscu do drzewa
	int getHeight(MyTreeNode<T>* start); // zwraca wysokosc drzewa od wskazanego wezla (domyslnie powinien byc root)
	int getSize() {return size;} // zwraca rozmiar drzewa (ilsoc wszystkich elementow drzewa)


};



#endif