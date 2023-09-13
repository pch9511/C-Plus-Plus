#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "common.h"
#include "operator.h"

class Customer : public Operator {
	string ID;
	int PW;
	int phoneNum;
public:
	Customer() { }
	Customer(string id,int pw,int pn) : ID(id),PW(pw),phoneNum(pn) {}
	Customer(const Customer& c);
	~Customer() {};		//결국 사용 X -> 어떻게 사용해야하지? 
	int play(vector<Seat *> *S);
	string getID() { return ID; }
	int getPW() { return PW; }
	int getPN() { return phoneNum; }
	void infoIn(string id,int pw,int pn);
	void show();
};

#endif

