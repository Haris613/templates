#ifndef _SORTS_H_
#define _SORTS_H_

template <typename T>
void swap(T & x, T & y){
	T tmp = x;
	x = y;
	y = tmp;
}

//------------------------------------HEAPSORT------------------------------------

#define father(x) ( (x+1)/2 -1 )
#define leftSon(x) ( 2*(x+1) -1 )
#define rightSon(x) ( (2*(x+1)) )

template <typename T>
void bubbleDown(T * array, size_t size, const size_t index = 0){
	size_t currIndex = index;
	while(leftSon(currIndex) < size){
		if( !( array[currIndex] < array[leftSon(currIndex)] ) &&
			(rightSon(currIndex) >= size || !( array[currIndex] < array[rightSon(currIndex)] )) )
			break;
		else if( rightSon(currIndex)>=size || !( array[leftSon(currIndex)] < array[rightSon(currIndex)] ) ){
			swap(array[currIndex],array[leftSon(currIndex)]);
			currIndex = leftSon(currIndex);
		}
		else{
			swap(array[currIndex],array[rightSon(currIndex)]);
			currIndex = rightSon(currIndex);
		}
	}
}

template <typename T>
void builMaxHeap(T * array, size_t size){
	for (size_t i = size/2+1; i>0; --i)
		bubbleDown(array,size,i-1);
}

template <typename T>
void extractMaxToEnd(T * array, size_t size){
	swap(array[0],array[size]);
	bubbleDown(array,size);
}

template <typename T>
void heapsort(T * array, size_t size){
	if(size == 0)
		return;
	builMaxHeap(array,size);
	for (size_t i = size; i > 0; --i)
		extractMaxToEnd(array,i-1);
}

//------------------------------------BUBBLESORT------------------------------------

template <typename T>
void bubblesort(T * array, size_t size){
	bool done;
	for (size_t i = 0; i < size-1; ++i)
	{
		done = true;
		for (size_t j = 0; j < size-1-i; ++j)
		{
			if(array[j+1] < array[j]){
				swap(array[j+1],array[j]);
				done = false;
			}
		}

		if(done)
			break;
	}
}

//------------------------------------SELECTSORT------------------------------------

template <typename T>
void selectsort(T * array, size_t size){
	for (size_t i = 0; i < size-1; ++i)
	{
		size_t min = i;
		for (size_t j = i + 1; j < size; ++j){
			if(array[j] < array[min])
				min = j;
		}
		if(min!=i)
			swap(array[i],array[min]);
	}
}

//------------------------------------INSERTSORT------------------------------------

template <typename T>
void insertsort(T * array, size_t size){
	for (size_t i = 0; i < size-1; ++i)
	{
		for (size_t j = i+1; j > 0; --j)
		{
			if(array[j] < array[j-1])
				swap(array[j],array[j-1]);
		}
	}
}

#endif