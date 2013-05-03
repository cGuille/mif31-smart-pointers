#ifndef __SMART_POINTER_HPP_INCLUDED__
#define __SMART_POINTER_HPP_INCLUDED__

#include <iostream>
#include "ref-counter.hpp"

template<typename T>
class SmartPointer
{
public:
	/* Default constructor: we set the underlaying
	 * pointer to NULL */
	SmartPointer() {
		pointer = NULL;
	}

	/* Copy constructor: we get the other pointer
	 * and signal to the references counter that
	 * we hold it */
	SmartPointer(const SmartPointer<T> &sp) {
		pointer = sp.pointer;
		use();
	}

	/* Conversion constructor: let us construct from
	 * from a pointer to T. I.e. permits:
	 * SmartPointer<T> sp = new T; */
	SmartPointer(T * pValue) {
		pointer = pValue;
		use();
	}

	/* Assignment operator overloading. We signal to
	 * the references counter that we release the
	 * previous address and hold the new one */
	SmartPointer<T>& operator=(SmartPointer<T> sp) {
		unuse();
		pointer = sp.pointer;
		use();

		return *this;
	}

	/* Signal to the references counter that we
	 * release the current address */
	~SmartPointer() {
		unuse();
	}

	/* Operators overloading */
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

	/* Signal to the references pointer that we
	 * hold the current address, except if it
	 * is NULL */
	void use() {
		if (pointer != NULL) {
			RefCounter::getInstance().use(pointer);
		}
	}

	/* Signal to the references pointer that we
	 * release the current address, and free the
	 * memory if necessary */
	void unuse() {
		if (pointer != NULL && RefCounter::getInstance().unuse(pointer)) {
			delete pointer;
			pointer = NULL;
		}
	}
};

#endif
