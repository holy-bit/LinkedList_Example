#pragma once
#include "LinkedList.h"

//Busca el elemento a partir de un nodo
template <typename E>
Node<E>& findFromPoint(const E& elem, Node<E>& point) {
	Node<E> f{ nullptr, "no encontrado",nullptr };
	return point.elem == elem ? point : point.next != nullptr ? findFromPoint(elem, *point.next) : f;
}

//Busca un elemento de una lista
template <typename E>
Node<E>& find(const E& elem, const LinkedList<E>& list) {
	Node<E> f{ nullptr, "lista vacia",nullptr };
	cout << endl;
	return !list.isEmpty() ? findFromPoint(elem, list.first()) : f;
}

//Busca un elemento de una lista
template <typename E>
void find(const LinkedList<E>& list,const E& elem) {
	Node<E> f{ nullptr, "lista vacia",nullptr };
	cout << endl;
	if (list.isEmpty())
		cout<<"Lista vacia."; 
	else cout <<"Se encontro el elemento:" << findFromPoint(elem, list.first()).elem;
}

//Muestra los elementos a partir de un nodo
template <typename E>
bool showListFromPoint(Node<E>& point)
{
	cout <<"--" << point.elem << endl;
	return point.next != nullptr ? showListFromPoint(*point.next) : false;
}

//Muestra los elementos de una lista
template <typename E>
void show(const LinkedList<E>& list) {
	cout << "\n----List----" << endl;
	if (!list.isEmpty()) showListFromPoint(list.first());
	else cout << "List empty" << endl;
	cout << endl;
}

