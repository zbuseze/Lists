#ifndef _NODE_
#define _NODE_
#include <iostream>
class Node{
public:
	int data;
	Node *next;
	Node(int v=0):next(NULL),data(v){}
};//end of Node

#endif