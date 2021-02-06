#ifndef STACK_H
#define STACK_H

struct node {
	node *next;
	event build;
};	

class stack {
public:
 	stack();
	bool isEmpty();	
	bool push();
	int pop();
	int peak();
Private:
	node *head;
};






#endif
