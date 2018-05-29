#include <cstddef>
#include <string>
#include <iostream>
#include <vector>


#include "List.h"
#include "List.cpp"

using namespace std;


int main() {
	//char input;
	ListTools tools;

	string numPositions[]{ "1","2","3","4","5","6","7" };


	
	cout << "---1.string,2.int---" << endl;
	//cin >> input;
	/*
	switch (input)
	{
	case'1':
		List<string> list{};
		List<string>::iterator first{ list.addFirst(numPositions[0]) };
		List<string>::iterator last{ list.addLast(numPositions[6]) };
		break;
	case'2':
		
		List<int> list{};
		List<int>::iterator first{ list.addFirst(numPositions[0]) };
		List<int>::iterator last{ list.addLast(numPositions[6]) };
		break;
	default:
		break;
	}*/

	List<string> list{};
	List<string>::iterator first{ list.addFirst(numPositions[0]) };
	List<string>::iterator last{ list.addLast(numPositions[6]) };


	//cout << *last << endl;

	
	
	tools.show(list);

	
	list.addAfter(list.addAfter(first, numPositions[1]), numPositions[2]);
	list.addAfter(++list.addBefore(list.addBefore(last, numPositions[4]),numPositions[3]), numPositions[5]);

	tools.show(list);
	
	list.setElem(first, "first");

	list.remove(--list.end());
	tools.show(list);


	cout << "---Contructor de copia---" << endl;
	List<string> list2{ list };
	cout << "\n1)" << endl;
	tools.show(list);
	cout << "\n2)" << endl;
	tools.show(list2);

	cout << "---Contructor de move---" << endl;
	List<string> list3{ move(list) };
	cout << "\n1)" << endl;
	tools.show(list);
	cout << "\n2)" << endl;
	tools.show(list2);
	cout << "---Operador = de copia---" << endl;
	list = list2;
	cout << "\n1)" << endl;
	tools.show(list);
	cout << "\n2)" << endl;
	tools.show(list2);


	cout << "---Operador = de move---" << endl;
	list2 = move(list);
	cout << "\n1)" << endl;
	tools.show(list);
	cout << "\n2)" << endl;
	tools.show(list2);
	
	cout << "---Pruebas de funcion Find---" << endl;

	//find(list2, (string)"4");
	list2.remove(first);

	list2.clear();

	tools.show(list);

	cin.get();
}

