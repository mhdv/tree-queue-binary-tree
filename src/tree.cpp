#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

#include "tree.h"


// KONSTRUKTOR
template <typename T>
MyTree<T>::MyTree(){
	size = 0;
	height = 0;
	root = new MyTreeNode<T>;
	root->setFather(nullptr);
}

// DESTRUKTOR
template <typename T>
MyTree<T>::~MyTree(){ }

// ZWRACA PRAWDE JESLI DRZEWO JEST PUSTE
template <typename T>
bool MyTree<T>::isEmpty(){
	if(size==0) return true;
	else return false;
}

// REKURENCYJNA FUNKCA WYSZUKUJACA DANY ELEMENT OD WSKAZANEGO WSKAZNIKA
template <typename T>
MyTreeNode<T>* MyTree<T>::find(const T& elem, MyTreeNode<T>* start){
	if(start->getElement()==elem) return start;
	else{
		if(start->getSons()!=0){
			for(int i=0; i<(start->getSons()); i++){
				if(find(elem, start->getSon(i))!=nullptr){ return find(elem, start->getSon(i));}
			}
		}else{
			return nullptr;
		}
	return nullptr;
	}
return nullptr;
}

// FUNKCJA DODAJACA ELEMENT DO DRZEWA WE WSKAZANYM MIEJSCU
template <typename T>
void MyTree<T>::add(const T& elem, const T& where){
	if(isEmpty()){
		root->setElement(elem);
		root->setIndex(size);
		size++;

		// POMOCNICZE COUTY
		std::cout << "OTO NOWY ELEMENT: " << root->getElement() << "\n";
		std::cout << "----------------------------------\n";
	
	}else{

		// DODAWANIE DLA NIEPUSTEGO DRZEWA
		MyTreeNode<T>* newnode = new MyTreeNode<T>;
		MyTreeNode<T>* tmp = find(where,root);

		if(tmp==nullptr) {

			// POMOCNICZE COUTY
			std::cout << "----------------------------------\n";
			std::cout << "Nie ma takiego ojca!\n";
			std::cout << "----------------------------------\n";

			return;
		}

		newnode->setFather(tmp);
		
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
MyTreeNode<T>* MyTree<T>::remove(const T& elem){
	if(size==0) {std::cout << "Drzewo jest puste!\n"; return nullptr;}
	else{

		// ZMIENNA POMOCNICZA PRZYMUJACA RETURN Z FIND
		MyTreeNode<T>* tmp = find(elem, root);
		if(tmp==nullptr) {

			// POMOCNICZE COUTY
			std::cout << "----------------------------------\n";
			std::cout << "Nie ma takiego elementu!\n";
			std::cout << "----------------------------------\n";

			return nullptr;
		}
		else{
			// ELEMENT ISTNIEJE I NIE MA SYNOW - USUWANIE
			if(tmp->getSons()==0) {tmp->getFather()->removeSon(tmp); size--; return tmp;}
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

// FUNKCJA ZWRACAJACA PRAWDE JESLI WEZEL JEST LISCIEM
template <typename T>
bool MyTree<T>::isExternal(MyTreeNode<T>* node){
	if(node->getSons()==0) return true;
	else return false;
}

// FUNKCJA ZWRACAJACA WYSOKOSC DRZEWA (REKURENCYJNA)
template <typename T>
int MyTree<T>::getHeight(MyTreeNode<T>* start){
	if(isEmpty()) {return 0;}
	if(isExternal(start)) return 1+height;
	else{
		for(int i=0; i<start->getSons(); i++){
			height=std::max(height, getHeight(start->getSon(i))); return 1+height;
		}
	}
	return 1+height;
}


//############################

template class MyTree<int>;
template class MyTree<float>;
template class MyTree<double>;