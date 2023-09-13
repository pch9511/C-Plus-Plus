#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "common.h"
#include "menu.h"

class Employee {
	int num;
	string name;
	string job;
	string sex;
	int Pnum;
public:
	Employee() { job = "가짜"; }
	Employee& clone() { return *this;}
	void show() { cout << job << endl; }
};

class Chief : public Employee {		//주임 
public:
	
};

class SC : public Employee {		//과장 
	
public:
	Employee *clone();		
};


class DH : public Employee {		//부장 
	
public:
	Employee *clone();		
};

class TL : public Employee {		//팀장 
	
public:
	Employee *clone();		
};








#endif
