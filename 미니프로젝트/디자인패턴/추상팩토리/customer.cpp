#include "customer.h"
#include "menu.h"

Customer :: Customer(const Customer& c) {
	this->ID = c.ID;
	this->PW = c.PW;
	this->phoneNum = c.phoneNum;	
}

int Customer :: play(vector<Seat *> *S) {
	Set(S);
	int j;
	while((i=CtMenuSelect())!=6) {
		switch(i) {
			case 1:
			reservation(getPN());
			break;
			
			case 2:
			In(phoneNum);
			break;
			
			case 3:
			Out();
			break;	
			
			case 4:
			j = AccountDel(getPN());
			if(j == -1) {
				Get(&S);
				return j;
			}
			break;
			
			case 5:
			SState();
			break;
			
			default:
			SELERROR;
			break;
		}
	}
	Get(&S);
}


void Customer :: infoIn(string id,int pw,int pn) {
	ID = id; PW = pw; phoneNum = pn;	
}

void Customer :: show() {
	cout << "ID : " << ID << endl << "PW : " << PW << endl << "전화번호 : " << phoneNum << endl; 
}
