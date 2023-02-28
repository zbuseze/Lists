#pragma once
#include<iostream>
using namespace std;
#define PAR(n)		(((n)-1)/2)
#define LCHILD(n)	((2*(n))+1)
#define RCHILD(n)	((2*(n))+2)
#define MAXARRAY 1000

template<typename T>
class MinHeap {
private:
	T itmArray[1000];
	int size;
public:
	MinHeap() :size(0) {}
	void insert(const T& key) {
		itmArray[size] = key;
		bubbleUp(size);
		size++;
	}
	T deleteMin() {
		if (isEmpty()) {
			cout << "Heap is Empty" << endl;
			exit(0);
		}
		T minItm = itmArray[0];
		itmArray[0] = itmArray[size - 1];
		size--;
		bubbleDown(0);
		return minItm;

	}
	T getMin()const {
		if (isEmpty()) {
			cout << "Heap is Empty" << endl;
			exit(0);
		}
		return itmArray[0];
	}
	int getSize()const {

	}
	bool isFull()const {
		return size == MAXARRAY;
	}
	bool isEmpty()const {
		return size == 0;
	}

private:
	void bubbleUp(int location) {
		while (location > 0) {
			if (itmArray[location] < itmArray[PAR(location)]) {
				T tmp = itmArray[location];
				itmArray[location] = itmArray[PAR(location)];
				itmArray[PAR(location)] = tmp;
				location = PAR(location);
			}
			else
				break;
		}
	}
	void bubbleDown(int loc) {
		int minLoc;
		while (loc < size) {
			minLoc = loc;
			if (RCHILD(loc) < size) { //if there exists left and right child
				if (itmArray[LCHILD(loc)] < itmArray[RCHILD(loc)]) {
					if (itmArray[minLoc] > itmArray[LCHILD(loc)])
						minLoc = LCHILD(loc);
				}
				else {
					if (itmArray[minLoc] > itmArray[RCHILD(loc)])
						minLoc = RCHILD(loc);
				}

				if (loc == minLoc)//there is no need to swap
					break;
				//swap root with smaller child if possible
				T tmp = itmArray[minLoc];
				itmArray[minLoc] = itmArray[loc];
				itmArray[loc] = tmp;
				loc = minLoc;//update loc

			}
			else if (LCHILD(loc) < size) {// if there is only left child
				if (itmArray[loc] > itmArray[LCHILD(loc)]) {// if parent is greater than left child then swap
					T tmp = itmArray[LCHILD(loc)];
					itmArray[LCHILD(loc)] = itmArray[loc];
					itmArray[loc] = tmp;
					loc = LCHILD(loc);//update loc
				}
				else break;
			}
			else { //if there is no child 
				loc = size;
				break;
			}
		}

	}

};



