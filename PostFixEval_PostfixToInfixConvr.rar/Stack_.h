#pragma once
#include "Node.h"
template <class T>
class Stack_ {
private:
	Node<T> *top;
public:
	Stack_() :top(NULL) {}
	bool isEmpty()const { return top == NULL; }
	bool isFull()const { return false; }
	T  pop() {
		if (isEmpty()) {
			cout << "Stack underflow";
			exit(0);
		}
		T data=top->data;
		Node<T> *t = top;
		top = top->next;
		delete t;
		return data;

	}
	void push(const T &itm) {
		Node <T> *t = new Node<T>(itm);
		t->next = top;
		top = t;
	}
};
