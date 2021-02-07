#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "structuretype.h"
#include "event.h"

struct node_l {
	node_l *next;
	node_l *prev;
	event type;
};

class linkedlist {
public: 
	linkedlist(); // constructor
	linkedlist(const linkedlist &ll_to_copy);
	void operator = (const linkedlist &ll_to_copy){
		head = ll_to_copy.head;
		tail = ll_to_copy.tail;
	}
	~linkedlist();
	bool isEmpty(); // check to see if the list is empty
	void insertFront(event e); // insert new node as head
	void removeBack(event &result);

private: 
	node_l *head, *tail;
};

#endif