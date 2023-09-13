#ifndef OPERATOR_H
#define OPERATOR_H
#include "common.h"
#include "seat.h"

class Operator {	
	vector<Seat *> seat;
	static int Otime;
	static int totalP;
	static int timeP; 
public:
	void seatSet();
	void totalPrice();
	void timeSchedule();
	void reservation(int PN);
	void RState();
	int SState();
	void SShow(int time);
	void In(int PN);
	void Out(); 
	void Set(vector<Seat *> *S);
	void Get(vector<Seat *> **S);
	int AccountDel(int PN);
	virtual int play(vector<Seat *> *S) = 0;
};

#endif
