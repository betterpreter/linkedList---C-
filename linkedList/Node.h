#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class Node
{
private:
	T* _dataPtr;
	Node<T>* _next;
	Node<T>* _prev;
public:
	Node():_next(NULL),_prev(NULL),_dataPtr(NULL) {}
	Node(const T & data):_next(NULL),_prev(NULL) {
		//this->_dataPtr = &data;
		this->_dataPtr = new T(data);
	}
	~Node() {
		if (this->_dataPtr)
			delete this->_dataPtr;
		//delete this->_next;
		//delete this->_prev;
	}
	Node<T>* getNext() const { return this->_next; }
	Node<T>* getPrev() const { return this->_prev; }
	T* getDataPtr() const { return this->_dataPtr; }
	void setNext(Node<T>* n) { this->_next = n; }
	void setPrev(Node<T>* p) { this->_prev = p; }
	void setData(const T& d) { 
		if (this->_dataPtr)
			delete this->_dataPtr;
		this->_dataPtr = new T(d);
	}
	void printToOutput(ostream& out) const {
		out << *(this->_dataPtr);
	}

};

