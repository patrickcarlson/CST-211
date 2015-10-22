/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/18/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				Node.h
*
* Overview:
*	This is the header file for the Node class. The node
*	class is utilized to store position and data information
*	for a doubley linked list.
*
* Input:
*	On construction a Node takes data to store.
*	
* Output:
*	Accessor functions allow manipulation of data stored
*	within the Node.
************************************************************/

#ifndef NODE_H
#define NODE_H

/************************************************************************
* Class: Node.h
*
* Constructors:
*		Node(T& data)
*				Single argument constructor.
*
* Mutators:
*		
*		void setData(T newData)
*				This mutator allows manipulation of the m_data member
*				variable.
*		void setNext(Node<T>* input)
*				This mutator allows manipulation of the m_next member
*				variable.
*		void setPrev(Node<T>* input)
*				This mutator allows manipulation of the m_prev member
*				variable.
*
* Methods:
*		T& getData()
*				Inspector returns value of m_data member variable.
*		Node<T>* getNext()
*				Inspector returns value of m_next member variable.
*		Node<T>* getPrev()
*				Inspector returns value of m_prev member variable.
*************************************************************************/

template <typename T>
class Node
{
public:

	// single argument constructor
	Node(T& data);

	// Inspector returns data stored in node
	T& getData();

	// Mutate data stored in Node.
	void setData(const T newData);
	
	// Inpector returns pointer to next node in list
	Node* getNext();

	// Inspector returns pointer to prev node in list
	Node* getPrev();

	// Mutator to set next pointer
	void setNext(Node<T>* input);

	// Mutator to set prev pointer
	void setPrev(Node<T>* input);
	
private:
	T m_data;			// data to be store in node
	Node* m_next;		// Pointer to next node in list
	Node* m_prev;		// Pointer to prev node in list


};

#include "Node.inc"

#endif