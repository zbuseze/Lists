#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedList{
private:
	Node *head;
public:
	LinkedList():head(NULL){}
	void traverse()const
	{
		Node *walk=head;
		cout<<"\nLinkedList:";
		while(walk!=NULL)
		{
			cout<<walk->data<<"->";
			walk=walk->next;
		}
		cout<<"NULL"<<endl;
	}
	void deleteFirst()
	{
		if(head!=NULL){
			Node *p=head;
			head=head->next;
			delete p;
		}
	}
	void insertFirst(int data){
		Node *p=new Node(data);
		p->next=head;
		head=p;
	}
	void insertLast(int dat){
		Node *newNode=new Node(dat);
		if(head==NULL){
			head=newNode;
		}
		else{
			Node *walk=head;
			while(walk!=NULL){
				if(walk->next==NULL)
					break;
				walk=walk->next;
			}
			walk->next=newNode;
		}
	}
	void insertAt(int dat,int pos){

		if(pos==0)//insert at first
		{
			Node *newNode=new Node(dat);
			newNode->next=head;
			head=newNode;
		}
		else{
			Node *prev=NULL,*walk=head;
			int cnt=0;
			while(walk!=NULL){
				if(cnt==pos)
					break;
				prev=walk;
				walk=walk->next;
				cnt++;
			}
			if(cnt==pos){
				Node *newNode=new Node(dat);
				prev->next=newNode;
				newNode->next=walk;
			}
		}
	}
	int getSize()const{
		int cnt=0;
		Node *walk=head;
		while(walk!=NULL)
		{
			cnt++;
			walk=walk->next;
		}
		return cnt;
	}
	void deleteAt(int pos)
	{
		if( (pos<0)||(head==NULL) ) return ;
		if(pos==0)
		{
			Node *oldHead=head;
			head=head->next;
			delete oldHead;
		}else{

			Node*walk=head,*prev=NULL;
			int cnt=0;
			while(walk!=NULL){
				if(pos==cnt)
					break;
				prev=walk;
				walk=walk->next;
				cnt++;
			}//end of while
			if(pos==cnt)
			{
				prev->next=walk->next;
				delete walk;
			}
		}
	}//end of 
	void deleteAt_data(int data)//to be completed by students
	{
	}

};//end of Node

#endif