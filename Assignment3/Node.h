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