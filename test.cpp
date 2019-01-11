/*
* test.cpp
*
* Unit tests for MaxHeap class
*
* @author Juan Arias
*
*/

#include <iostream>
#include <string>
#include <cassert>
#include "maxheap.h"

/*
* Unit tests for constructors & assignment operator overload
*/
void constructorsAndAssignment() {

	Heap<int>* heap = new MaxHeap<int>;
	delete heap;

	int testArr[10]{5, 2, 8, 3, 1, 9, 7, 6, 4, 0};

	Heap<int>* heap1 = new MaxHeap<int>(testArr, 10);

	Heap<int>* heap2 = new MaxHeap<int>(*heap1);
	
	delete heap2;

	heap2 = new MaxHeap<int>;

	(*heap2) = (*heap1);

	delete heap2, heap1;
}

/*
* Unit tests for contains
*/
void contains() {

	std::string testArr[10]{ "GYRO", "CISCO", "POPS", "DISK", "BASE", "QUAVO",
		                     "MONSTER", "JACKA", "ELON", "ACE" };

	Heap<std::string>* heap = new MaxHeap<std::string>(testArr, 10);

	for (std::string word : testArr) {
		
		assert(heap->contains(word));
	}

	delete heap;
}

template<class T>
void addsert(Heap<T>* heap, const T& item) {
	
	heap->add(item);
	assert(heap->contains(item));
}

/*
* Unit test for add
*/
void add() {
	
	Heap<char>* heap = new MaxHeap<char>();

	for (char c('a'); c <= 'z'; ++c) {
	
		addsert(heap, c);
	}

	delete heap;
}

template <class T>
void removesert(Heap<T>* heap, const T& item) {

	heap->remove();
	
	assert(!heap->contains(item));
}

/*
* Unit test for remove
*/
void remove() {
	
	Heap<char>* heap = new MaxHeap<char>();

	for (char c('a'); c <= 'z'; ++c) {

		addsert(heap, c);
	}

	for (char c('z'); c >= 'a'; --c) {

		removesert(heap, c);
	}

	delete heap;
}

/*
* Unit test for isEmpty
*/
void isEmpty() {

	Heap<double>* heap = new MaxHeap<double>();

	assert(heap->isEmpty());
	
	for (double d(5.23); d <= 23.04; d += 2.40) {

		addsert(heap, d);
	}

	for (double d(23.04); d >= 5.23; d -= 2.40) {

		removesert(heap, d);
	}

	assert(heap->isEmpty());

	delete heap;
}

/*
* Unit test for clear
*/
void clear() {
	
	Heap<long>* heap = new MaxHeap<long>();

	for (long l(250000); l <= 10000000; l += 250000) {

		addsert(heap, l);
	}

	heap->clear();

	assert(heap->isEmpty());

	delete heap;
}

template <class T>
void peeksert(Heap<T>* heap, const T& item) {

	assert(heap->peek() == item);
	removesert(heap, item);
}

/*
* Unit test for peek
*/
void peek() {
	
	std::string testArr[10] {"GYRO", "CISCO", "POPS", "DISK", "BASE", "QUAVO",
							 "MONSTER", "JACKA", "ELON", "ACE" };

	Heap<std::string>* heap = new MaxHeap<std::string>(testArr, 10);

	std::string peek("QUAVO");
	peeksert(heap, peek);

	peek = "POPS";
	peeksert(heap, peek);

	peek = "MONSTER";
	peeksert(heap, peek);

	peek = "JACKA";
	peeksert(heap, peek);

	peek = "GYRO";
	peeksert(heap, peek);

	peek = "ELON";
	peeksert(heap, peek);

	peek = "DISK";
	peeksert(heap, peek);

	peek = "CISCO";
	peeksert(heap, peek);

	peek = "BASE";
	peeksert(heap, peek);

	peek = "ACE";
	peeksert(heap, peek);

	delete heap;
}

/*
* Unit test for getNodes
*/
void getNodes() {

	Heap<int>* heap = new MaxHeap<int>;

	for (int i(1); i <= 50; ++i) {
	
		addsert(heap, i);

		assert(heap->getNodes() == i);
	}

	heap->clear();

	assert(heap->getNodes() == 0);

	delete heap;
}

/*
* Unit test for getHeight
*/
void getHeight() {

	Heap<int>* heap = new MaxHeap<int>();

	for (int i(0); i < 90; ++i) {
		
		addsert(heap, i);

		assert(heap->peek() == i);
	}

	assert(heap->getHeight() == 7);
}

/*
* Unit test for equality operator overloads
*/
void operators() {
	
	Heap<int>* heap1 = new MaxHeap<int>;

	for (int i(1); i <= 50; ++i) {

		addsert(heap1, i);
	}

	Heap<int>* heap2 = new MaxHeap<int>(*heap1);

	assert(*heap1 == *heap2);

	heap1->remove();
	assert(*heap1 != *heap2);

	heap2->remove();
	assert(*heap1 == *heap2);

	delete heap2;

	heap2 = new MaxHeap<int>;

	for (int i(1); i <= 50; ++i) {

		addsert(heap2, i);
	}

	assert(*heap1 != *heap2);

	heap1->add(50);
	assert(*heap1 == *heap2);

	heap1->clear();
	heap2->clear();

	assert(*heap1 == *heap2);

	delete heap1, heap2;
}

/*
* Runs all unit tests
*/
void runTests() {

	constructorsAndAssignment();
	contains();
	add();
	remove();
	isEmpty();
	clear();
	peek();
	getNodes();
	getHeight();
	operators();
}

/*
* Begins unit testing
*/
int main() {
	
	runTests();
	std::cout << "Success!" << std::endl;
}