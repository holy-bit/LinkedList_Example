#pragma once

//#ifndef LINKED_LIST
//#define LINKED_LIST

#include <cstddef>
#include <string>
#include <iostream>
#include <vector>
#include "Node.h"

template <typename E>
class LinkedList {

private:
	size_t size_; //Tamaño de la lista
	Node<E>*  head; //Primer nodo de la lista
	Node<E>*  tail; //Ultimo nodo de la lista

public:

	//Constructor
	LinkedList() : size_{ 0 }, head{ nullptr }, tail{ nullptr } {}

	//Constructor de copia
	LinkedList(LinkedList<E>& list) : size_{ list.size_ }, head{ list.head }, tail{ list.tail }
	{
		Node<E>* iterator = head;

		for (int x = 0; x < size_; ++x) {
			Node<E> node{ *iterator };
			iterator = iterator->next;
		}

		cout << "List copied." << endl;
	}

	//Constructor de move
	LinkedList(LinkedList<E>&& list) : size_{ list.size_ }, head{ list.head }, tail{ list.tail }
	{
		list.head = nullptr;
		list.tail = nullptr;
		list.size_ = 0;

		cout << "List moved." << endl;
	}


	//Operador de copia
	void operator=(const LinkedList<E>& list) {
		if (this != &list)
		{
			head = list.head;
			tail = list.tail;
			size_ = list.size_;

			Node<E>* iterator = head;

			for (int x = 0; x < size_; ++x) {
				Node<E> node{ *iterator };
				iterator = iterator->next;
			}
		}

		cout << "List copied." << endl;
	}

	//Operador de move
	void operator=( LinkedList<E>&& list) {
		head = list.head;
		tail = list.tail;
		size_ = list.size_;

		list.head = nullptr;
		list.tail = nullptr;
		list.size_ = 0;

		cout << "List moved." << endl;
	}
	
	//Comprueba si la lista esta vacia
	bool isEmpty() const { return size_ == 0; }

	//Devuelve el tamaño de la lista
	size_t size() const { return size_; }

	Node<E>& addFirst(const E& elem);

	Node<E>& addLast(const E& elem);

	Node<E>& addAfter(Node<E>& node, const E& elem);

	Node<E>& addBefore(Node<E>& node, const E& elem);

	E& remove(Node<E>& node);

	E& setElem(Node<E>& node, const E& elem);

	//Devuelve el siguiente nodo
	Node<E>& next(const Node<E>& node) const { return *node.next; };

	//Devuelve el nodo anterior
	Node<E>& prev(const Node<E>& node) const { return *node.prev; };

	//Devuelve el primer nodo
	Node<E>& first() const { return *head; };
	Node<E>&  last() const { return *tail; };

	template<typename E>
	class Iterator {
	private:
		Node* iterator;

	public:
		operator++();
		operator*();
		operator --();
		operator ==();
		operator !=();
		operator ->();
	};
};

//Añade un nodo en la primera posición.
template <typename E>
Node<E>&  LinkedList<E>::addFirst(const E& elem)
{
	Node<E>* nodeFirst = new Node<E>{ nullptr, elem, head };

	if (isEmpty()) tail = nodeFirst;
	else head->next->prev = nodeFirst;

	head = nodeFirst;
	size_++; 
	cout << "\nFirst:" << nodeFirst->elem << endl;

	return *head;
}

//Añade un nodo en la ultima posición.
template <typename E>
Node<E>& LinkedList<E>::addLast(const E& elem)
{
	Node<E>* nodeLast = new Node<E>{ tail, elem, nullptr };

	if (isEmpty()) head = nodeLast;
	else nodeLast->prev->next = nodeLast;


	tail = nodeLast;
	size_++;

	cout << "\nLast: " << nodeLast->elem << endl;

	return *tail;
}

//Añade un nodo despues del indicado.
template <typename E>
Node<E>& LinkedList<E>::addAfter(Node<E>& node, const E& elem)
{
	Node<E> *newNode = new Node<E>{ &node, elem, node.next };

	node.next->prev = newNode;
	newNode->prev->next = newNode;

	size_++;

	cout << "\nAfter(" << newNode->prev->elem << "): " << newNode->elem << endl;
	return *newNode;

}

//Añade un nodo antes del indicado
template <typename E>
Node<E>& LinkedList<E>::addBefore(Node<E>& node, const E& elem)
{
	Node<E> *newNode = new Node<E>{ node.prev, elem, &node };

	node.prev->next = newNode;
	newNode->next->prev = newNode;

	size_++;

	cout << "\nBefore(" << newNode->next->elem << "): " << newNode->elem << endl;

	return *newNode;
};

//Destruye el nodo pasado como argumento.
template <typename E>
E& LinkedList<E>::remove(Node<E>& node)
{
	string log = "Deleted";

	cout << "\nElement(" << node.elem << ")Deleted" << endl;

	node.next->prev = node.prev;
	node.prev->next = node.next;
	delete &node;

	size_--;

	return log;
};

//Cambia el elemento del nodo por uno nuevo.
template <typename E>
E& LinkedList<E>::setElem(Node<E>& node, const E& elem)
{
	string log = "Element Changed";

	cout << "\nElement(" << node.elem << ") changed to: " << elem << endl;
	node.elem = elem;

	return log;
}



