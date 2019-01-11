/*
* maxheap.h
* 
* Specifications for MaxHeap class
*
* @author Juan Arias
*
*/

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include "heap.h"

/*
* A MaxHeap is an implementation of the Heap interface that prioritizes
* the maximum value.
*/
template <class T>
class MaxHeap: public Heap<T> {

public:

	/*
	* Constructs empty heap
	*/
	MaxHeap();

	/*
	* Constructs heap from given array
	* @param arr The array to construct heap from
	* @param size The size of arr
	*/
	MaxHeap(const T arr[], int size);

	/*
	* Copy constructor overload
	* @param other The other heap to copy
	*/
	MaxHeap(const Heap<T>& other);

	/*
	* Destroys heap and deallocates all dynamic memory
	*/
	virtual ~MaxHeap();

	/*
	* Assignment operator overload
	* @param other The other heap to copy
	* @return this heap by reference
	*/
	Heap<T>& operator=(const Heap<T>& other) override;

	/*
	* Remove the peek item in the heap
	*/
	void remove() override;

	/*
	* Add item to the heap
	* @param item The item to add to the heap
	*/
	void add(const T& item) override;

	/*
	* Remove the peek item in the heap
	*/
	bool contains(const T& item) override;

	/*
	* Static method
	* Heap sorts the given array
	* @param arr The array to sort
	* @param size The size of arr
	*/
	static void maxHeapSort(T arr[], int size);

private:

	/*
	* Helper function for array constructor
	*/
	void create();

	/*
	* Bubbles node up heap until in correct position
	* @param curr The current node in the heap
	*/
	void bubbleUp(Node curr);

	/*
	* Trickles nodes down heap until in correct position
	* @param curr The current node in the heap
	*/
	void rebuild(Node curr);

	/*
	* Static method
	* Trickles nodes down given heap array until in correct position
	* @param arr The heap array to rebuild
	* @param size The size of arr
	* @param curr The current node in the heap
	*/
	static void rebuild(T arr[], int size, Node curr);

};
#include "maxheap.cpp"
#endif // MAXHEAP_H
