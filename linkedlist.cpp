#include "linkedlist.h"
#include "event.h"
#include <iostream>

using namespace std;

linkedlist::linkedlist() { // constructor
	head = NULL;
	tail = NULL;
}

linkedlist::linkedlist(const linkedlist &ll_to_copy){
	head = ll_to_copy.head;
	tail = ll_to_copy.tail;
}

linkedlist::~linkedlist() {
	node_l *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

bool linkedlist::isEmpty() {
	return (head == NULL);
}

void linkedlist::insertFront(event e) {
	// initialize new node
	node_l *newHead = new node_l;
	newHead->type = e;
	newHead->next = NULL;
	newHead->prev = NULL;	
	// if the list is empty
	if (head == NULL) {
		head = newHead;
		tail = newHead;
	} else if (head->next == NULL) {
		node_l *temp = head;
		newHead->next = temp;
		temp->prev = newHead;
		head = newHead;
		tail = temp;
	} else {
		node_l *temp = head;
		newHead->next = temp;
		temp->prev = newHead;
		head = newHead;
	}
}

void linkedlist::removeBack(event &result) {
	node_l *temp = tail;
	if (head->next == NULL){
		result = temp->type;
		delete temp;
		head = NULL;
		tail = NULL;
	} else {
		tail = tail->prev;
		tail->next = NULL;
		result = temp->type;
		delete temp;
	}
}