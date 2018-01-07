#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

template <typename T>
class MyTree;
template <typename T>
class MyTreeNode{
private:

	int howmanysons=0; // ilu mamy synow
	int index; // index danego wezla
    T element; // zawartosc elementu
    MyTreeNode<T>* father; // wskaznik na nastepny element
    std::list<MyTreeNode<T>*> sons; // lista wskaznikow na synow
    friend class MyTree<T>;

public:

    T getElement() {return element;} // zwraca element
    T removeSon(MyTreeNode<T>* elem) {sons.remove(elem); howmanysons--; return elem->getElement();} // usuwa danego syna

    // FUNKCJA ZWRACAJACA KONKRETNEGO SYNA
    MyTreeNode<T>* getSon(int ind){
    	std::list<MyTreeNode<T>*> tmp = sons;
    	if(ind==0) return tmp.front();
    	else{
	    	for(int i=0; i<ind; i++){
	    		tmp.pop_front();
	    	}

	    	return tmp.front(); 
		}
    }
    MyTreeNode<T>* getFather() {return father;} // zwraca ojca

    void addSon(MyTreeNode<T>* son){sons.push_front(son); howmanysons++;} // dodaje syna
    void setElement(T newE) {element=newE;} // ustala element
    void setFather(MyTreeNode<T>* newN) {father=newN;} // ustala ojca
    void setIndex(int x){index = x;}
    int getIndex(){return index;} // zwraca index
    int getSons(){return howmanysons;}

};

#endif