#ifndef EVENT_H
#define EVENT_H
#include "structuretype.h"

class event {
public:
	event();
	event(int input_sector, structure_type input_struct);
	event(const event& event_to_copy);
	void operator = (const event &event_to_copy){
		sector = event_to_copy.sector;
		structure =  event_to_copy.structure;
	}
	int getSector();
	void setSector(int input_sector);
	structure_type getType();
	void setType(structure_type input_structure);

private: 
	int sector;
	structure_type structure;
};

#endif