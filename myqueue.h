#ifndef _MYQUEUE_H_
#define _MYQUEUE_H_

#include <cstddef>

using namespace std;

template <class T>
class myQueue
{
	struct QElement{
		QElement(T value):m_value(value), m_next(NULL), m_previous(NULL){}
		QElement(T value, QElement * next):m_value(value), m_next(next), m_previous(NULL){}
		~QElement(){ delete m_next; }
		T m_value;
		QElement * m_next;
		QElement * m_previous;
	};
public:
	myQueue(): m_first(NULL), m_last(NULL), m_size(0){}
	~myQueue(){ delete m_last; }
	void push(const T & newElement){
		if(m_first == NULL)
			m_first = m_last = new QElement(newElement);
		else{
			m_last->m_previous = new QElement(newElement,m_last);
			m_last = m_last->m_previous;
		}
		++m_size;
	}
	void pop(){
		if(m_first == NULL)
			return;
		QElement * tmp = m_first->m_previous;
		delete m_first;
		m_first = tmp;
		if(m_first != NULL)
			m_first->m_next = NULL;
		else
			m_last = NULL;
		--m_size;
	}
	T & front(){ return m_first->m_value; }
	T & back(){ return m_last->m_value; }
	T & first(){ return m_first->m_value; }
	T & last(){ return m_last->m_value; }
	bool empty(){ return m_first == NULL; }
	size_t size(){ return m_size; }
private:
	QElement * m_first;
	QElement * m_last;
	size_t m_size;
};

#endif