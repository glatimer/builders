#ifndef BUILDER_H
#define BUILDER_H
#include "structuretype.h"
#include "linkedlist.h"
#include "stack.h"

class builder {
	public:  
		void setBuilderNum(int buil_number);
		void addRequest(int sector, structure_type to_build);
		bool doCycle();
		void returnHome();
	private:
		int builder_number;
		linkedlist ll;
		stack s;
		int oldest_sector = -1;
};
#endif 
