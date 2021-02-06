#include "linkedlist.h"
#include "event.h"
#include <iostream>

using namespace std;

linkedlist::linkedlist() { // constructor
	head = NULL;
	tail = NULL;
}
bool linkedlist::isEmpty() {
	if (head == NULL) {
		return true;
	} else {
		return false;
	}
}

void linkedlist::insertFront(event type) {
	// initialize new node
	node *newHead = new node;
	newHead->type = type;
	newHead->next = NULL;
	newHead->prev = NULL;	
	// if the list is empty
	if (head == NULL) {
		head = newHead;
		tail = newHead;
	} else if (head->next == NULL) {
		node *temp = head;
		newHead->next = temp;
		temp->prev = newHead;
		head = newHead;
		tail = temp;
	} else {
		node *temp = head;
		newHead->next = temp;
		temp->prev = newHead;
		head = newHead;
	}
}

void linkedlist::removeBack(event &result) {
	node *temp = tail;
	tail = tail->prev;
	tail->next = NULL;
	result.setSector(temp->type.getSector());
	result.setType(temp->type.getType());
	delete temp;
}

linkedlist::~linkedlist() {
	node *temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

