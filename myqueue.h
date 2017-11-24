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
	myQueue(): m_first(NULL), m_last(NULL){}
	~myQueue(){ delete m_last; }
private:
	QElement * m_first;
	QElement * m_last;
};

#endif