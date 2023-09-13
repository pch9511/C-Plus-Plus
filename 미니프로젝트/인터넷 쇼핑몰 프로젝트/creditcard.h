#ifndef CREDITCARD_H
#define CREDITCARD_H
#include "common.h"

class CreditCard {
	string company;	 //카드사 
	int CardNum;	 //카드번호 
	int PW;			 //카드 비밀번호
	int date;		 //유효 기간 
	int pay;		 //이용 한도 
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

