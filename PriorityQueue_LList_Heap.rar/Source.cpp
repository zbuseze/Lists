#include <iostream>
#include <vector>
#include <ostream>
#include <string>
#include <limits>
#include"minHeap.h"

using namespace std;

template <class T>
class PriorityQueue {
public:
	virtual bool isEmpty()const = 0;
	virtual bool isFull()const = 0;

	//returns true if operation is successful otherwise false
	virtual void enqueue(const T &) = 0;

	//returns true if operation is successful otherwise false, and the item at front of queue is returned as argument
	virtual T dequeueMin() = 0;
	//returns true if operation is successful otherwise false, and the item at front of queue is returned as argument
	virtual T getMin()const = 0;
};

template <class T>
class Node {
public:
	T data;
	Node *next;
	Node() :next(NULL) {}
	Node(const T &dat) :next(NULL), data(dat) {}


};

template <class T>
class LinkedPriorityQueue :public PriorityQueue<T>
{
private:
	Node<T> *front, *rear;
public:
	LinkedPriorityQueue() :front(NULL), rear(NULL) {}
	bool isEmpty()const { return front == NULL; }
	 bool isFull()const { return true; }
	 void enqueue(const T &itm) {
		Node <T> *newNode = new Node<T>(itm);
		if (front == NULL) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = rear->next;
		}
	}


	T dequeueMin() {
		T itm;
		if (front == NULL) {
			cout << "Queue underflow";
			exit(0);
		}
		else if (front->next == NULL) {
			itm = front->data;
			delete front;
			front = rear = NULL;
		}
		else {
			Node <T> *min, *minPrev, *prev, *walk;
			min = front;
			minPrev = NULL;
			walk = front->next;
			prev = front;
			while (walk != NULL) {
				if (walk->data < min->data) {
					min = walk;
					minPrev = prev;
				}
				prev = walk;
				walk = walk->next;
			}
			if (min == front) {
				itm = min->data;
				front = front->next;
				delete min;
			}
			else if (min == rear) {
				minPrev->next = NULL;
				itm = min->data;
				delete min;
				rear = minPrev;
			}
			else {
				itm = min->data;
				minPrev->next = min->next;
				delete min;
			}
		}//end else
		return itm;
	}
	//returns true if operation is successful otherwise false, and the item at front of queue is returned as argument
	T getMin()const {
		T itm;
		if (front == NULL) {
			cout << "Queue underflow";
			exit(0);
		}
		else if (front->next == NULL) {
			itm = front->data;

		}
		else {
			Node <T> *min, *minPrev, *prev, *walk;
			min = front;
			minPrev = NULL;
			walk = front->next;
			prev = front;
			while (walk != NULL) {
				if (walk->data < min->data) {
					min = walk;
					minPrev = prev;
				}
				prev = walk;
				walk = walk->next;
			}
			itm = min->data;
		}//end else
		return itm;
	}
};

template <class T>
class OrderedLinkedPriorityQueue :public PriorityQueue<T>
{
private:
	Node<T> *head;
public:
	OrderedLinkedPriorityQueue() : head(NULL) {}
	bool isEmpty()const { return head == NULL; }
	 bool isFull()const { return true; }
	 void enqueue(const T &itm) {
		Node <T> *newNode = new Node<T>(itm);
		if (head == NULL) {
			head = newNode;
		}
		else {
			if (itm < head->data) {
				newNode->next = head;
				head = newNode;
			}
			else {
				Node<T> *prev = NULL, *walk = head;
				while (walk != NULL) {
					if (itm < walk->data)
						break;
					prev = walk;
					walk = walk->next;
				}
				prev->next = newNode;
				newNode->next = walk;
			}

		}
	}


	T dequeueMin() {
		T itm;
		if (head == NULL) {
			cout << "Queue underflow";
			exit(0);
		}
		itm = head->data;
		Node<T> *oldPtr = head;
		head = head->next;
		delete oldPtr;
		return itm;
	}
	//returns true if operation is successful otherwise false, and the item at front of queue is returned as argument
	T getMin()const {
		T itm;
		if (head == NULL) {
			cout << "Queue underflow";
			exit(0);
		}
		itm = head->data;
		return itm;
	}
};


template<class T>
class MinHeapBasedPQueue:public PriorityQueue<T>{
public:
	bool isEmpty()const {
		return mHeap.isEmpty();
	}

	 bool isFull()const {
		 return mHeap.isFull();
	 }
	  void enqueue(const T &itm) {
		  mHeap.insert(itm);
	 }
	  T dequeueMin() {
		return mHeap.deleteMin();
	 }
	  T getMin()const {
		 return  mHeap.getMin();
  }
 private:
	 MinHeap<T> mHeap;
};

class Vehicle {
private:
	string carType;
	int priority;
public:
	Vehicle(const string &cT = "None", int pri = INT_MAX) :carType(cT), priority(pri) {}
	friend ostream & operator<<(ostream &out, const Vehicle &);
	bool operator<(const Vehicle &other)const {
		return priority < other.priority;
	}
	bool operator>(const Vehicle &other)const {
		return priority > other.priority;
	}
	bool operator==(const Vehicle &other)const {
		return priority == other.priority;
	}
	bool operator<=(const Vehicle &other)const {
		return priority <= other.priority;
	}
};
ostream & operator<<(ostream &out, const Vehicle &itm) {
	out << "|" << itm.carType << " " << itm.priority << "|";
	return out;
}

template<class T>
bool binarySearchRecursive(const T &key, const T list[], int &startIdx, int &endIdx) {	if (startIdx > endIdx) { return false; }int middle = (startIdx + endIdx) / 2;	if (key == list[middle]) { return true; }	if (key < list[middle]) { endIdx = middle - 1; }	if (key > list[middle]) { startIdx = middle + 1; }		return binarySearchRecursive(key, list, startIdx, endIdx);}


void main() {
	LinkedPriorityQueue <int> pq;
	pq.enqueue(22);
	pq.enqueue(8);
	pq.enqueue(2);
	pq.enqueue(19);
	pq.enqueue(4);
	pq.enqueue(11);
	pq.enqueue(2);

	while (!pq.isEmpty())
		cout << " Dequeued itm:" << pq.dequeueMin() << endl;

	LinkedPriorityQueue <Vehicle> Vpq;
	Vpq.enqueue(Vehicle("Car1", 5));
	Vpq.enqueue(Vehicle("Car2", 4));
	Vpq.enqueue(Vehicle("Police Car", 3));
	Vpq.enqueue(Vehicle("Car3", 4));
	Vpq.enqueue(Vehicle("Ambulance", 1));
	Vpq.enqueue(Vehicle("Car5", 7));
	Vpq.enqueue(Vehicle("Car6", 8));
	Vpq.enqueue(Vehicle("Car9", 4));
	Vpq.enqueue(Vehicle("Fire Truck", 2));
	while (!Vpq.isEmpty())
		cout << " Dequeued itm:" << Vpq.dequeueMin() << endl;

	OrderedLinkedPriorityQueue <Vehicle> V2Pq;
	cout << "Priority Queue implementation based on Ordered Linked List " << endl;
	V2Pq.enqueue(Vehicle("Car1", 5));
	V2Pq.enqueue(Vehicle("Car2", 4));
	V2Pq.enqueue(Vehicle("Police Car", 3));
	V2Pq.enqueue(Vehicle("Car3", 4));
	V2Pq.enqueue(Vehicle("Ambulance", 1));
	V2Pq.enqueue(Vehicle("Car5", 7));
	V2Pq.enqueue(Vehicle("Car6", 8));
	V2Pq.enqueue(Vehicle("Car9", 4));
	V2Pq.enqueue(Vehicle("Fire Truck", 2));
	while (!V2Pq.isEmpty())
		cout << " Dequeued itm:" << V2Pq.dequeueMin() << endl;

	MinHeapBasedPQueue<Vehicle> minHeapPQ;
	cout << "Priority Queue implementation based on Heap(min) " << endl;
	minHeapPQ.enqueue(Vehicle("Car1", 5));
	minHeapPQ.enqueue(Vehicle("Car2", 4));
	minHeapPQ.enqueue(Vehicle("Police Car", 3));
	minHeapPQ.enqueue(Vehicle("Car3", 4));
	minHeapPQ.enqueue(Vehicle("Ambulance", 1));
	minHeapPQ.enqueue(Vehicle("Car5", 7));
	minHeapPQ.enqueue(Vehicle("Car6", 8));
	minHeapPQ.enqueue(Vehicle("Car9", 4));
	minHeapPQ.enqueue(Vehicle("Fire Truck", 2));
	while (!minHeapPQ.isEmpty())
		cout << " Dequeued itm:" << minHeapPQ.dequeueMin() << endl;

}
