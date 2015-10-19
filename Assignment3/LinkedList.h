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
	LinkedList();
	LinkedList(const LinkedList& copy);
	~LinkedList();
	LinkedList& operator = (const LinkedList& rhs);
	bool isEmpty();
	const Node& First();
	const Node& Last();
	void Prepend(T* input);
	void Append(T* input);
	void Purge();
	Node& Extract(T input);
	void insertAfter(T data, T* inNode);
	Iterator Begin();
	Iterator End();

private:
	Node* m_tail;
	Node* m_head;
};

#include "LinkedList.inc"

#endif