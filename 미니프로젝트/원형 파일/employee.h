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
	Employee() { job = "��¥"; }
	Employee& clone() { return *this;}
	void show() { cout << job << endl; }
};

class Chief : public Employee {		//���� 
public:
	
};

class SC : public Employee {		//���� 
	
public:
	Employee *clone();		
};


class DH : public Employee {		//���� 
	
public:
	Employee *clone();		
};

class TL : public Employee {		//���� 
	
public:
	Employee *clone();		
};








#endif
