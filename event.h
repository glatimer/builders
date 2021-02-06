#ifndef EVENT_H
#define EVENT_H
#include "structuretype.h"

class event {
public:
	event();
	// event(event& obj);
	event(int input_sector, structure_type input_struct);
	// ~event();
	int getSector();
	void setSector(int input_sector);
	structure_type getType();
	void setType(structure_type input_structure);
	void print();
private: 
	int sector;
	structure_type structure;
};


#endif
