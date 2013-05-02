#ifndef __SMART_POINTER_H_INCLUDED__
#define __SMART_POINTER_H_INCLUDED__

#include <iostream>

template<typename T>
class SmartPointer
{
public:
	// Constructeurs
	SmartPointer() {
		pointer = NULL;
		refCount = 0;
	}

	SmartPointer(const SmartPointer<T> &sp) {
		pointer = sp.pointer;
		refCount = sp.refCount;
	}

	SmartPointer(T * pValue) {
		pointer = pValue;
		refCount = 1;
	}

	// Destructeur
	~SmartPointer() {
		decrement();
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
		decrement();
		pointer = sp.pointer;
		refCount = sp.refCount;
		increment();
		sp.increment();
		
		return *this;
	}
	
private:
 	int refCount;
  	T* pointer;

	void increment() {
		refCount++;
	}

	void decrement() {
		refCount--;
		
		if (refCount == 0 && pointer != NULL)
		{
			delete pointer;
			pointer = NULL;
		}
	}
};

#endif /* __SMART_POINTER_H_INCLUDED__ */
