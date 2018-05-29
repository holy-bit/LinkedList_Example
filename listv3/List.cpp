#include "List.h"

//Constructor de copia de un nodo
template<typename E>
List<E>::Node::Node(Node* prev, const E& elem, Node* next) : 
	prev{ prev }, elem{ elem }, next{ next }

{}


//Constructor de move de un nodo
template<typename E>
List<E>::Node::Node(Node *prev, E&& elem, Node* next) :
	prev{ prev }, elem{ elem }, next{ next }

{}

/////////////////////// ITERATOR ////////////////////////

//Contructor estandar
template<typename E>
List<E>::iterator::iterator(Node* node_ptr): node_ptr { node_ptr } {}

//Constructor para end.
template<typename E>
List<E>::iterator::iterator(Node* node_ptr,Node* tail) : node_ptr{ node_ptr }, tail{tail} {}

//Constructor de copia
template<typename E>
List<E>::iterator::iterator(const iterator& it) : node_ptr{ it.node_ptr } {}

//Constructor de move
template<typename E>
List<E>::iterator::iterator(iterator&& it) : node_ptr{ move(it.node_ptr) } {}

//Operador de copia
template<typename E>
typename List<E>::iterator List<E>::iterator::operator=(const iterator& it) {
	node_ptr = it.node_ptr;
	return *this;
}

//Operador de move
template<typename E>
typename List<E>::iterator List<E>::iterator::operator=(iterator&& it) {
	this.node_ptr = move(it.node_ptr);
	return this;
}

//Operador para pasar al siguiente elemento
template<typename E>
typename List<E>::iterator& List<E>::iterator::operator++()
{
	node_ptr = node_ptr->next;
	return *this;
} 

//Operador para pasar al anterior elemento
template<typename E>
typename List<E>::iterator& List<E>::iterator::operator--()
{
	if (node_ptr != nullptr) 
		node_ptr = node_ptr->prev;
	else node_ptr = tail;
	return *this;
}

//Muestra el elemento del nodo
template<typename E>
E& List<E>::iterator::operator*()
{
	return node_ptr->elem;
}

//Puntero al elemento del nodo.
template<typename E>
E* List<E>::iterator::operator->() {
	return &(node_ptr->elem);
}

//Operador de comparacion ==
template<typename E>
bool List<E>::iterator::operator==(const iterator& it)
{
	return node_ptr == it.node_ptr ;
}

//Operador de desingualdad !=
template<typename E>
bool List<E>::iterator::operator!=(const iterator& it)
{
	return (node_ptr != it.node_ptr);
}

////////////////////// LIST /////////////////////////////////

//Constructor de copia
template<typename E>
List<E>::List(const List<E>& list) : size_{ list.size_ }, head{ list.head }, tail{ list.tail }
{
	List<E>::iterator it{ head };

	for (int x = 0; x < size_; ++x) {
		Node node{ it.node_ptr->prev, *it, it.node_ptr->next };
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


//Marca el primer elemento
template<typename E>
inline typename List<E>::iterator List<E>::begin() const {
		return iterator{ head };
}

//Marca la siguiente posicion a tail
template<typename E>
inline typename List<E>::iterator List<E>::end() const {
	return iterator { nullptr, tail };
}

//Cambia el elemento del nodo por uno nuevo.
template <typename E>
E& List<E>::setElem(iterator& it, const E& elem)
{
	E x = elem;

	cout << "\nElement(" << *it << ") changed to: " << elem << endl;
	*it = elem;

	return x;
}

//Añade el primer elemento haciendo una copia.
template <typename E>
inline typename List<E>::iterator List<E>::addFirst(const E& elem)
{
	return addFirst(std::move(E{ elem }));
}

//Añade el primer elemento haciend move
template <typename E>
typename List<E>::iterator  List<E>::addFirst(E&& elem)
{
	head = new List<E>::Node{ nullptr, elem, head };

	if (empty()) tail = head;
	else head->next->prev = head;
	++size_;
	cout << "\nFirst:" << head->elem << endl;

	return iterator { head };
}

//Añade el primer elemento haciendo una copia.
template <typename E>
inline typename List<E>::iterator List<E>::addLast(const E& elem)
{
	return addLast(std::move(E{ elem }));
}

//Añade el primer elemento haciendo move.
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

//Añade un elemento despues de la posicion del iterator haciendo una copia.
template <typename E>
inline typename List<E>::iterator List<E>::addAfter(const iterator it, const E& elem)
{
	return addAfter(it,std::move(E{ elem }));
}

//Añade un elemento despues de la posicion del iterator haciendo move.
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
	cout << "\nAfter(" << n->prev->elem << "): " << n->elem << endl;
	return List<E>::iterator{ n };
}

//Añade un elemento antes de la posicion del iterator haciendo una copia.
template <typename E>
inline typename List<E>::iterator List<E>::addBefore(const iterator it, const E& elem)
{
	return addBefore(it, std::move(E{ elem }));
}

//Añade un elemento anter de la posicion del iterator haciendo move.
template <typename E>
typename List<E>::iterator List<E>::addBefore(const iterator it, E&& elem)
{
	List<E>::Node* n = new List<E>::Node{ it.node_ptr->prev, elem, it.node_ptr };
	it.node_ptr->prev = n;
	if (n->prev == nullptr)
		head = n;
	else
		n->prev->next = n;
	++size_;

	cout << "\nBefore(" << n->next->elem << "): " << n->elem << endl;
	return List<E>::iterator{ n };
}

//Operador de copia
template <typename E>
void List<E>::operator=(const List<E>& list) {
	if (this != &list)
	{
		head = list.head;
		tail = list.tail;
		size_ = list.size_;
		List<E>::iterator it{ head };

		for (int x = 0; x < size_; ++x) 
		{
			Node node{ it.node_ptr->prev, *it, it.node_ptr->next };
			++it;
		}
	}
	
	cout << "List copied." << endl;
}

//Operador de move
template <typename E>
void List<E>::operator=(List<E>&& list) {
	head = list.head;
	tail = list.tail;
	size_ = list.size_;

	list.head = nullptr;
	list.tail = nullptr;
	list.size_ = 0;

	cout << "List moved." << endl;
}

//Borrado de un elemento
template <typename E>
E& List<E>::remove(iterator& it)
{
	E log = *it;

	cout << "\nElement(" << *it << ")Deleted" << endl;
	if (it.node_ptr == head)
	{
		head = it.node_ptr->next;
		it.node_ptr->next->prev = nullptr;
	}
	else if (it.node_ptr == tail)
	{
		tail = it.node_ptr->prev;
		it.node_ptr->prev->next = nullptr;
	}
	else {
		it.node_ptr->next->prev = it.node_ptr->prev;
		it.node_ptr->prev->next = it.node_ptr->next;
	}
	
	delete it.node_ptr;

	size_--;

	return log;
}

//Limpia la lista entera
template <typename E>
void List<E>::clear() {


		List<E>::iterator it{ begin() };
		List<E>::iterator temp{ begin() };
		while (size() > 1) {
			temp = it;
			it = ++it;
			remove(temp);

		}
		
		head = nullptr;
		tail = nullptr;
		--size_;		
}

//Muestra todos los elementos de la lista.
template<typename E>
inline typename void ListTools::show(List<E>& list)
{
	if (!list.empty())
	{	
		for (List<E>::iterator it{ list.begin() }; it != list.end(); ++it)
		{
			cout <<"--" <<*it << endl;
		}
	}
	else cout << "List is empty" << endl;

}




