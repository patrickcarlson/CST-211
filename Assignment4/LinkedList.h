/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/24/2015
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

/************************************************************************
* Class: LinkedList.h
*
* Constructors:
*		LinkedList()
*				Default constructor assigns member variables m_head and 
*				m_tail to nullptr.
*		LinkedList(const LinkedList<T>& copy)
*				Copy constructor 
*		~LinkedList()
*				Destructor
*
* Mutators:
*
*		void Prepend(T* input)
*				Allows node to be prepended to list.
*		void Append(T* input)
*				Allows node to be appended to list.
*		void Purge()
*				Removes all nodes in linked list.
*		Node<T>& Extract(T input)
*				Removes first item on list holding data of same value
*				as input.
*		void insertAfter(T data, T* inNode)
*				Inserts node after node holding entered data value.
*		
*
* Methods:
*		bool isEmpty()
*				returns bool if no nodes are present in list.
*		const Node<T>& First()
*				returns member variable m_head
*		const Node<T>& Last()
*				returns member variable m_tail
*		const Iterator<T> Begin()
*				returns iterator to m_head node
*		const Iterator<T> End()
*				returns iterator to m_tail node
*				
*************************************************************************/
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

	//Linked list assignment operator overload
	LinkedList& operator = (const LinkedList& rhs);
	
	// bool representing presence of data in linked list
	bool isEmpty();

	// Inspector returns Head node.
	const Node<T>& First();

	// Inspector returns Tail node.
	const Node<T>& Last();

	// Prepend node to list
	void Prepend(T* input);

	// Append node to list
	void Append(T* input);

	// Remove all nodes from the list
	void Purge();
	
	// Remove node containing associated data
	Node<T>& Extract(T input);

	// Remove last node in Linked List
	T popBack();

	// insert node after node containing specified data
	void insertAfter(T data, T* inNode);

	// insert node before node containing specified data
	void insertBefore(T data, T* inNode);

	// Iterator of Head node.
	const Iterator<T> Begin();

	// Iterator of Node after tail node.
	const Iterator<T> End();

private:
	Node<T>* m_tail; // Last node in list
	Node<T>* m_head; // First node in list
};

#include "LinkedList.inc"

#endif