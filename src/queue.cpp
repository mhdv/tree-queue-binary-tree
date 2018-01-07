#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>

#include "queue.h"


// KONSTRUKTOR
template <typename T>
MyQueue<T>::MyQueue(){

	// stworzenie wezlow glowy i ogona
	head = new MyNode<T>;
	tail = new MyNode<T>;

	// deklaracje kluczy glowy i ogona - ustawienie wskaznikow glowy i ogona
	tail->setKey(-1);
	head->setKey(-1);
	tail->setNext(head);
	head->setPrevious(tail);

	// początkowy rozmiar to 0
	size=0;
}


// DESTRUKTOR
template <typename T>
MyQueue<T>::~MyQueue(){}


// FUNKCJA ZWRACAJACA ROZMIAR KOLEJKI
template <typename T>
int MyQueue<T>::getSize(){
	return size;
}

// FUNKCJA DODAJACA ELEMENT DO KOLEJKI - (k- klucz, elem- wartosc elementu)
template <typename T>
void MyQueue<T>::insert(int k, const T& elem){

	// deklaracja nowego wezla
	MyNode<T>* newnode = new MyNode<T>;

	// warunek zapobiegajacy wpisaniu blednego klucza
	if(k<=0) { std::cout << "Nieprawidlowy klucz\n"; return;}
	else{

		// warunek dzielacy funkcje na dodawanie PIERWSZEGO elemntu do kolejki oraz KAZDEGO INNEGO elementu
		if(isEmpty()){

			// pierwsza deklaracja zaleznosci miedzy ogonem, glowa, a pierwszym wezlem
			head->setNext(newnode);
			tail->setPrevious(newnode);

			// ustawienie wartosci pierwszego wezla
			newnode->setKey(k);
			newnode->setElement(elem);

			// ustawienie zaleznosci dla pierwszego wezla
			newnode->setNext(tail);
			newnode->setPrevious(head);

			// pomocnicze wyswietlanie zawartosci
			std::cout << "element: " << newnode->getElement() << "\n" << "klucz: " << newnode->getKey() << "\n";
			std::cout << "poprzedni: " << newnode->getPrevious()->getElement() << "\n";
			std::cout << "nastepny: " << newnode->getNext()->getElement() << "\n";

			// inkrementacja rozmiaru
			size++;
		}else{
			// wezel pomocniczy ustawiony jako glowa
			MyNode<T>* tmp = head;

			// petla ustawiajaca tmp na odpowiedni wezel
			do{
				tmp = tmp->getNext();
			}while(k>tmp->getKey() && tmp->getKey()!=-1);
			tmp = tmp->getPrevious();

			// ustawienie wartosci nowego wezla
			newnode->setKey(k);
			newnode->setElement(elem);

			// ustawienie odpowiednich zaleznosci dla nowego wezla
			newnode->setNext(tmp->getNext());
			newnode->setPrevious(tmp);

			// ustawienie odpowiednich zaleznosci sasiednich wezlow
			tmp->getNext()->setPrevious(newnode);
			tmp->setNext(newnode);

			// pomocnicze wyswietlanie zawartosci
			std::cout << "element: " << newnode->getElement() << "\n" << "klucz: " << newnode->getKey() << "\n";
			std::cout << "poprzedni: " << newnode->getPrevious()->getElement() << "\n";
			std::cout << "nastepny: " << newnode->getNext()->getElement() << "\n";

			// inkrementacja rozmiaru
			size++;
		}
	}
}

// FUNKCJA USUWAJACA ELEMENT O NAJMNIEJSZYM KLUCZU
template <typename T>
T MyQueue<T>::removeMin(){
	if(isEmpty()) {std::cout << "Kolejka nie istnieje\n"; return 0;}
	else{
		MyNode<T>* tmp = head->getNext();
		T tmp2 = head->getNext()->getElement();
		delete head->getNext();
		head->setNext(tmp->getNext());
		tmp = tmp->getNext();
		tmp->setPrevious(head);
		size--;
		return tmp2;
	}
}

// FUNKCJA ZWRACAJACA ELEMENT O NAJMNIEJSZYM KLUCZU
template <typename T>
T MyQueue<T>::min(){
	return head->getNext()->getElement();
}

// FUNKCJA SPRAWDZAJACA CZY KOLEJKA JEST PUSTA
template <typename T>
bool MyQueue<T>::isEmpty(){
	if(size>0) return false;
	else return true;
}


//############################





template class MyQueue<int>;
template class MyQueue<float>;
template class MyQueue<double>;