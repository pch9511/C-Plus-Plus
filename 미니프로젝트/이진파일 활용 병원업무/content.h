#ifndef CONTENT_H
#define CONTENT_H

#include "common.h"

class Content {
	string content;	//����
	int Pnum;		//ȯ�� �ڵ�����ȣ 
	string name;	//ȯ�ڸ�
	int time;		//����ð�
	int num;		//�����ȣ
	bool state;		//���� ����		
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
