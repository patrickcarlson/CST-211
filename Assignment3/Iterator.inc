/*
template <typename T>
Iterator<T>::Iterator()
{

}
*/
template <typename T>
Iterator<T>::Iterator(Node<T> *P)
{
	m_node = P;
}

/*
template <typename T>
Iterator<T>::~Iterator() {

}

template <typename T>
Iterator& Iterator<T>::operator =(const Iterator& rhs)
{

}

*/

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
		m_node = m_node->getNext();

		return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++(int input)
{
	Iterator<T> temp(m_node);

	temp = *this;

	m_node = m_node->getNext();

	return temp;


}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	m_node = m_node->getPrev();
}

template <typename T>
Iterator<T>& Iterator<T>::operator--(int input)
{
	Iterator<T> tempIt;

	tempIt = *this;

	m_node = m_node->getPrev();

	return tempIt;
}

template <typename T>
T& Iterator<T>::operator*()
{
	T something = m_node->getData();
	
	return something;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& other)
{
	return m_node == other.m_node;
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& other)
{
	return m_node != other.m_node;
}

template <typename T>
Node<T>& Iterator<T>::getItNode()
{
	return *m_node;
}