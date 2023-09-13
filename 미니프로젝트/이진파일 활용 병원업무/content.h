#ifndef CONTENT_H
#define CONTENT_H

#include "common.h"

class Content {
	string content;	//내용
	int Pnum;		//환자 핸드폰번호 
	string name;	//환자명
	int time;		//예약시간
	int num;		//예약번호
	bool state;		//진료 여부		
public:
	Content(string s,int a,string t,int tm,int rn,bool st);
	string getName() { return name; }
	int getPnum() { return Pnum; }
	int getNum() { return num; }
	int getTime() { return time; }
	string getContent() { return content; }
	bool getState() { return state; }
	void Complete() { state = true; }
	void View(int code);
};






#endif
