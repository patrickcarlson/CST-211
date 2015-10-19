#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename T>
class Iterator
{
public:
	Iterator(Node<T> *P);
	/*Iterator(const Iterator& copy);
	~Iterator();
	Iterator& operator =(const Iterator& rhs);
	*/
	Iterator& operator++();
	Iterator& operator++(int input);
	Iterator& operator--();
	Iterator& operator--(int input);
	T& operator*();
	bool operator==(const Iterator& other);
	bool operator!=(const Iterator& other);

	Node<T>& getItNode();

private:
	Node<T>* m_node;

};


#include "Iterator.inc"
#endif