/*
* heap.cpp
*
* Implementations for Heap interface/abstrast base class.
*
* @author Juan Arias
* 
*/

#include <iostream>
#include "heap.h"

// Type definition for Nodes in a heap
using Node = int;

  //**************// //**************// //**************//
 //*  PUBLIC:   *// //*  PUBLIC:   *// //*  PUBLIC:   *//
//**************// //**************// //**************//

/*
* Destroys heap and deallocates all dynamic memory
*/
template <class T>
Heap<T>::~Heap() {

	this->clear();
}

/*
* Assignment operator overload
* @param other The other heap to copy
* @return this heap by reference
*/
template<class T>
Heap<T>& Heap<T>::operator=(const Heap<T>& other) {

	if (this != &other) {

		if (this->MAX != other.MAX) {

			this->clear();
			this->arr = new T[other.MAX];
			this->MAX = other.MAX;
		}

		this->itemCount = other.itemCount;

		this->copyArray(other.arr);
	}

	return (*this);
}

/*
* Equality operator overload
* @param other The other heap to compare
* @return true if equal, else false
*/
template <class T>
bool Heap<T>::operator==(const Heap<T>& other) const {

	bool equal(true);

	if (this != &other || !(this->isEmpty()) && (other.isEmpty()) ) {

		if (this->itemCount != other.itemCount) {
		
			equal = false;

		} else {
	
			for (Node curr(Heap<T>::ROOT); (curr < this->itemCount && equal); ++curr) {

				equal = (this->arr[curr] == other.arr[curr]);
			}
		}
	}

	return equal;
}

/*
* Inequality operator overload
* @param other The other heap to compare
* @return true if not equal, else false
*/
template <class T>
bool Heap<T>::operator!=(const Heap<T>& other) const {
	
	return !((*this) == other);
}

/*
* Check if heap is empty
* @return true if empty, else false
*/
template <class T>
bool Heap<T>::isEmpty() const {
	
	return (this->itemCount == Heap<T>::EMPTY);
}

/*
* Get the height of the heap
* @return the height of the heap
*/
template <class T>
int Heap<T>::getHeight() const {

	Node curr(Heap<T>::ROOT);

	int height(0);

	while (curr < this->itemCount) {
	
		++height;

		curr = Heap<T>::left(curr);
	}

	return height;
}

/*
* Get the number of nodes in the heap
* @return the number of nodes in the heap
*/
template <class T>
int Heap<T>::getNodes() const {
	
	return this->itemCount;
}

/*
* Get the peek item in the heap
* @return the peek item in the heap
*/
template <class T>
T& Heap<T>::peek() const {

	if (this->arr != nullptr && this->itemCount > Heap<T>::EMPTY) {
		
		return this->arr[Heap<T>::ROOT];
	}

	throw Heap<T>::EMPTY;
}

/*
* Clear the heap
*/
template <class T>
void Heap<T>::clear() {

	if (this->arr != nullptr) {
		
		delete[] this->arr;

		this->arr = nullptr;
		this->itemCount = Heap<T>::EMPTY;
	}
}

/*
* Display heap sideways
* @param
*/
template<class T>
void Heap<T>::displaySideways() {

	this->sideways(Heap<T>::ROOT, Heap<T>::EMPTY);
}

  //***************// //***************// //***************//
 //*  PROTECTED: *// //*  PROTECTED: *// //*  PROTECTED: *//
//***************// //***************// //***************//

/*
* Constructs empty heap
*/
template<class T>
Heap<T>::Heap() :arr(nullptr), itemCount(Heap<T>::EMPTY), MAX(Heap<T>::EMPTY) {}

/*
* Constructs heap from given array
* @param arr The array to construct heap from
* @param size The size of arr
*/
template<class T>
Heap<T>::Heap(const T arr[], int size) :arr(new T[size * 2]), itemCount(size), MAX(size * 2) {
	
	this->copyArray(arr);
}

/*
* Default initialization
*/
template<class T>
void Heap<T>::initialize() {

	this->arr = new T[Heap<T>::DEFAULT / 2];
	this->MAX = Heap<T>::DEFAULT;
}

/*
* Swaps the items in the given indexes
* @param node1 The index of the first node
* @param node2 The index of the second node
*/
template<class T>
void Heap<T>::swap(Node node1, Node node2) {

	Heap<T>::swap(this->arr, node1, node2);
}

/*
* Static method
* Checks if the given node is a leaf
* @param curr The current node
* @return true if leaf, else false
*/
template<class T>
bool Heap<T>::isLeaf(Node curr, int itemCount) {

	return (Heap<T>::left(curr) >= itemCount);
}

/*
* Static method
* Gets the larger of the given node's children
* @param curr The current node
* @return the larger child
*/
template<class T>
Node Heap<T>::largerChild(T arr[], int itemCount, Node curr) {

	Node larger = Heap<T>::left(curr);

	if (Heap<T>::hasRight(curr, itemCount)) {

		Node right = Heap<T>::right(curr);

		larger = (arr[right] > arr[larger]) ? right : larger;
	}

	return larger;
}

/*
* Static method
* Gets the parent of the given node
* @param curr The current node
* @return the parent of curr
*/
template<class T>
Node Heap<T>::parent(Node curr) {

	return (curr - 1) / 2;
}

/*
* Static method
* Swaps the items in the given indexes
* @param node1 The index of the first node
* @param node2 The index of the second node
*/
template<class T>
void Heap<T>::swap(T arr[], Node node1, Node node2) {

	T temp = arr[node1];
	arr[node1] = arr[node2];
	arr[node2] = temp;
}

  //**************// //**************// //**************//
 //*  PRIVATE:  *// //*  PRIVATE:  *// //*  PRIVATE:  *//
//**************// //**************// //**************//

/*
* Copies elements of given array and forms heap
* @param arr The given array to copy
*/
template<class T>
void Heap<T>::copyArray(const T arr[]) {

	for (Node curr(Heap<T>::ROOT); curr < this->itemCount; ++curr) {

		this->arr[curr] = arr[curr];
	}
}

/*
* Static method
* Gets the left child of the given node
* @param curr The current node
* @return the left child of curr
*/
template<class T>
Node Heap<T>::left(Node curr) {

	return (2 * curr + 1);
}

/*
* Static method
* Checks if the given node has right child
* @param curr The current node
* @return true if has right child, else false
*/
template<class T>
bool Heap<T>::hasRight(Node curr, int itemCount) {

	return (Heap<T>::right(curr) < itemCount);
}


/*
* Static method
* Gets the right child of the given node
* @param curr The current node
* @return the right child of curr
*/
template<class T>
Node Heap<T>::right(Node curr) {

	return (2 * curr + 2);
}

/*
* Helper function for display sideways
* @param curr The current node
* @param level the current level of the heap
*/
template<class T>
void Heap<T>::sideways(Node curr, int level) {

	if (curr < this->itemCount) {

		++level;

		this->sideways(Heap<T>::right(curr), level);

		for (int i(level); i >= Heap<T>::ROOT; --i) {

			std::cout << "    ";
		}

		std::cout << this->arr[curr] << std::endl;

		this->sideways(Heap<T>::left(curr), level);
	}
}
