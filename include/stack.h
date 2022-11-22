#include "Vector.h"
using namespace std;
template<typename T>class Stack {
private:
	Vector<T> v;
	int size;
public:
	Stack() :v(0), size(0) { ; }
	Stack(T elem) :v(1),size(1) {
		v[0] = elem;
		size = 1;
	}
	int getsize() {
		return size;
	}
	bool empty() {
		if (size == 0) {
			return true;
		}
		return false;
	}
	void pop() {
		if (size == 0) {
			throw out_of_range("STACK IS EMPTY");
		}
		v.pop_back();
		size--;
	}
	void push(T val) {
		v.push_back(val);
		size++;
	}

	T top() {
		if (size == 0) {
			throw out_of_range("STACK IS EMPTY");
		}
		return v[size - 1];
	}
};
