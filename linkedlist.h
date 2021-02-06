#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "structuretype.h"
#include "event.h"

struct node_l {
	node_l *next;
	node_l *prev;
	event type;
};
//addRequest() insert item to head of list
//doCycle() remove node at tail of list
class linkedlist {
public: 
	linkedlist(); // constructor
	bool isEmpty(); // check to see if the list is empty
	void insertFront(event e); // insert new node as head
	void removeBack(event &result);
	int get_sector();
	~linkedlist();

private: 
	node_l *head, *tail;
};



#endif
