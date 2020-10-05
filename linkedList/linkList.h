#pragma once
#include "Node.h"

template<class T>
class linkList
{
private:
	Node<T>* _head;
	Node<T>* getHead() const { return this->_head; }
	Node<T>* getTail() const {
		if (this->getHead() == NULL) return NULL;
		Node<T>* temp = this->getHead();
		while (temp->getNext())
			temp = temp->getNext();
		return temp;
	}
public:
	linkList() :_head(NULL) {}
	
	~linkList() {
		this->clearList();
	}

	int size() const {
		int counter = 0;
		Node<T>* temp = this->getHead();
		while (temp) {
			counter++;
			temp = temp->getNext();
		}
		return counter;
	}
	void pushFront(const T & d) {
		Node<T>* newNode = new Node<T>(d);
		if (this->getHead() == NULL)
		{
			this->_head = newNode;
			return;
		}
		this->getHead()->setPrev(newNode);
		newNode->setNext(this->getHead());
		this->_head = newNode;
	}
	void pushBack(const T& d) {
		Node<T>* newNode = new Node<T>(d);
		if (this->getHead() == NULL)
		{
			this->_head = newNode;
			return;
		}
		Node<T>* tail = this->getTail();
		tail->setNext(newNode);
		newNode->setPrev(tail);
	}
	void printListToScreen() const {
		if (this->size() == 0) {
			cout << "Empty list" << endl;
			return;
		}
		cout << "||<-->";
		Node<T>* temp = this->getHead();
		while (temp) {
			cout << *(temp->getDataPtr()) << "<-->";
			temp = temp->getNext();
		}
		cout << "||" << endl;
	}
	void saveToBinFile(ostream& out) const {
		int size = this->size();
		out.write((char*)&size, sizeof(int));
		Node<T>* temp = this->getHead();
		while (temp) {
			out.write((char*)(temp->getDataPtr()), sizeof(T));
			temp = temp->getNext();
		}
	}
	void printListToTextFile(ostream& out) const {
		out << this->size() << endl;
		Node<T>* temp = this->getHead();
		while (temp) {
			out << *(temp->getDataPtr()) << endl;
			temp = temp->getNext();
		}
	}
	friend ostream& operator<<(ostream& out, const linkList<T>& other) {
		other.printListToTextFile(out);
		return out;
	}
	void scanFromKeyboard() {
		int size;
		cout << "Enter the size : ";
		cin >> size;
		T temp;
		for (int i = 0; i < size; i++)
		{
			cout << "Enter value number " << i + 1 << " : ";
			cin >> temp;
			this->pushBack(temp);
		}
	}
	void scanFromtxtFile(istream & in) {
		int size;
		in >> size;
		T temp;
		for (int i = 0; i < size; i++) {
			in >> temp;
			this->pushBack(temp);
		}
	}
	friend istream& operator>>(istream& in, linkList<T>& other) {
		other.scanFromtxtFile(in);
		return in;
	}
	void deleteFront() {
		if (this->getHead() == NULL) return;
		Node<T>* temp = this->getHead();
		this->_head = this->_head->getNext();
		delete temp;
		this->_head->setPrev(NULL);
	}
	void deleteBack() {
		if (this->getHead() == NULL) return;
		if (this->size() == 1) {
			delete this->_head;
			this->_head = NULL;
			return;
		}
		Node<T>* temp = this->getTail();
		Node<T>* temp1 = temp->getPrev();
		delete temp;
		temp1->setNext(NULL);
	}
	void clearList() {
		while (this->size())
			this->deleteFront();
	}
};

