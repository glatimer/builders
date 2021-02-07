#include "stack.h"
#include <iostream>

using namespace std;

stack::stack(){
	head = NULL;
}

stack::stack(const stack &stack_to_copy){
	head = stack_to_copy.head;
}

stack::~stack(){
	node *tmp;
	while (head != NULL){
		tmp = head;
		head = head->next;
		delete(tmp);
	}
	delete(head);
}

bool stack::isEmpty(){
	return (head == NULL);
}

void stack::push(event e){
	node *tmp = new node;
	tmp->build = e;
	tmp->next = NULL;
	if (head == NULL) {
		head = tmp;
	} else {
		tmp->next = head;
		head = tmp;
	}

}

event stack::pop(){
	node *tmp;
	event popped_event;
	tmp = head;
	head = tmp->next;
	popped_event = tmp->build;
	delete(tmp);
	return popped_event;
}
