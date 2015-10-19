/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/18/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				Node.inc
*
* Overview:
*	This is the .inc file for the Node class. The node
*	class is utilized to store position and data information
*	for a doubley linked list. This file holds the 
*	member function definitions.
*
* Input:
*	On construction a Node takes data to store.
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the Node.
************************************************************/

template <typename T>
Node<T>::Node(T& data)
	:m_data(data)
{
	m_next = nullptr;
	m_prev = nullptr;
}


template <typename T>
T& Node<T>::getData()
{
	return m_data;
}

template <typename T>
void Node<T>::setData(T newData)
{
	m_data = newData;
}

template <typename T>
Node<T>* Node<T>::getNext()
{
	return m_next;
}

template <typename T>
Node<T>* Node<T>::getPrev()
{
	return m_prev;
}

template <typename T>
void Node<T>::setNext(Node<T>* input)
{
	m_next = input;
}

template <typename T>
void Node<T>::setPrev(Node<T>* input)
{
	m_prev = input;
}