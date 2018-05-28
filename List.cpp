#include "List.h"


template<typename E>
List<E>::Node::Node(Node* prev, const E& elem, Node* next) : 
	//List(prev, std::move(E{ elem }), next)
	prev{ prev }, elem{ elem }, next{ next }

{}



template<typename E>
List<E>::Node::Node(Node *prev, E&& elem, Node* next) :
	//List(prev, std::move(E{ elem }), next)
	prev{ prev }, elem{ elem }, next{ next }

{}

template<typename E>
List<E>::iterator::iterator(Node* node_ptr): node_ptr { node_ptr } {}

template<typename E>
List<E>::iterator::iterator(const iterator& it) : node_ptr{ it.node_ptr } {}

template<typename E>
List<E>::iterator::iterator(iterator&& it) : node_ptr{ move(it.node_ptr) } {}

template<typename E>
typename List<E>::iterator List<E>::iterator::operator=(const iterator& it) {
	this.node_ptr = it.node_ptr;
	return this;
}

template<typename E>
typename List<E>::iterator List<E>::iterator::operator=(iterator&& it) {
	this.node_ptr = move(it.node_ptr);
	return this;
}

template<typename E>
typename List<E>::iterator& List<E>::iterator::operator++()
{
	node_ptr = node_ptr->next;
	return *this;
} 

template<typename E>
E& List<E>::iterator::operator*()
{
	return node_ptr->elem;
}

template<typename E>
E* List<E>::iterator::operator->() {
	return &(node_ptr->elem);
}

template<typename E>
bool List<E>::iterator::operator==(const iterator& it)
{
	return this.node_ptr == it.node_ptr ? true : false;
}

template<typename E>
bool List<E>::iterator::operator!=(const iterator& it)
{
	return !(this == it) ? true : false;
}

////////////////////// LIST /////////////////////////////////

//Constructor de copia
template<typename E>
List<E>::List(const List<E>& list) : size_{ list.size_ }, head{ list.head }, tail{ list.tail }
{
	List<E>::iterator it{ head };

	for (int x = 0; x < size_; ++x) {
		Node<E> node{ it.node_ptr->prev, *it, it.node_ptr->next };
		++it;
	}

	cout << "List copied." << endl;
}

//Constructor de move
template<typename E>
List<E>::List(List<E>&& list) : size_{ list.size_ }, head{ list.head }, tail{ list.tail }
{
	list.head = nullptr;
	list.tail = nullptr;
	list.size_ = 0;

	cout << "List moved." << endl;
}



template<typename E>
inline typename List<E>::iterator List<E>::begin() const {
		return iterator{ head };
}

template<typename E>
inline typename List<E>::iterator List<E>::end() const {
	return iterator{ tail };
}

template <typename E>
inline typename List<E>::iterator List<E>::addFirst(const E& elem)
{
	return addFirst(std::move(E{ elem }));
}

template <typename E>
typename List<E>::iterator  List<E>::addFirst(E&& elem)
{
	head = new List<E>::Node{ nullptr, elem, head };

	if (empty()) tail = head;
	else head->next->prev = head;
	++size_;
	cout << "\nFirst:" << head->elem << endl;

	return iteratar x{ head };
}

template <typename E>
inline typename List<E>::iterator List<E>::addLast(const E& elem)
{
	return addLast(std::move(E{ elem }));
}

template <typename E>
typename List<E>::iterator List<E>::addLast(E&& elem)
{ 
	tail = new List<E>::Node{ tail, elem, nullptr };
	if (empty()) head = tail;
	else tail->prev->next = tail;
	++size_;
	cout << "\nLast: " << tail->elem << endl;
	return List<E>::iterator{ tail };
}

template <typename E>
inline typename List<E>::iterator List<E>::addAfter(const iterator it, const E& elem)
{
	return addAfter(it,std::move(E{ elem }));
}

template <typename E>
typename List<E>::iterator List<E>::addAfter(const iterator it, E&& elem)
{
	List<E>::Node* n = new List<E>::Node{ it.node_ptr, elem, it.node_ptr->next };
	it.node_ptr->next = n;
	if (n->next == nullptr)
		tail = n;
	else
		n->next->prev = n;
	++size_;
	return List<E>::iterator{ n };
}

template <typename E>
E& List<E>::remove(const iterator it)
{
	E log = *it;

	cout << "\nElement(" << *it << ")Deleted" << endl;

	it.node_ptr->next->prev = it.node_ptr->prev;
	it.node_ptr->prev->next = it.node_ptr->next;
	delete *it;

	size_--;

	return log;
};
template <typename E>
void List<E>::clear() {

}



