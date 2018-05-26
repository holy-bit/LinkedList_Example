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



////////////////////// LIST /////////////////////////////////

template<typename E>
inline typename List<E>::iterator List<E>::begin() const {
		return iterator{ head };
}

template <typename E>
inline typename List<E>::iterator List<E>::addFirst(const E& elem)
{
	return addFirst(std::move(E{ elem }));
}

template <typename E>
typename List<E>::iterator&  List<E>::addFirst(E&& elem)
{
	head = new List<E>::Node{ nullptr, elem, head };

	if (empty()) tail = head;
	else head->next->prev = head;
	++size_;
	cout << "\nFirst:" << head->elem << endl;

	return List<E>::iterator{ head };
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
inline typename List<E>::iterator List<E>::addAfter(const List<E>::iterator it, const E& elem)
{
	return addAfter(it,std::move(E{ elem }));
}

template <typename E>
typename List<E>::iterator List<E>::addAfter(const List<E>::iterator it, E&& elem)
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
