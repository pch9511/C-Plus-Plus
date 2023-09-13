#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "common.h"
#include "basket.h"
#include "product.h"
#include "order.h" 
#include "creditcard.h" 

class Customer {	//ȸ�� Ŭ����
	string ID;					//ID
	string RRN;					//�ֹε�Ϲ�ȣ 
	string name;				//�̸� 
	string address;				//�ּ� 
	string PW;					//�н����� 
	string mail;				//�����ּ� 
	string Pnum;				//��ȭ��ȣ 
	vector<Basket* > basket;	//��ٱ���  
	vector<Order* > order;		//�ֹ� 
	vector<CreditCard* > credit;//�ſ�ī�� 
public:	
	Customer(string ID = "",string RRN = "",string name = "",string address = "",string PW = "",string mail = "",string Pnum ="")  {
		this->ID = ID; this->RRN = RRN; this->name = name; this->address = address; this->PW = PW; this->mail = mail; this->Pnum = Pnum;
	}
	string getID() { return ID; }	//ID �޾ƿ��� 
	string getRRN() { return RRN; }	//�ֹι�ȣ �޾ƿ��� 
	string getPW() { return PW; } 	//PW �޾ƿ��� 
	string getPnum() { return Pnum; }

	void Show() { 
		cout << "ID : " << ID << endl << "�̸� : " << name << endl << "�ּ� : " << address << endl
		<< "�����ּ� : " << mail << endl << "��ȭ��ȣ : " << Pnum << endl;
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
			if(cnt == 0) cout << "<< ��ٱ��� ��� >>" << endl;
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
