#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

#include "bintree.h"


// KONSTRUKTOR
template <typename T>
MyBinTree<T>::MyBinTree(){
	size=0;
	root = new MyBinTreeNode<T>;
	root->setFather(nullptr);
	root->addSon(nullptr);
	root->addSon(nullptr);
}

// DESTRUKTOR
template <typename T>
MyBinTree<T>::~MyBinTree(){ }

// ZWRACA PRAWDE JESLI DRZEWO JEST PUSTE
template <typename T>
bool MyBinTree<T>::isEmpty(){
	if(size==0) return true;
	else return false;
}

// REKURENCYJNA FUNKCJA WYSZUKUJACA DANY ELEMENT OD WSKAZANEGO WSKAZNIKA
template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::find(const T& elem, MyBinTreeNode<T>* start){
	if(start->getElement()==elem) return start;
	else{
		if(start->getLeft()!=nullptr){
			if(find(elem, start->getLeft())!=nullptr){
				return find(elem, start->getLeft());
			}
		}
		if(start->getRight()!=nullptr){
			if(find(elem, start->getRight())!=nullptr){
				return find(elem, start->getRight());
			}
		}
		return nullptr;
	}
}

// FUNKCJA DODAJACA ELEMENT DO DRZEWA WE WSKAZANYM MIEJSCU
template <typename T>
void MyBinTree<T>::add(const T& elem, const T& where){
	if(isEmpty()){
		root->setElement(elem);
		root->setIndex(size);
		size++;

		// POMOCNICZE COUTY
		std::cout << "OTO NOWY ELEMENT: " << root->getElement() << "\n";
		std::cout << "----------------------------------\n";
	}else{
		MyBinTreeNode<T>* newnode = new MyBinTreeNode<T>;
		MyBinTreeNode<T>* tmp = find(where, root);

		if(tmp==nullptr){

			// POMOCNICZE COUTY
			std::cout << "----------------------------------\n";
			std::cout << "Nie ma takiego ojca!\n";
			std::cout << "----------------------------------\n";

			return;

		}

		newnode->setFather(tmp);
		newnode->addSon(nullptr);
		newnode->addSon(nullptr);
		if(tmp->getLeft()!=nullptr && tmp->getRight()!=nullptr){
			// POMOCNICZE COUTY
			std::cout << "----------------------------------\n";
			std::cout << "Ojciec ma juz dwoch synow!\n";
			std::cout << "----------------------------------\n";
			delete newnode;
			return;
		}else
		tmp->addSon(newnode);
		newnode->setElement(elem);
		newnode->setIndex(size);
		size++;

		// POMOCNICZE COUTY
		std::cout << "----------------------------------\n";
		std::cout << "Dodany element: " << newnode->getElement() << "\n";
		std::cout << "Ojciec tego elementu: " << newnode->getFather()->getElement() << "\n";
		std::cout << "----------------------------------\n";

	}
}

// FUNKCJA DO USUWANIA ELEMENTU DRZEWA
template <typename T>
MyBinTreeNode<T>* MyBinTree<T>::remove(const T& elem){
	if(size==0) {std::cout << "Drzewo jest puste!\n"; return nullptr;}
	else{

		// ZMIENNA POMOCNICZA PRZYMUJACA RETURN Z FIND
		MyBinTreeNode<T>* tmp = find(elem, root);
		if(tmp==nullptr) {

			// POMOCNICZE COUTY
			std::cout << "----------------------------------\n";
			std::cout << "Nie ma takiego elementu!\n";
			std::cout << "----------------------------------\n";

			return nullptr;
		}
		else{
			// ELEMENT ISTNIEJE I NIE MA SYNOW - USUWANIE
			if(tmp->getRight()==nullptr && tmp->getLeft()==nullptr) {tmp->getFather()->removeSon(tmp); tmp->getFather()->addSon(nullptr); size--; return tmp;}
			else {
				// POMOCNICZE COUTY
				std::cout << "----------------------------------\n";
				std::cout << "Proba usuniecia elementu, ktory nie jest lisciem!\n";
				std::cout << "----------------------------------\n";

				return nullptr;
			}
		}
	}
}

// FUNKCJA ZWRACAJACA WYSOKOSC DRZEWA (REKURENCYJNA)
template <typename T>
int MyBinTree<T>::getHeight(MyBinTreeNode<T>* start){
	if(start == nullptr) return 0;
	int leftheight = getHeight(start->getLeft());
	int rightheight = getHeight(start->getRight());

	if(leftheight > rightheight) {
        return leftheight + 1;
    } else {
        return rightheight + 1;
    }
}

template class MyBinTree<int>;
template class MyBinTree<float>;
template class MyBinTree<double>;