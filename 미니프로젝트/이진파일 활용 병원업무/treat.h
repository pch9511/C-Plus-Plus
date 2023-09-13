#ifndef TREAT_H
#define TREAT_H

#include "common.h"

typedef struct ListNode {
	string name;
	struct ListNode* link;
}TreatList;

class Treat {	//진료과목 
	TreatList* h;
	const char* file;
public:
	Treat();
	void Add();
	void Print();
	bool Check(string s);
	void Mod();
	void Del();
	void Save();
	bool Nothing();
	string getName(string s);
};


#endif
