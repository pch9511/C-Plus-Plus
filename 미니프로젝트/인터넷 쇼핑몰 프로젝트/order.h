#ifndef ORDER_H
#define ORDER_H
#include "common.h"

class Order {
	int Num;		//�ֹ���ȣ 
	string Date;	//�ֹ����� 
	string name;	//������ �̸� 
	string address;	//������ּ� 
	string Pnum;	//����� ��ȭ��ȣ 
	int totalSum; 	//�ֹ��Ѿ� 
public:
	Order(string name = "",string address = "",string Pnum = "",int totalSum = 0) {
		this->name = name; this->address = address; this->Pnum = Pnum; this->totalSum = totalSum; this->Date = "";
		time_t timer = time(NULL);
		struct tm* t = localtime(&timer);
		char a[20];
		char b[20];
		char c[20];
		itoa(t->tm_year+1900,a,10); itoa(t->tm_mon+1,b,10); itoa(t->tm_mday,c,10);
		Date += a; Date += "-"; Date += b; Date += "-"; Date += c;
		this->Num = cnt; cnt ++;
	}
};


#endif
