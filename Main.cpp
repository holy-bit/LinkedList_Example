#include <cstddef>
#include <string>
#include <iostream>
#include <vector>

#include "ListTools.h"


int main() {

	string numPositions[]{ "1","2","3","4","5","6","7" };

	LinkedList<string> list{};

	

	Node<string>& firstnode = list.addFirst(numPositions[0]);
	Node<string>& lastnode = list.addLast(numPositions[6]);

	Node<string> lastnode2{ lastnode };
	cout << lastnode2.elem << endl;
	Node<string> lastnode3{ move(lastnode2) };
	cout <<"Nodo vacio:" << lastnode2.elem << endl;
	cout <<"Node movido:" << lastnode3.elem << endl;

	show(list);

	list.addAfter(firstnode, numPositions[4]);

	show(list);

	list.addAfter(firstnode, numPositions[3]);
	list.addAfter(firstnode, numPositions[2]);	
	list.addBefore(lastnode, numPositions[5]);

	show(list);

	list.setElem(firstnode, "first");
	Node<string>& newNode = list.addAfter(firstnode, numPositions[1]);

	show(list);

	list.remove(newNode);

	show(list);

	list.addAfter(firstnode, numPositions[1]);

	cout << "---Contructor de copia---" << endl;
	LinkedList<string> list2{ list };
	cout << "\n1)" << endl;
	show(list);
	cout << "\n2)" << endl;
	show(list2);

	cout << "---Contructor de move---" << endl;
	LinkedList<string> list3{move(list)};
	cout << "\n1)" << endl;
	show(list);
	cout << "\n2)" << endl;
	show(list2);

	cout << "---Operador = de copia---" << endl;
	list = list2;
	cout << "\n1)" << endl;
	show(list);
	cout << "\n2)" << endl;
	show(list2);

	cout << "---Operador = de move---" << endl;
	list2 = move(list);
	cout << "\n1)" << endl;
	show(list);
	cout << "\n2)" << endl;
	show(list2);

	cout << "---Pruebas de funcion Find---" << endl;

	find(list2, (string)"4");



	cin.get();
}