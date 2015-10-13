#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename T>
class Iterator
{
public:
	Iterator();
	Iterator(const Iterator& copy);
	~Iterator();
	Iterator& operator =(const Iterator& rhs);
	Iterator operator++();
	Iterator operator++(int input);
	Iterator operator--();
	Iterator operator--(int input);

private:
	Node* m_node;

};

#include "Iterator.inc"
#endif