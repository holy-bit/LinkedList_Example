#pragma once

#include <cstddef>
#include <string>
#include <iostream>

using namespace std;

template <typename E>
class Node {
public:
	E elem; //elemento del nodo
	Node* next; //Puntero al siguiente nodo
	Node* prev; //Puntero al nodo previo

	//Constructor de copia del elemento
	Node(Node<E> *prev, const E& elem, Node* next) :
		prev{ prev },
		elem{ elem },
		next{ next } {}

	//Constructor de move del elemento
	Node(Node<E>* prev, E&& elem, Node* next) : 
		prev{ prev },
		elem{ elem }, 
		next{ next } {}

	Node() = delete;

	//Constructor de copia de un nodo
	Node(const Node<E>& node)
	{
		elem = node.elem;
		cout << "-Node Copied." << endl;
	}

	//Constructor de move de un nodo
	Node(Node<E>&& node)
	{
		elem = move(node.elem);
		cout << "-Node moved." << endl;
	}

	//Operador de copia de un nodo
	Node<E>& operator=(const Node<E>& node) {  
		if (this != &node) elem = node.elem;
		return *this;
	}

	//Operado de move de un nodo
	Node<E>& operator=(Node<E>&& node) {
		if (this != &node) elem = move(node.elem);
		return *this;
	}

	//Destructor
	~Node() = default;
};
