#ifndef PATIENT_H
#define PATIENT_H

#include "common.h"
#include "treat.h"

class Patient {	
	string name; //ȯ�ڸ� 
	int code;	 //����ǻ�
	string ill;	 //����
	int Pnum; 	 //����ó 
	int time;	 //����ð�
	int num;	 //�����ȣ  
public :
	Patient(string n,int c,string i,int p,int t,int rn) { name = n; code = c; ill = i; Pnum = p; time = t; num = rn; }
	void View();
	string getName() { return name; }
	int getCode() { return code; }
	string getIll() { return ill; }
	int getPnum() { return Pnum; }
	int getTime() { return time; }
	int getRN() { return num; }
	void Move(int tv,int cd) { time = tv; code = cd; }
};



#endif
