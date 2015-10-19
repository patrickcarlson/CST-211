#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
	Node();
	Node(T& data);
	Node(const Node& copy);
	~Node();
	Node& operator = (const Node& rhs);
	T getData();
	setData(T newData);
	/*
	* Mutators/Accessors
	*/
private:
	T m_data;
	Node* m_next;
	Node* m_prev;


};

#include "Node.inc"

#endif