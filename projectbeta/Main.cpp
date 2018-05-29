#include <cstddef>
#include <string>
#include <iostream>
#include <vector>

#include "List.h"
#include "List.cpp"

using namespace std;

int main() {

	string numPositions[]{ "1","2","3","4","5","6","7" };

	List<string> list{};
	List<int> l{};

	List<string>::iterator q{ list.addFirst(move(numPositions[0])) };

	cout << *q << endl;
	

	cin.get();
}