#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "common.h"
#include "treat.h"
#include "doctor.h" 
#include "patient.h"

class Hospital {	//병원(메뉴) 
	static int i;
	static int a;
	static int rn;
	static string s;
	static string t;
	Treat T;
	vector<Doctor* > D;
	vector<Patient* > P;
public:
	Hospital();
	void Menu();  //메인메뉴  
	int MenuSelect();
	void HMenu(); //병원업무 메뉴
	int HMenuSelect();
	void DMenu(); //의사업무 메뉴
	int DMenuSelect(); 
	void TMenu(); //진료과목 메뉴 
	int TMenuSelect();
	void PMenu(); //환자업무 메뉴 
	int PMenuSelect();
	void DSave();
	void PSave();
	void Move(string TL,int code,int p);
};



#endif
