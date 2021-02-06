#include "linkedlist.h"
#include "event.h"
#include <iostream>

using namespace std;

linkedlist::linkedlist() { // constructor
	head = NULL;
	tail = NULL;
}
bool linkedlist::isEmpty() {
	return (head == NULL);
}

void linkedlist::insertFront(event e) {
	// initialize new node
	node_l *newHead = new node_l;
	newHead->type.setSector(e.getSector());
	newHead->type.setType(e.getType());
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
		result.setSector(temp->type.getSector());
		result.setType(temp->type.getType());
		delete temp;
		head = NULL;
		tail = NULL;
	} else {
		tail = tail->prev;
		tail->next = NULL;
		result.setSector(temp->type.getSector());
		result.setType(temp->type.getType());
		delete temp;
	}
}

int linkedlist::get_sector(){
	return head->type.getSector();
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

