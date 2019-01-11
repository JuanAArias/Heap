/*
* heap.h
*
* Interface/AbstractBaseClass specs for Heap ADT
*
* @author Juan Arias
*
*/

#ifndef HEAP_H
#define HEAP_H

/*
* A Heap is a binary-tree that is always complete (leaves filled in left to right),
* and either has the maximum value in the root and every node is greater than
* or equal to it's children (max-heap) or the minmum value in the root and every
* node is less than or equal to it's children (minheap).
*/
template <class T>
class Heap {

// Type definition for Nodes in a heap
using Node = int;

public:

	/*
	* Destroys heap and deallocates all dynamic memory
	*/
	virtual ~Heap();

	/*
	* Assignment operator overload
	* @param other The other heap to copy
	* @return this heap by reference
	*/
	virtual Heap<T>& operator=(const Heap<T>& other);

	/*
	* Add item to the heap
	* @param item The item to add to the heap
	*/
	virtual void add(const T& item) = 0;

	/*
	* Remove the peek item in the heap
	*/
	virtual void remove() = 0;

	/*
	* Remove the peek item in the heap
	*/
	virtual bool contains(const T& item) = 0;

	/*
	* Equality operator overload
	* @param other The other heap to compare
	* @return true if equal, else false
	*/
	bool operator==(const Heap<T>& other) const;

	/*
	* Inequality operator overload
	* @param other The other heap to compare
	* @return true if not equal, else false
	*/
	bool operator!=(const Heap<T>& other) const;

	/*
	* Check if heap is empty
	* @return true if empty, else false
	*/
	bool isEmpty() const;

	/*
	* Get the height of the heap
	* @return the height of the heap
	*/
	int getHeight() const;

	/*
	* Get the number of nodes in the heap
	* @return the number of nodes in the heap
	*/
	int getNodes() const;

	/*
	* Get the peek item in the heap
	* @return the peek item in the heap
	*/
	T& peek() const;

	/*
	* Clear the heap
	*/
	void clear();

	/*
	* Display heap sideways
	*/
	void displaySideways();

protected:

	// Pointer for dynamic array
	T * arr;

	// Item count in array and maximum possible size of array
	int itemCount, MAX;

	// Default constant for MAX & empty constant
	static const int DEFAULT = 100, EMPTY = 0;

	// Constant for indexing root
	static const Node ROOT = 0;

	/*
	* Constructs empty heap
	*/
	Heap();

	/*
	* Constructs heap from given array
	* @param arr The array to construct heap from
	* @param size The size of arr
	*/
	Heap(const T arr[], int size);

	/*
	* Default initialization
	*/
	void initialize();

	/*
	* Swaps the items in the given indexes
	* @param node1 The index of the first node
	* @param node2 The index of the second node
	*/
	void swap(Node node1, Node node2);

	/*
	* Static method
	* Checks if the given node is a leaf
	* @param curr The current node
	* @return true if leaf, else false
	*/
	static bool isLeaf(Node curr, int itemCount);

	/*
	* Static method
	* Gets the larger of the given node's children
	* @param curr The current node
	* @return the larger child
	*/
	static Node largerChild(T arr[], int itemCount, Node curr);

	/*
	* Static method
	* Gets the parent of the given node
	* @param curr The current node
	* @return the parent of curr
	*/
	static Node parent(Node curr);

	/*
	* Static method
	* Swaps the items in the given indexes
	* @param node1 The index of the first node
	* @param node2 The index of the second node
	*/
	static void swap(T arr[], Node node1, Node node2);

private:

	/*
	* Copies elements of given array and forms heap
	* @param arr The given array to copy
	*/
	void copyArray(const T arr[]);

	/*
	* Static method
	* Checks if the given node has right child
	* @param curr The current node
	* @return true if has right child, else false
	*/
	static bool hasRight(Node curr, int itemCount);

	/*
	* Static method
	* Gets the left child of the given node
	* @param curr The current node
	* @return the left child of curr
	*/
	static Node left(Node curr);

	/*
	* Static method
	* Gets the right child of the given node
	* @param curr The current node
	* @return the right child of curr
	*/
	static Node right(Node curr);

	/*
	* Helper function for display sideways
	* @param curr The current node
	* @param level the current level of the heap
	*/
	void sideways(Node curr, int level);

};

#include "heap.cpp"
#endif // HEAP_H
