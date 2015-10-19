/***********************************************************
* Author:				Patrick Carlson
* Date Created:			10/13/2015
* Last Modification Date:	10/18/2015
* Assignment Number:    CST 211 Assignment 3
* Filename:				LinkedList.inc
*
* Overview:
*	This is the inc file for the templated LinkedList
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

template <typename T>
LinkedList<T>::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;

	
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy)
{
	if ( copy.m_head == nullptr)
	{
		m_head = nullptr;
		m_tail = nullptr;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* delNode = m_head;

	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->getNext();
		delete delNode;
		delNode = nextNode;
	}

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList& rhs)
{	
	Node<T>* delNode = m_head;

	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->getNext();
		delete delNode;
		delNode = nextNode;
	}

	if (rhs.m_head == nullptr)
	{
		m_head = nullptr;
		m_tail = nullptr;

		return *this;
	}

	Node<T>* curNode = rhs.m_head;

	Node<T>* nextNode;

	while (curNode != nullptr)
	{
			
		this->Append(&curNode->getData());

		nextNode = curNode->getNext();

		curNode = nextNode;

	}

}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (m_head == nullptr)
		return true;
	else
		return false;
}

template <typename T>
const Node<T>& LinkedList<T>::First()
{
	return m_head;
}

template <typename T>
const Node<T>& LinkedList<T>::Last()
{
	return m_tail;
}

template <typename T>
void LinkedList<T>::Prepend(T* input)
{
	Node<T>* newNode = new Node<T>(*input);
	Node<T>* oldNode = m_head;
	if (!oldNode)
	{
		m_tail = newNode;
		m_head = newNode;
	}

	else
	{
		m_head = newNode;
		oldNode->setPrev(newNode);
		newNode->setNext(oldNode);
	}
	m_head = newNode;
}

template <typename T>
void LinkedList<T>::Append(T* input)
{
	
	
	Node<T>* newNode = new Node<T>(*input);
	Node<T>* oldLast = m_tail;

	if (!oldLast)
	{
		m_head = newNode;
		m_tail = newNode;
				
	}
	
	else
	{
		m_tail = newNode;
		oldLast->setNext(newNode);
		newNode->setPrev(oldLast);

	}

}

template <typename T>
void LinkedList<T>::Purge()
{
	Node<T>* delNode = this->m_head;
	
	while (delNode != nullptr)
	{
		Node<T>* nextNode = delNode->getNext();
		delete delNode;
		delNode = nextNode;
	}
}

template <typename T>
Node<T>& LinkedList<T>::Extract(T input)
{
	for (Iterator<T> i = this->Begin(); i != this->End(); ++i)
	{

		if (*i == input)
		{
			Node<T>* curNode = &i.getItNode();
			Node<T>* afterNode = curNode->getNext();			
			Node<T>* beforeNode = curNode->getPrev();
			if (afterNode == nullptr)
			{
				m_tail = curNode;
				beforeNode->setNext(nullptr);

				return *curNode;
			}
			else if (beforeNode == nullptr)
			{
				m_head = curNode;
				afterNode->setPrev(nullptr);

				return *curNode;
			}

			afterNode->setPrev(beforeNode);
			beforeNode->setNext(afterNode);

			return *curNode;
		}
	}
}

template <typename T>
void LinkedList<T>::insertAfter(T data, T* inNode)
{
	for (Iterator i = this->Begin(); i != this->End(); ++i)
	{
		if (*i == data)
		{
			Node<T>* newNode = new Node<T>(inNode);
			newNode->m_prev = curNode;
			curNode->m_next = newNode;

			m_tail = newNode;
		}
	}
}

template <typename T>
Iterator<T> LinkedList<T>::Begin()
{
	Iterator<T> first(m_head);

	return first;
}

template <typename T>
Iterator<T> LinkedList<T>::End()
{
	Iterator<T> last(m_tail->getNext());

	return last;
}

