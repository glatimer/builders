#ifndef BUILDER_H
#define BUILDER_H
#include "structuretype.h"

class builder {
	public:  
		void setBuilderNum(int);
		void addRequest(int, structure_type);
		bool doCycle();
		void returnHome();
	private:
		int builder_number;
};
#endif 
