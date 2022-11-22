#pragma once
#include<ostream>
#define CONST 2;
template<typename T>class Vector {
protected:
	T* data = 0;
	int size = 0;
	int capacity = 0;
public:
	int getsize() {
		return size;
	}
	Vector() {
		size = 0;
		data = nullptr;
		capacity = size + 1;
	}
	Vector(int size = 0) {
		this->size = size;
		this->capacity = (size + 1) * CONST;
		this->data = new T[capacity];
		for (int i = 0; i < capacity; i++) data[i] = 0;
	}

	Vector(const Vector& vector) {
		T* tmp = new T[vector.capacity];
		for (int i = 0; i < capacity; i++) {
			if (i < size) tmp[i] = data[i];
			else tmp[i] = 0;
		}
		size = vector.size;
		capacity = vector.capacity;
		delete[] data;
		data = tmp;
	}

	~Vector() {
		this->size = 0;
		this->capacity = 0;
		delete[] this->data;
	}
	void randomFill() {
		for (int i = 0; i < size; i++) data[i] = rand() % 113;
	}

	T erase(int index) {
		T tmp = data[index];
		for (int i = index; i <= size; i++)
			data[i] = data[i + 1];
		size--;
		return tmp;
	}
	void insert(T elem, int index) {
		if (capacity <= (size + 1))resize(size + 1);
		for (int i = size; i >= index; i--)
			data[i + 1] = data[i];
		data[index] = elem;
	}


	void resize(int newSize) {
		if (newSize < capacity) {
			if (newSize < size) {
				for (int i = newSize; i < size; i++)
					data[i] = 0;
			}
		}
		if (newSize > capacity) {
			capacity = (newSize + 1) * 2;
			T* tmp = new T[capacity];
			for (int i = 0; i < capacity; i++) {
				if (i < size)
					tmp[i] = data[i];
				else tmp[i] = 0;
			}
			delete[] data;
			data = tmp;
		}
		size = newSize;
	}
	void push_back(T elem) {
		size++;
		if ((size) >= capacity) resize(size);
		data[size - 1] = elem;

	}
	T pop_back() {
		size--;
		T tmp = data[size];
		data[size] = 0;
		return tmp;
	}

	Vector& operator=(const Vector& v) {
		if (this != &v) {
			if (v.size != this->size)
				this->resize(v.size);
			for (int i = 0; i < v.size; i++)
				this->data[i] = v.data[i];
		}
		return *this;
	}
	T& operator[](int index) {
		if (index < size)return data[index];
		else std::cout << "index out of range.Max index is " << size - 1 << ". Take last element.";
		return data[size - 1];
	}
	T operator[](int index) const {
		if (index < size)return data[index];
		else std::cout << "index out of range. Max index is " << size - 1 << ". Last element:";
		return data[size - 1];
	}


	/*
	std::ostream& operator<< (std::ostream& out, const Vector& v) {
		out << "(";
		for (int i = 0; i < v.size; i++) {
			out << v.data[i];
			if ((i + 1) != v.size)
				std::cout << ",";
		}
		std::cout << ")";
		std::cout << std::endl;
		return out;
	}
*/
	Vector(const std::initializer_list<T>& l) {
		int i = 0; data = new T[l.size()]; this->size = l.size();
		for (auto it = l.begin(); it != l.end(); ++it) {
			data[i++] = *it;
		}
	}
};