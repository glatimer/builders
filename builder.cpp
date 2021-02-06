#include "builder.h"
#include <iostream>

using namespace std;

void builder::setBuilderNum(int numBuilders) {
	builder_number = numBuilders;
}

void builder::addRequest(int, structure_type) {

}

bool builder::doCycle() {
	if (true) {
		cout << "Task complete" << endl;
	} else {
		cout << "Task not complete" << endl;
	}
}

void builder::returnHome() {

}

