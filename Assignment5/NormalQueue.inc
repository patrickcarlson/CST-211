/***********************************************************
* Author:				Patrick Carlson
* Date Created:			11/1/2015
* Last Modification Date:	11/1/2015
* Assignment Number:    CST 211 Assignment 5
* Filename:				NormalQueue.inc
*
* Overview:
*	This is the .inc file for the templated NormalQueue
*	class. NormalQueue is a queue utilizing the custom
*	linked list class found in LinkedList.h.
*
* Input:
*
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/

/**************************************************************
*	  Purpose:   Single argument constructor for NormalQueue.
*
*         Entry:	int value for size of queue
*
*          Exit:	Assigns m_capacity to size and m_size to 0.
****************************************************************/
template <typename T>
NormalQueue<T>::NormalQueue(int size)
	:m_capacity(size)
{
	m_size = 0;
}

/**************************************************************
*	  Purpose:  Adds value to back of queue
*
*         Entry:	Value to be stored, input
*
*          Exit:
****************************************************************/
template <typename T>
void NormalQueue<T>::Enqueue(T* input)
{
	if (!isFull())
	{
		m_queue.Append(input);
		m_size++;
	}
	else
		throw Exception("Overflow: Queue is full, no more room");
}

/**************************************************************
*	  Purpose:  Removes and returns value at front of queue
*
*         Entry:
*
*          Exit:	Returns value stored at front of queue
****************************************************************/
template <typename T>
T NormalQueue<T>::Dequeue()
{
	if (!isEmpty())
	{
		m_size--;

		return m_queue.popFront();
	}
	else
		throw Exception("Underflow: Queue is empty, nothing to remove");

}

/**************************************************************
*	  Purpose:  Return reference to value at front of queue
*
*         Entry:
*
*          Exit:	Returns reference to value at front of queue
*					which allows the value to manipulated
****************************************************************/
template <typename T>
T& NormalQueue<T>::Front()
{
	return m_queue.First().getData();
}

/**************************************************************
*	  Purpose:  Current queue size inspector
*
*         Entry:
*
*          Exit:	Returns current number of values stored in
*					queue.
****************************************************************/
template <typename T>
int NormalQueue<T>::size()
{
	return m_size;
}

/**************************************************************
*	  Purpose:  Empty status inspector
*
*         Entry:
*
*          Exit:	Returns bool status of queue emptiness. True
*					if empty.
****************************************************************/
template <typename T>
bool NormalQueue<T>::isEmpty()
{
	return m_queue.isEmpty();
}

/**************************************************************
*	  Purpose:  Full status inspector
*
*         Entry:
*
*          Exit:	Returns bool status of queue fullness. true
*					if full
****************************************************************/
template <typename T>
bool NormalQueue<T>::isFull()
{
	if (m_size == m_capacity)
		return true;
	else
		return false;
}