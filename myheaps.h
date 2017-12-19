#ifndef _MYHEAPS_H_
#define _MYHEAPS_H_

#include <cstddef>

template<class T>
class myHeap
{
public:
	myHeap():m_array(NULL), m_size(0), m_capacity(0){}
	~myHeap(){ delete[] m_array; }
protected:
	T * m_array;
	size_t m_size;
	size_t m_capacity;
};

template<class T>
class myMinHeap: public myHeap<T>
{
public:
	myMinHeap():myHeap(){}
};

template<class T>
class myMaxHeap: public myHeap<T>
{
public:
	myMaxHeap():myHeap(){}
};

#endif