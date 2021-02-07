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
 	stack(const stack &stack_to_copy);
	void operator = (const stack &stack_to_copy){head = stack_to_copy.head;}
 	~stack();
	bool isEmpty();	
	void push(event e);
	event pop();
private:
	node *head;
};
#endif
