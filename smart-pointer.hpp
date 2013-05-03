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
		RefCounter::getInstance().use(pointer);
	}

	SmartPointer(T * pValue) {
		pointer = pValue;
		RefCounter::getInstance().use(pointer);
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

	SmartPointer<T>& operator=(SmartPointer<T> sp) {
		unuse();
		pointer = sp.pointer;
		RefCounter::getInstance().use(pointer);
		
		return *this;
	}
	
private:
  	T* pointer;

	void unuse() {
		if (RefCounter::getInstance().unuse(pointer)) {
			delete pointer;
			pointer = NULL;
		}
	}
};

#endif
