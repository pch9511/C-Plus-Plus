#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "common.h"
#include "basket.h"
#include "product.h"
#include "order.h" 
#include "creditcard.h" 

class Customer {	//회원 클래스
	string ID;					//ID
	string RRN;					//주민등록번호 
	string name;				//이름 
	string address;				//주소 
	string PW;					//패스워드 
	string mail;				//메일주소 
	string Pnum;				//전화번호 
	vector<Basket* > basket;	//장바구니  
	vector<Order* > order;		//주문 
	vector<CreditCard* > credit;//신용카드 
public:	
	Customer(string ID = "",string RRN = "",string name = "",string address = "",string PW = "",string mail = "",string Pnum ="")  {
		this->ID = ID; this->RRN = RRN; this->name = name; this->address = address; this->PW = PW; this->mail = mail; this->Pnum = Pnum;
	}
	string getID() { return ID; }	//ID 받아오기 
	string getRRN() { return RRN; }	//주민번호 받아오기 
	string getPW() { return PW; } 	//PW 받아오기 
	string getPnum() { return Pnum; }

	void Show() { 
		cout << "ID : " << ID << endl << "이름 : " << name << endl << "주소 : " << address << endl
		<< "메일주소 : " << mail << endl << "전화번호 : " << Pnum << endl;
	}
	bool basketEqual(string name) {
		for(int i=0; i<basket.size(); i++) {
			if(name == basket[i]->getName()) return true;	
		}
		return false;
	}
	void BasketCreate(Product *p,int amount) {
		basket.push_back(new Basket(p->getName(),amount,p->getPrice()));
	}
	void BasketIn(string name,int amount) {
		for(int i=0; i<basket.size(); i++) {
			if(name == basket[i]->getName()) basket[i]->Sum(amount);
		}		
	}
	bool BasketList() {
		bool check = false;
		int cnt = 0;
		for(int i=0; i<basket.size(); i++) {
			if(cnt == 0) cout << "<< 장바구니 목록 >>" << endl;
			basket[i]->Show();
			check = true;
			cnt++;
		}
		return check;
	}
	int BasketShow(string name) {
		int sum = 0;
		for(int i=0; i<basket.size(); i++) {
			if(basket[i]->getName() == name) return basket[i]->Show();
		}
	}
	void OrderCreate(string name,string address,string Pnum,int totalSum) { order.push_back(new Order(name,address,Pnum,totalSum));}
	void BasketDelete(string name);
	void CardIn(int company,int price,int pw,int date,int pay) {
		switch(company) {
			case 1:
			credit.push_back(new KB("KB",price,pw,date,pay));
			break;
			
			case 2:
			credit.push_back(new KB("SH",price,pw,date,pay));	
			break;
		}
	}
	bool NumCheck(int CardNum) {
		for(int i=0; i<credit.size(); i++) {
			if(credit[i]->getCardNum() == CardNum) return true;
		}
		return false;			
	}
	bool CardCheck(string name,int CardNum,int date,int pw) {
		for(int i=0; i<credit.size(); i++) {
			if(credit[i]->getCompany() == name && credit[i]->getCardNum() == CardNum && credit[i]->getDate() == date && credit[i]->getPW() == pw) 
				return true;
		}
		return false;
	}
};



#endif
