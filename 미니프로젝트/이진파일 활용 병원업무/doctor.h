#ifndef DOCTOR_H
#define DOCTOR_H

#include "common.h"
#include "treat.h"
#include "content.h"

class Doctor : public Treat{	//의사 
	int code;				//식별가능한 번호 
	string time;			//시간대 
	string name; 			//이름 
	string TL; 				//진료과목 
	vector<Content* > C;	//진료내역 
public:
	Doctor(int i,string n,string t) { code = i; name = n; TL = t; time = "OOOOOOOO"; }
	Doctor(int i,string n,string t,string tm);
	void View();
	void TimeView();
	int getTimeView();
	void Mod(string n,string t) { name = n; TL = t; }
	int getCode() { return code; }
	string getName() { return name; }
	string getTL() { return TL; }
	string getTime() { return time; }
	bool RCheck(int t);
	bool OCheck(int t);
	void ContentIn(string s,int a,string t,int tm,int rn) {
		C.push_back(new Content(s,a,t,tm,rn,false)); 
		CSave();
	}
	void CSave();
	bool CView(int code);
	string CgetContent(int num);
	bool PCheck(int p,string n);
	void CErase();
};


#endif
