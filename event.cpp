#include "event.h"
#include <iostream>

using namespace std;

event::event() {
	sector = -1;
}

event::event(int sector_input, structure_type input_structure) {
	sector = sector_input;
    structure = input_structure;	
}

int event::getSector() {
	return sector;
}

void event::setSector(int input_sector) {
	sector = input_sector;
}

structure_type event::getType() {
	return structure;
}

void event::setType(structure_type input_structure) {
	structure = input_structure;
}
