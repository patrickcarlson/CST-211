/***********************************************************
* Author:				Patrick Carlson
* Date Created:			11/1/2015
* Last Modification Date:	11/1/2015
* Assignment Number:    CST 211 Assignment 5
* Filename:				NormalQueue.h
*
* Overview:
*	This is the header file for the templated NormalQueue
*	class. NormalQueue is a queue(non circular) utilizing the 
*	custom array class found in Array.h.
*
* Input:
*
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/

#ifndef NORMALQUEUE_H
#define NORMALQUEUE_H

#include "LinkedList.h"
#include "Exception.h"

/************************************************************************
* Class: CircularQueue.h
*
* Constructors:
*		NormalQueue(int size)
*				Single argument constructor, sets member variable
*				m_capacity to argument value stored in size.
*
* Mutators:
*		void Enqueue(T input)
*				Adds another value, input, to the queue, unless queue is
*				already full.
*		T Dequeue()
*				Removes first value in queue, and returns that value
*		T& Front()
*				Returns a reference to the first value in queue, which
*				allows that value to be modified.
*
* Methods:
*		int size()
*				Returns the current size of the queue, stored in the
*				m_size member variable.
*		bool isEmpty()
*				Returns true if no values are stored in the queue.
*		bool isFull()
*				Returns true if queue is full.
*
************************************************************************/
template <typename T>
class NormalQueue
{
public:
	NormalQueue(int size);

	void Enqueue(T* input);

	T Dequeue();

	T& Front();

	int size();

	bool isEmpty();

	bool isFull();

private:
	int m_capacity;
	int m_size;
	LinkedList<T> m_queue;
};


#include "NormalQueue.inc"


#endif