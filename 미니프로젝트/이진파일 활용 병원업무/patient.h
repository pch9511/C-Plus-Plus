#ifndef PATIENT_H
#define PATIENT_H

#include "common.h"
#include "treat.h"

class Patient {	
	string name; //환자명 
	int code;	 //담당의사
	string ill;	 //질병
	int Pnum; 	 //연락처 
	int time;	 //예약시간
	int num;	 //예약번호  
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
