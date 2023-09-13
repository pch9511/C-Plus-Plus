#ifndef CREDITCARD_H
#define CREDITCARD_H
#include "common.h"

class CreditCard {
	string company;	 //ī��� 
	int CardNum;	 //ī���ȣ 
	int PW;			 //ī�� ��й�ȣ
	int date;		 //��ȿ �Ⱓ 
	int pay;		 //�̿� �ѵ� 
public:
	CreditCard(string company = "",int CardNum = 0,int PW = 0,int date = 0,int pay = 0) {
		this->company = company; this->CardNum = CardNum; this->PW = PW; this->date = date; this->pay = pay;
	}
	string getCompany() { return company; }
	int getCardNum() { return CardNum; }
	int getPW() { return PW; }
	int getDate() { return date; }
};

class KB : public CreditCard {
public:
	KB(string company = "KB", int CardNum = 0,int PW = 0,int date = 0,int pay = 0) : CreditCard(company,CardNum,PW,date,pay) {}	
};

class SH : public CreditCard {
public:
	SH(string company = "SH", int CardNum = 0,int PW = 0,int date = 0,int pay = 0) : CreditCard(company,CardNum,PW,date,pay) {}		
};



#endif

