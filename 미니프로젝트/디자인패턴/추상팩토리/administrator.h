#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "common.h"
#include "menu.h"
#include "operator.h"

class Administrator : public Operator {
	
public:
	Administrator() {}
	int play(vector<Seat *> *S);	
	
};

#endif

