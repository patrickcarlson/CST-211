
template <typename T>
NormalQueue<T>::NormalQueue(int size)
	:m_capacity(size)
{
	m_size = 0;
}

template <typename T>
void NormalQueue<T>::Enqueue(T input)
{
	if (!isFull())
	{
		m_queue.Append(input);
		m_size++;
	}
}

template <typename T>
T NormalQueue<T>::Dequeue()
{
	// Build pop_front member function for linkedlist.
}

template <typename T>
T& NormalQueue<T>::Front()
{

}

template <typename T>
int NormalQueue<T>::size()
{
	return m_size;
}

template <typename T>
bool NormalQueue<T>::isEmpty()
{
	return m_queue.isEmpty();
}

template <typename T>
bool NormalQueue<T>::isFull()
{
	if (m_size == m_capacity)
		return true;
	else
		return false;
}