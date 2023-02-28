#pragma once
template <class T>
class Node {
public:
	T data;
	Node *next;
	Node():next(NULL){}
	Node(const T &dat) :next(NULL),data(dat) {}


};