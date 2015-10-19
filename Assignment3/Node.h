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

template <typename T>
class Node
{
public:
	Node(T& data);
	T& getData();
	void setData(const T newData);
	Node* getNext();
	Node* getPrev();
	void setNext(Node<T>* input);
	void setPrev(Node<T>* input);
	
private:
	T m_data;
	Node* m_next;
	Node* m_prev;


};

#include "Node.inc"

#endif