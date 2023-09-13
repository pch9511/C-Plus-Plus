#ifndef BASKET_H
#define BASKET_H
#include "common.h"

class Basket {
	string name;	//상품명 
	int amount;		//수량 
	int price;		//가격
public:	
	Basket(string name = "",int amount = 0,int price = 0) {
		this->name = name; this->amount = amount; this->price = price;
	}
	int Show() {
		cout << "상품명 : " << name << endl << "가격 : " << price << endl << "수량 : " << amount << endl << "금액 : " << amount*price << endl;	
		return amount*price;
	}
	string getName() { return name; }
	void Sum(int amount) { this->amount += amount; }  
};


#endif
