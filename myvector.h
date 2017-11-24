#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_

#include <cstddef>

using namespace std;

template <class T>
class myVector
{
	typedef T* MViterator;
public:
	myVector():m_size(0), m_capacity(1){}
	~myVector(){
		delete m_array;
	}
	MViterator begin(){ return m_array; }
	MViterator end(){ return m_array+m_size; }//todo maybe not right
	size_t size(){ return m_size; }
	size_t capacity(){ return m_capacity; }
	bool empty(){ return m_size == 0; }
	T & operator[](size_t n){
		return m_array[n];
	}
private:
	T * m_array;
	size_t m_size;
	size_t m_capacity;
};


#endif