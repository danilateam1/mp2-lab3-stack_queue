#include "Vector.h"
using namespace std;
template<typename T>class Queue {
private:
	int startptr;
	int finishptr;
	int size;
	int capacity;
	T* data;
public:
	Queue() {
		size = 0;
		capacity = 1;
		data = new T[capacity];
		startptr = 0;
		finishptr = 0;
	}

	Queue(T val) {
		size = 1;
		capacity = 2;
		data = new T[capacity];
		data[0] = val;
		startptr = 0;
		finishptr = 1;
	}
	~Queue() {
		delete[]data;
	}
	void resize() {
		capacity = (size + 1) * 2;
		T* tmp = new T[capacity];
		int m = 0;
		for (int i = startptr; i < size; i++) {
			tmp[m++] = data[i];
		}
		for (int i = 0; i <= finishptr; i++) {
			tmp[m++] = data[i];
		}
		delete[] data;
		data = tmp;
		startptr = 0;
		finishptr = size;
	}
	bool empty() {
		if (size == 0) {
			return true;
		}
		return false;
	}
	void push(T val) {
		size++;
		finishptr++;
		data[finishptr - 1] = val;
		if (finishptr == capacity) {
			finishptr = 0;
		}
		if ((startptr == finishptr) && (size != 0)) {
			resize();
		}
	}
	void pop() {
		if (size == 0) {
			throw out_of_range("QUEUE IS EMPTY");
		}
		startptr++;
		data[startptr - 1] = 0;
		size--;
		if (startptr == capacity) {
			startptr = 0;
		}
	}

	T front() {
		if (size == 0) {
			throw out_of_range("QUEUE IS EMPTY");
		}
		return data[startptr];
	}

	int getsize() {
		return size;
	}
};