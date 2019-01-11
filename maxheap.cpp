#include "maxheap.h"
/*
* maxheap.cpp
*
* Implementations for MaxHeap class
*
* @author Juan Arias
*
*/

  //**************// //**************// //**************//
 //*  PUBLIC:   *// //*  PUBLIC:   *// //*  PUBLIC:   *//
//**************// //**************// //**************//

/*
* Constructs empty heap
*/
template <class T>
MaxHeap<T>::MaxHeap() {}

/*
* Constructs heap from given array
* @param arr The array to construct heap from
* @param size The size of arr
*/
template <class T>
MaxHeap<T>::MaxHeap(const T arr[], int size) :Heap<T>(arr, size) {
	
	this->create();
}

/*
* Copy constructor overload
* @param other The other heap to copy
*/
template <class T>
MaxHeap<T>::MaxHeap(const Heap<T>& other) {
	
	(*this) = other;
}

/*
* Destroys heap and deallocates all dynamic memory
*/
template <class T>
MaxHeap<T>:: ~MaxHeap() {}

/*
* Assignment operator overload
* @param other The other heap to copy
* @return this heap by reference
*/
template <class T>
Heap<T>& MaxHeap<T>::operator=(const Heap<T>& other) {

	this->Heap<T>::operator=(other);

	this->create();

	return (*this);
}

/*
* Add item to the heap
* @param item The item to add to the heap
*/
template <class T>
void MaxHeap<T>::add(const T& item) {

	if (this->arr == nullptr) {

		this->initialize();
	}

	if (this->itemCount < this->MAX) {

		Node curr = this->itemCount;
		this->arr[this->itemCount++] = item;

		this->bubbleUp(curr);
	}
}

/*
* Remove the peek item in the heap
*/
template <class T>
void MaxHeap<T>::remove() {
	
	if (this->itemCount > Heap<T>::EMPTY) {
	
		this->arr[Heap<T>::ROOT] = this->arr[--this->itemCount];

		this->rebuild(Heap<T>::ROOT);
	}
}

/*
* Remove the peek item in the heap
*/
template<class T>
bool MaxHeap<T>::contains(const T& item) {

	bool found(false);

	if (!this->isEmpty() && item <= this->peek()) {

		for (Node curr(Heap<T>::ROOT); curr < this->itemCount && !found; ++curr) {

			found = (this->arr[curr] == item);
		}
	}

	return found;
}

/*
* Static method
* Heap sorts the given array
* @param arr The array to sort
* @param size The size of arr
*/
template<class T>
void MaxHeap<T>::maxHeapSort(T arr[], int size) {
	
	for (Node curr(size / 2); curr >= Heap<T>::ROOT; --curr) {
	
		MaxHeap<T>::rebuild(arr, curr, size);
	}

	Heap<T>::swap(arr, Heap<T>::ROOT, --size);

	while (size > 1) {
	
		MaxHeap<T>::rebuild(arr, Heap<T>::ROOT, size);

		Heap<T>::swap(arr, Heap<T>::ROOT, --size);
	}
}

  //**************// //**************// //**************//
 //*  PRIVATE:  *// //*  PRIVATE:  *// //*  PRIVATE:  *//
//**************// //**************// //**************//

/*
* Helper function for array constructor
*/
template<class T>
void MaxHeap<T>::create() {

	for (Node curr(this->itemCount / 2); curr >= Heap<T>::ROOT; --curr) {
		
		this->rebuild(curr);
	}
}

/*
* Bubbles node up heap until in correct position
* @param curr The current node in the heap
*/
template<class T>
void MaxHeap<T>::bubbleUp(Node curr) {

	while (curr > Heap<T>::ROOT) {

		Node parent = Heap<T>::parent(curr);

		if (this->arr[parent] >= this->arr[curr]) {

			break;
		}

		this->swap(curr, parent);
		curr = parent;
	}
}

/*
* Trickles nodes down heap until in correct position
* @param curr The current node in the heap
*/
template<class T>
void MaxHeap<T>::rebuild(Node curr) {

	MaxHeap<T>::rebuild(this->arr, this->itemCount, curr);
}

/*
* Static method
* Trickles nodes down given heap array until in correct position
* @param arr The heap array to rebuild
* @param size The size of arr
* @param curr The current node in the heap
*/
template<class T>
void MaxHeap<T>::rebuild(T arr[], int size, Node curr) {

	while (!Heap<T>::isLeaf(curr, size)) {

		Node larger = Heap<T>::largerChild(arr, size, curr);

		if (arr[curr] < arr[larger]) {

			Heap<T>::swap(arr, curr, larger);
			curr = larger;

		} else {

			break;
		}
	}
}
