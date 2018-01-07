#ifndef BINTREENODE_H
#define BINTREENODE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

template <typename T>
class MyBinTree;
template <typename T>
class MyBinTreeNode{
private:

	int index; // index danego wezla
    T element; // zawartosc elementu
    MyBinTreeNode<T>* father; // wskaznik na nastepny element
    MyBinTreeNode<T>* left; // lewy syn
    MyBinTreeNode<T>* right; // prawy syn
    friend class MyBinTree<T>;

public:

    T getElement() {return element;} // zwraca element
    T removeSon(MyBinTreeNode<T>* elem) {
        MyBinTreeNode<T>* tmp2;
        tmp2=elem;
        delete elem;
        return tmp2->getElement();
    } // usuwa danego syna

    MyBinTreeNode<T>* getLeft() {return left;} // zwraca lewego syna
    MyBinTreeNode<T>* getRight() {return right;} // zwraca prawego syna
    MyBinTreeNode<T>* getFather() {return father;} // zwraca ojca


    void addSon(MyBinTreeNode<T>* son){if(left!=nullptr) right=son; else left=son;} // dodaje syna
    void setElement(T newE) {element=newE;} // ustala element
    void setFather(MyBinTreeNode<T>* newN) {father=newN;} // ustala ojca
    void setIndex(int x){index = x;}
    int getIndex(){return index;} // zwraca index

};

#endif