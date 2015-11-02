/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/31/2015
* Last Modification Date:	11/1/2015
* Assignment Number:    CST 211 Assignment 5
* Filename:				CircularQueue.inc
*
* Overview:
*	This is the .inc file for the templated CircularQueue
*	class. CircularQueue is a queue utilizing the custom
*	array class found in Array.h.
*
* Input:
*
*
* Output:
*	Accessor functions allow manipulation of data stored
*	within the linked list.
************************************************************/

/**************************************************************
*	  Purpose:   Single argument constructor for CircularQueue.
*
*         Entry:	int value for size of queue
*
*          Exit:	Assigns m_capacity to size, m_size to 0 and
*					m_first and m_last to -1.
****************************************************************/
template <typename T>
CircularQueue<T>::CircularQueue(int size)
	:m_capacity(size)

{
	Array<T> m_queue(m_capacity);
	m_first = -1;
	m_last = -1;
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
void CircularQueue<T>::Enqueue(T input)
{
	if (!isFull())
	{
		if (m_last == m_capacity - 1 || m_last == -1)
		{
			m_queue[0] = input;
			m_last = 0;
			if (m_first == -1)
			{
				m_first = 0;
			}
		}
		else
		{
			m_queue[m_last + 1] = input;

			++m_last;
		}

		m_size++;
	}
	else
		throw Exception("Overflow: No more room in queue.");
}

/**************************************************************
*	  Purpose:  Removes and returns value at front of queue
*
*         Entry:
*
*          Exit:	Returns value stored at front of queue
****************************************************************/
template <typename T>
T CircularQueue<T>::Dequeue()
{
	if (!isEmpty())
	{
		T reElement = m_queue[m_first];
		if (m_first == m_last)
		{
			m_first = -1;
			m_last = -1;
		}
		else if (m_first == m_capacity - 1)
		{
			m_first = 0;
		}
		else
			m_first++;

		m_size--;

		return reElement;
	}
	else
	{
		throw Exception("Underflow: Queue is empty, nothing to return");
	}

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
T& CircularQueue<T>::Front()
{
	if (!isEmpty())
	{
		T* reElement = &m_queue[m_first];

		return *reElement;
	}
	else
		throw Exception("Queue is empty, nothing to return");
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
int CircularQueue<T>::size()
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
bool CircularQueue<T>::isEmpty()
{
	if (m_first == -1 && m_last == -1)
		return true;
	else
		return false;
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
bool CircularQueue<T>::isFull()
{
	if (m_first - 1 == m_last || (m_first == 0 && m_last == m_capacity - 1))
		return true;
	else
		return false;
}