#include <cstddef>
#include <string>
#include <iostream>
#include <vector>


#include "List.h"
#include "List.cpp"

using namespace std;

int main() {
	ListTools tools;
	string numPositions[]{ "1","2","3","4","5","6","7" };
	List<string> list{};
	List<string>::iterator first{ list.addFirst(numPositions[0]) };
	List<string>::iterator last{ list.addLast(numPositions[6]) };

	//cout << *last << endl;

	list.addAfter(first,numPositions[1]);
	
	tools.show(list);

	list.addAfter(first, numPositions[3]);
	list.addAfter(first, numPositions[2]);
	list.addBefore(first, numPositions[5]);

	tools.show(list);
	
	list.setElem(first, "first");

	tools.show(list);

	list.remove(list.end());
	
	list.clear();


	cin.get();
}

