#ifndef _MYVECTOR_H_
#define _MYVECTOR_H_

#include <cstddef>

using namespace std;

template <class T>
class myVector
{
public:
	typedef T* iterator;
	myVector():m_size(0), m_capacity(1){}
	~myVector(){
		delete[] m_array;
	}
	iterator begin(){ return m_array; }
	iterator end(){ return m_array+m_size; }
	size_t size(){ return m_size; }
	size_t capacity(){ return m_capacity; }
	bool empty(){ return m_size == 0; }
	T & operator[](size_t n){
		return m_array[n];
	}
	bool resize(const size_t newCapacity){
		if(newCapacity<m_size)
			return false;
		
		T * tmp = new T[newCapacity];
		
		if(tmp == NULL)
			return false;

		for (size_t i = 0; i < m_size; ++i)
			tmp[i] = m_array[i];
		delete[] m_array;

		m_array = tmp;
		m_capacity = newCapacity;

		return true;
	}
	void shrink_to_fit(){
		T * tmp = new T[m_size];

		for (size_t i = 0; i < m_size; ++i)
			tmp[i] = m_array[i];
		delete[] m_array;

		m_array = tmp;
		m_capacity = m_size;
	}
	void clear(){
		delete[] m_array;
		m_array = new T[m_capacity];
		m_size = 0;
	}
	void push_back(const T & newElement){
		if(m_size+1 >= m_capacity)
			resize(m_capacity*2);
		m_array[m_size++] = newElement;
	}
	void pop_back(){
		if(m_size == 0)
			return;
		--m_size;
	}
	void insert(const iterator position, const T & newElement){
		if(position-m_array >= 0)
			this->insert((size_t)(position-m_array),newElement);
	}
	void erase(const iterator position){
		if(position-m_array >= 0)
			this->erase((size_t)(position-m_array));
	}
	void insert(const size_t n, const T & newElement){
		if(m_size+1 >= m_capacity)
			m_capacity*=2;

		T * tmp = new T[m_capacity];

		for (size_t i = 0; i < n; ++i)
			tmp[i] = m_array[i];
		tmp[n] = newElement;
		for (size_t i = n; i < m_size; ++i)
			tmp[i+1] = m_array[i];
		delete[] m_array;
		m_array = tmp;
		++m_size;
	}
	void erase(const size_t n){
		if(n>=m_size)
			return;
		T * tmp = new T[m_capacity];

		for (size_t i = 0; i < n; ++i)
			tmp[i] = m_array[i];
		for (size_t i = n+1; i < m_size; ++i)
			tmp[i-1] = m_array[i];
		delete[] m_array;
		m_array = tmp;
		--m_size;
	}
	iterator find(const T & value){
		for (iterator it = this->begin(); it != this->end(); ++it)
			if(*it == value)
				return it;
		return this->end();
	}

private:
	T * m_array;
	size_t m_size;
	size_t m_capacity;
};


#endif