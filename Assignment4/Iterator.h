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

/************************************************************************
* Class: Iterator.h
*
* Constructors:
*		Iterator(Node<T> *P)
*				Single argument constructor.
*
* Methods:
*		Iterator& operator++()
*				Post increment operator overload
*		Iterator& operator++(int input)
*				Pre increment operator overload	
*		Iterator& operator--()
*				Post decrement operator overload
*		Iterator& operator--(int input)
*				Pre decrement operator overload	
*		T& operator*()
*				Dereference operator overload
*		bool operator==(const Iterator& other)
*				Equality operator overload
*		bool operator!=(const Iterator& other)
*				Inequality operator overload
*		Node<T>& getItNode()
*				Inspector for iterated node.
*
*************************************************************************/
template <typename T>
class Iterator
{
public:
	// Single argument constructor
	Iterator(Node<T> *P);

	// Post increment operator overload
	Iterator& operator++();

	// pre increment operator overload
	Iterator& operator++(int input);

	// Post decrement operator overload
	Iterator& operator--();

	// Pre decrement operator overload
	Iterator& operator--(int input);

	// Dereference operator overload
	T& operator*();

	// Equality operator overload
	bool operator==(const Iterator& other);

	// Inequality operator overload
	bool operator!=(const Iterator& other);

	// Inspector for member variable m_node
	Node<T>& getItNode();

private:
	Node<T>* m_node; // Node iterator is currently inspecting

};


#include "Iterator.inc"
#endif