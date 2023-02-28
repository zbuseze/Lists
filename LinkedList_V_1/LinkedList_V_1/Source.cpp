#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList myList;
	myList.insertFirst(33);
	myList.insertFirst(12);
	myList.insertLast(555);
		myList.traverse();
	myList.insertAt(333,1);
	myList.insertAt(777,myList.getSize() );//test for insert  at last location
	myList.traverse();
	myList.insertAt(222,0); //test case for insertion at first
	myList.traverse();
	myList.insertAt(-999,70); //test case for non existent position
	myList.traverse();
	cout<<"Delete at 0\n";
	myList.deleteAt(0);
	myList.traverse();
	cout<<"Delete the last node\n";
	myList.deleteAt(myList.getSize()-1);
	myList.traverse();
	cout<<"Delete non existent node\n";
	myList.deleteAt(70);
	myList.traverse();
	cout<<"Delete from middle of a linkedList\n";
	myList.deleteAt(2);
	myList.traverse();


	return 0;
}