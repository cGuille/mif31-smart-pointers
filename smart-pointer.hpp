#ifndef __SMART_POINTER_HPP_INCLUDED__
#define __SMART_POINTER_HPP_INCLUDED__

#include <iostream>
#include "ref-counter.hpp"

template<typename T>
class SmartPointer
{
public:
	// Constructeurs
	SmartPointer() {
		pointer = NULL;
	}

	SmartPointer(const SmartPointer<T> &sp) {
		pointer = sp.pointer;
		use();
	}

	SmartPointer(T * pValue) {
		pointer = pValue;
		use();
	}

	SmartPointer<T>& operator=(SmartPointer<T> sp) {
		unuse();
		pointer = sp.pointer;
		use();

		return *this;
	}

	// Destructeur
	~SmartPointer() {
		unuse();
	}

	// Opérateurs
	T& operator*() {
	  return *pointer;
	}

	T* operator->(){
	  return pointer;
	}

	bool operator==(SmartPointer<T> sp) {
		return pointer == sp.pointer;
	}

	bool operator!=(SmartPointer<T> sp) {
		return pointer != sp.pointer;
	}

	T& operator[](unsigned int index) {
		return pointer[index];
	}

	T* operator+(unsigned int i) {
		return pointer + i;
	}

private:
	T* pointer;

	void use() {
		if (pointer != NULL) {
			RefCounter::getInstance().use(pointer);
		}
	}

	void unuse() {
		if (pointer != NULL && RefCounter::getInstance().unuse(pointer)) {
			delete pointer;
			pointer = NULL;
		}
	}
};

#endif
