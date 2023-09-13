#ifndef CARDCOMPANY_H
#define CARDCOMPANY_H
#include "common.h"
#include "customer.h"

class Company {		//½ÂÀÎÈ¸»ç 
	bool CreateCheck;		//°¡ÀÔ½ÂÀÎÃ³¸®(true=½ÂÀÎ) 
	bool PayCheck;			//°áÁ¦½ÂÀÎÃ³¸® 
public:
	Company(bool CreateCheck = false,bool PayCheck = false) {
		this->CreateCheck = CreateCheck; this->PayCheck = PayCheck;
	}
	bool CardNumCheck(Customer* c,int CardNum) {
		if(c->NumCheck(CardNum)) return true;
		CreateCheck = true;
		return false;
	}
	bool CardPayCheck(Customer* c,string name,int CardNum,int date,int pw) {
		if(c->CardCheck(name,CardNum,date,pw)) return true;
		PayCheck = false;
		return false;
	}	
};






#endif



