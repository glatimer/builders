#ifndef STACK_H
#define STACK_H
#include "structuretype.h"
#include "event.h"

using namespace std;

struct node {
	node *next;
	event build;
};	

class stack {
public:
 	stack();
 	~stack();
	bool isEmpty();	
	void push(event e);
	event pop();
	// int peak();
private:
	node *head;
};
#endif
