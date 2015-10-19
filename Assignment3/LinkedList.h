/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/18/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				LinkedList.h
*
* Overview:
*	This is the header file for the templated LinkedList
*	class. LinkedList is a doubly linked list storing the
*	locations of the first and last node in the list.
*
* Input:
*	
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include "Iterator.h"

template <typename T>
class LinkedList
{
public:
	//default constructor for Linked List
	LinkedList();

	//single argument constructor for Linked List
	LinkedList(const LinkedList& copy);

	//Linked list destructor
	~LinkedList();

	//
	LinkedList& operator = (const LinkedList& rhs);
	bool isEmpty();
	const Node<T>& First();
	const Node<T>& Last();
	void Prepend(T* input);
	void Append(T* input);
	void Purge();
	Node<T>& Extract(T input);
	void insertAfter(T data, T* inNode);
	Iterator<T> Begin();
	Iterator<T> End();

private:
	Node<T>* m_tail;
	Node<T>* m_head;
};

#include "LinkedList.inc"

#endif