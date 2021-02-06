#include <iostream>
#include "builder.h"
#include "event.h"
#include "linkedlist.h"
#include "stack.h"
#include "structuretype.h"


using namespace std;

void builder::setBuilderNum(int build_number) {
	builder_number = build_number;
}

void builder::addRequest(int sector, structure_type to_build) {
	cout << "Builder #" << builder_number << ": Received request to build a " << str(to_build) << " in sector " << sector << endl;
	event new_event(sector, to_build);
	ll.insertFront(new_event);
}

bool builder::doCycle() {
	if (ll.isEmpty()) {
		return false;
	} else {
		event result;
		ll.removeBack(result);
		if (oldest_sector != result.getSector()){
			cout << "Builder #" << builder_number << ": Moving to sector " << result.getSector() << endl;
		}
		cout << "Builder #" << builder_number << ": Building a " << str(result.getType()) << " in sector " << result.getSector() << endl;
		s.push(result);
		oldest_sector = result.getSector();
		return true;
	}
}

void builder::returnHome() {
	oldest_sector = -1;
	while(s.isEmpty() == false){
		event result = s.pop();
		if (oldest_sector != result.getSector() && oldest_sector != -1){
			cout << "Builder #" << builder_number << ": Moving to sector " << result.getSector() << endl;
		}
		cout << "Builder #" << builder_number << ": Connected to " << str(result.getType()) << " in sector " << result.getSector() << endl;
		oldest_sector = result.getSector();
	}
	cout << "Builder #" << builder_number << ": Arrived back at base." << endl;
}

