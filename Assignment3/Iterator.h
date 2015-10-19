/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/18/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				Iterator.h
*
* Overview:
*	This is the header file for the Iterator class, which
*	is utilized to iterate through a doubly linked list.
*
* Input:
*	On construction it takes in a pointer to a Node.
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/

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