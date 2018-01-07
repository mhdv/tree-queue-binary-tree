#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

// naglowki implementacji
#include "queue.h"
#include "tree.h"
#include "bintree.h"

// naglowek z innymi metodami
#include "othermethods.h"

int main(){

// // test sortowania przez kolejke priorytetowa
	
// 	int y=50;
// 	int* tab = new int[y];
// 	for(int i=0; i<y; i++){
// 		tab[i]=std::rand()%100;
// 		std::cout << tab[i] << "\n";
// 	}


// 	sortQueue<int>(tab,y);
	

// 	for(int i=0; i<y; i++){
// 		std::cout << tab[i] << "\n";
// 	}



// // test drzewa binarnego
// 	MyBinTree<int>* drzewobin = new MyBinTree<int>;
// 	drzewobin->add(1,0);
// 	drzewobin->add(2,1);
// 	drzewobin->add(4,2);
// 	drzewobin->add(3,1);
// 	drzewobin->add(5,3);
// 	drzewobin->add(6,1);
// 	drzewobin->add(7,3);
// 	drzewobin->add(8,7);
// 	drzewobin->remove(5);
// 	drzewobin->remove(8);
// 	drzewobin->add(100, 3);
// 	drzewobin->remove(1);

// 	drzewobin->add(1,1);
// 	drzewobin->add(2,1);
// 	drzewobin->add(3,2);
// 	drzewobin->add(4,3);
// 	std::cout << drzewobin->getHeight(drzewobin->getRoot()) << "\n";



// // test drzewa
// 	MyTree<int>* drzewo = new MyTree<int>;
// 	drzewo->add(1,1);
// 	drzewo->add(432, 1234);
// 	drzewo->add(1,1);
// 	drzewo->add(2,1);
// 	drzewo->add(55,1);
// 	drzewo->add(27,55);
// 	drzewo->add(100,55);
// 	drzewo->add(99, 2);
// 	drzewo->add(100,1);
// 	drzewo->add(225,55);
// 	drzewo->add(999,55);
// 	drzewo->add(202, 999);
// 	drzewo->add(404, 1);
// 	drzewo->add(405, 55);
// 	drzewo->remove(405);
// 	drzewo->add(15,1);
// 	drzewo->add(405,55);
// 	drzewo->remove(405);
// 	drzewo->remove(55);
// 	drzewo->remove(123456);

// 	drzewo->add(1,1);
// 	drzewo->add(2,1);
// 	drzewo->add(3,2);
// 	drzewo->add(4,3);	
// 	std::cout << drzewo->getHeight(drzewo->getRoot());



// //test kolejki priorytetowej
// 	MyQueue<int>* nowa = new MyQueue<int>;
// 	nowa->insert(1,5);
// 	nowa->insert(2,4);
// 	nowa->insert(3,3);
// 	nowa->insert(5,2);
// 	nowa->insert(4,1);
// 	displayQueue(nowa);
	return 0;
}