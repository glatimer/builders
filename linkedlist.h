#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "structuretype.h"
#include "event.h"

struct node {
	node *next;
	node *prev;
	event type;
};
//addRequest() insert item to head of list
//doCycle() remove node at tail of list
class linkedlist {
public: 
	linkedlist(); // constructor
	bool isEmpty(); // check to see if the list is empty
	void insertFront(event); // insert new node as head
	void removeBack(event&);
	~linkedlist();

private: 
	node *head, *tail;
};



#endif
