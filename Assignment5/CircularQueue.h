#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

#include "Array.h"
#include "Exception.h"

template <typename T>
class CircularQueue
{
public:
	CircularQueue(int size);

	void Enqueue(T input);

	T Dequeue();

	T& Front();

	int size(); //Needs to keep track of number values in queue

	bool isEmpty();

	bool isFull();
	
	/*Enqueue - Puts the data item at the end(tail) of the queue.

		Dequeue - Removes and returns the data item at the front of the queue.

		Front - Returns a reference to the data at the front of the queue.This will allow the consumer to modify the element at the front of the queue.

		Size – Returns the number of items currently in the queue.

		isEmpty - Returns true if the stack is empty.

		isFull - Returns true if the queue is full.*/

private:
	int m_size;
	int m_capacity;
	Array<T> m_queue;
	int m_first;
	int m_last;

};


#include "CircularQueue.inc"


#endif