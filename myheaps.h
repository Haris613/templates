#ifndef _MYHEAPS_H_
#define _MYHEAPS_H_

#include <cstddef>

#define father(x) ( (x+1)/2 -1 )
#define leftSon(x) ( 2*(x+1) -1 )
#define rightSon(x) ( (2*(x+1)) )

template<class T>
class myHeap
{
public:
	myHeap():m_array(NULL), m_size(0), m_capacity(0){}
	myHeap(const T * array, const size_t arraySize):m_size(arraySize),m_capacity(arraySize){
		m_array = new T[m_capacity];
		for (size_t i = 0; i < arraySize; ++i)
			m_array[i] = array[i];
	}
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
	virtual void bubbleDown(const size_t index = 0) = 0;
	size_t size(){ return m_size; }
	T & getTop(){ return m_array[0]; }
protected:
	void swap(const size_t index1, const size_t index2){
			T tmp = m_array[index1];
			m_array[index1] = m_array[index2];
			m_array[index2] = tmp;
	}
	void prepareExtraction(){
		swap(0,--m_size);
	}
	T & getExtracted(){ return m_array[m_size]; }
	T & at(const size_t index){ return m_array[index]; }
	virtual void buildHeap() = 0;
	T * m_array;
	size_t m_size;
	size_t m_capacity;
};

template<class T>
class myMinHeap: public myHeap<T>
{
public:
	myMinHeap():myHeap<T>(){}
	myMinHeap(const T * array, const size_t arraySize):myHeap<T>(array,arraySize){
		buildHeap();
	}
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
	T extractMin(){
		myHeap<T>::prepareExtraction();
		bubbleDown();
		return myHeap<T>::getExtracted();
	}
	void bubbleDown(const size_t index = 0) override{
		uint currIndex = index;
		while(leftSon(currIndex) < myHeap<T>::size()){
			if( !( myHeap<T>::at(leftSon(currIndex)) < myHeap<T>::at(currIndex) ) &&
				(rightSon(currIndex) >= myHeap<T>::size() || !( myHeap<T>::at(rightSon(currIndex)) < myHeap<T>::at(currIndex) )) )
				break;
			else if( rightSon(currIndex)>=myHeap<T>::size() || !( myHeap<T>::at(rightSon(currIndex)) < myHeap<T>::at(leftSon(currIndex)) ) ){
				myHeap<T>::swap(currIndex,leftSon(currIndex));
				currIndex = leftSon(currIndex);
			}
			else{
				myHeap<T>::swap(currIndex,rightSon(currIndex));
				currIndex = rightSon(currIndex);
			}
		}
	}
protected:
	void buildHeap() override{
		for (size_t i = myHeap<T>::size()/2+1; i>0 ; --i)
			bubbleDown(i-1);
	}
};

template<class T>
class myMaxHeap: public myHeap<T>
{
public:
	myMaxHeap():myHeap<T>(){}
	myMaxHeap(const T * array, const size_t arraySize){
		buildHeap();
	}
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
	T extractMax(){
		myHeap<T>::prepareExtraction();
		bubbleDown();
		return myHeap<T>::getExtracted();
	}
	void bubbleDown(const size_t index = 0) override{
		uint currIndex = index;
		while(leftSon(currIndex) < myHeap<T>::size()){
			if( !( myHeap<T>::at(currIndex) < myHeap<T>::at(leftSon(currIndex)) ) &&
				(rightSon(currIndex) >= size || !( myHeap<T>::at(currIndex) < myHeap<T>::at(rightSon(currIndex)) )) )
				break;
			else if( rightSon(currIndex)>=myHeap<T>::size() || !( myHeap<T>::at(leftSon(currIndex)) < myHeap<T>::at(rightSon(currIndex)) ) ){
				myHeap<T>::swap(currIndex,leftSon(currIndex));
				currIndex = leftSon(currIndex);
			}
			else{
				myHeap<T>::swap(currIndex,rightSon(currIndex));
				currIndex = rightSon(currIndex);
			}
		}
	}
protected:
	void buildHeap() override{
		for (size_t i = myHeap<T>::size()/2+1; i>0 ; --i)
			bubbleDown(i-1);
	}
};

#endif