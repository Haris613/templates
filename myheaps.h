#ifndef _MYHEAPS_H_
#define _MYHEAPS_H_

#include <cstddef>

#define father(x) ( (x+1)/2 -1 )
#define leftSon(x) ( 2*(x+1) -1 )
#define RightSon(x) ( (2*x)+1 )

template<class T>
class myHeap
{
public:
	myHeap():m_array(NULL), m_size(0), m_capacity(0){}
	~myHeap(){ delete[] m_array; }
	bool resize(const size_t newCapacity){
		if(newCapacity<m_size)
			return false;

		T * tmp = new T[newCapacity];

		if(tmp == NULL)
			return false;

		for (size_t i = 0; i < m_size; ++i)
			tmp[i] = m_array[i];
		delete m_array;

		m_array = tmp;
		m_capacity = newCapacity;

		return true;
	}
	virtual void insert(const T & newElement){
		if(m_size >= m_capacity)
			resize( (m_capacity+1)*2 -1 );
		m_array[m_size] = newElement;
		++m_size;
	}
	virtual void bubbleUp(const size_t index) = 0;
	size_t size(){ return m_size; }
	T & getTop(){ return m_array[0]; }
protected:
	void swap(const size_t index1, const size_t index2){
			T tmp = m_array[index1];
			m_array[index1] = m_array[index2];
			m_array[index2] = tmp;
	}
	T & at(const size_t index){ return m_array[index]; }
	T * m_array;
	size_t m_size;
	size_t m_capacity;
};

template<class T>
class myMinHeap: public myHeap<T>
{
public:
	myMinHeap():myHeap<T>(){}
	void insert(const T & newElement) override{
		myHeap<T>::insert(newElement);
		bubbleUp(myHeap<T>::size()-1);
	}
	void bubbleUp(size_t index) override{
		while(index!=0){
			if( ! (myHeap<T>::at(index) < myHeap<T>::at(father(index))) )
				break;
			myHeap<T>::swap(index,father(index));

			index = father(index);
		}
	}
	T & getMin(){ return myHeap<T>::getTop(); }
};

template<class T>
class myMaxHeap: public myHeap<T>
{
public:
	myMaxHeap():myHeap<T>(){}
	void insert(const T & newElement) override{
		myHeap<T>::insert(newElement);
		bubbleUp(myHeap<T>::size()-1);
	}
	void bubbleUp(size_t index) override{
		while(index!=0){
			if( ! (myHeap<T>::at(father(index)) < myHeap<T>::at(index)) )
				break;
			myHeap<T>::swap(index,father(index));

			index = father(index);
		}
	}
	T & getMax(){ return myHeap<T>::getTop(); }
};

#endif