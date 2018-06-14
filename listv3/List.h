#pragma once
#include <cstddef>
#include <string>
#include <iostream>
#include <stdexcept>
#include <vector>
#ifndef LIST
#define LIST



template<typename E>
class List {

private:
	class Node {
	public:

		Node* prev;
		E elem;
		Node* next;
		
		Node(Node*, const E&, Node*);

		Node(Node*, E&&, Node*);

		Node() = delete;
		Node(const Node&)=delete;
		Node(Node&&) = delete;
		Node& operator=(const Node&) = delete;
		Node& operator=(Node&&) = delete;
		bool& operator==(const Node&) = delete;
		bool& operator!=(const Node&) = delete;
		bool& operator==(Node&) = delete;
		bool& operator!=(Node&) = delete;
		~Node() = default;
	};
public:
	class iterator {
	public:
		friend class List;
		iterator() = delete;
		iterator(const iterator&);
		iterator(iterator&&);
		~iterator() = default;
		iterator operator=(const iterator&);
		iterator operator=(iterator&&);

		
		iterator& operator++();
		iterator& operator--();
		bool operator!=(const iterator& it);
		bool operator==(const iterator& it);
		E& operator*();
		E* operator->();
		
	private:
		Node* node_ptr;
		Node* prev;
		size_t id;
		iterator(Node*, size_t);
		iterator(Node*,Node*, size_t);


	};
	
	size_t id; //ID de la lista
	List();
	//explicit List(const sdt::vector<E>&);
	//List(const T[], const std::size_t);
	List(const List<E>&);
	List(List<E>&&);
	size_t size() const { return size_; }
	bool empty() { return size_ == 0; }

	iterator begin() const;
	iterator end() const;

	iterator addFirst(const E&);
	iterator addFirst(E&&);
	iterator addLast(const E&);
	iterator addLast(E&&);
	iterator addAfter(const iterator, const E&);
	iterator addAfter(iterator, E&&);
	iterator addBefore(const iterator, const E&);
	iterator addBefore(iterator, E&&);

	//Operador de copia
	void operator=(const List<E>&);

	void operator=(List<E>&&);
		
	void remove(iterator&);
	void clear();

	


	static size_t IdGenerator();


private:

	size_t size_; //Tamaño de la lista
	Node*  head; //Primer nodo de la lista
	Node*  tail; //Ultimo nodo de la lista

	static size_t IdCount;

};


class ListTools{
public:
	template<typename E>
	void show(List<E>&);
	
};


#endif



