#pragma once

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
		iterator(const iterator&);
		iterator(iterator&&);
		~iterator
		iterator operator=(const iterator&);
		iterator operator=(iterator&&);

		
		iterator& operator++();
		iterator& operator--() :
		bool operator!=(const iterator& it);
		bool operator==(const iterator& it);
		E& operator*();
		E* operator->();
		
	private:
		Node* node_ptr;
		iterator(Node*);


	};
	
	List() = default;
	//explicit List(const sdt::vector<E>&);
	//List(const T[], const std::size_t);
	List(const List<E>&);
	List(List<E>&&);
	iterator begin() const;
	iterator end() const;

	iterator addFirst(const E&);
	iterator addFirst(E&&);
	iterator addLast(const E&);
	iterator addLast(const E&&);
	iterator addAfter(const iterator, const E&);
	iterator addAfter(iterator, E&&);
	E& remove(const iterator);
	void clear();

private:

	size_t size_; //Tamaño de la lista
	Node*  head; //Primer nodo de la lista
	Node*  tail; //Ultimo nodo de la lista

};
