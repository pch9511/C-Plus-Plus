#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "common.h"
#include "treat.h"
#include "doctor.h" 
#include "patient.h"

class Hospital {	//����(�޴�) 
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
	void Menu();  //���θ޴�  
	int MenuSelect();
	void HMenu(); //�������� �޴�
	int HMenuSelect();
	void DMenu(); //�ǻ���� �޴�
	int DMenuSelect(); 
	void TMenu(); //������� �޴� 
	int TMenuSelect();
	void PMenu(); //ȯ�ھ��� �޴� 
	int PMenuSelect();
	void DSave();
	void PSave();
	void Move(string TL,int code,int p);
};



#endif
