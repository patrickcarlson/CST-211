/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/31/2015
* Last Modification Date:	11/1/2015
* Assignment Number:    CST 211 Assignment 5
* Filename:				CircularQueue.h
*
* Overview:
*	This is the header file for the templated CircularQueue
*	class. CircularQueue is a queue utilizing the custom
*	linked list class found in LinkedList.h.
*
* Input:
*
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/
#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Array.h"
#include "Exception.h"

/************************************************************************
* Class: CircularQueue.h
*
* Constructors:
*		CircularQueue(int size)
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
*				that value to be modified.
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
class CircularQueue
{
public:
	//Single argument constructor
	CircularQueue(int size);

	// Adds new value to back of queue.
	void Enqueue(T input);

	// Removes value at front of queue, returns that value
	T Dequeue();

	// Returns reference to value stored at front of queue.
	T& Front();

	// Returns number of values stored in queue
	int size();

	// Returns true if empty
	bool isEmpty();
	
	// Returns true if full.
	bool isFull();	

private:
	int m_size;				// Current size of queue
	int m_capacity;			// Total storage capacity of queue
	Array<T> m_queue;		// Array used to store values in queue
	int m_first;			// Index of first value in queue
	int m_last;				// Index of last value in queue

};


#include "CircularQueue.inc"


#endif