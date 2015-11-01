#ifndef NORMALQUEUE_H
#define NORMALQUEUE_H

#include "LinkedList.h"
#include "Exception.h"

template <typename T>
class NormalQueue
{
public:
	NormalQueue(int size);

	void Enqueue(T input);

	T Dequeue();

	T& Front();

	int size();

	bool isEmpty();

	bool isFull();

	/*Enqueue - Puts the data item at the end(tail) of the queue.

	Dequeue - Removes and returns the data item at the front of the queue.

	Front - Returns a reference to the data at the front of the queue.This will allow the consumer to modify the element at the front of the queue.

	Size – Returns the number of items currently in the queue.

	isEmpty - Returns true if the stack is empty.

	isFull - Returns true if the queue is full.*/

private:
	int m_capacity;
	int m_size;
	LinkedList<T> m_queue;
};


#include "NormalQueue.inc"


#endif