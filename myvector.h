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
private:
	T * m_array;
	size_t m_size;
	size_t m_capacity;
};


#endif