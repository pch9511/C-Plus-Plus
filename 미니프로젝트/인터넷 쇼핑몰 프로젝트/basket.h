#ifndef BASKET_H
#define BASKET_H
#include "common.h"

class Basket {
	string name;	//��ǰ�� 
	int amount;		//���� 
	int price;		//����
public:	
	Basket(string name = "",int amount = 0,int price = 0) {
		this->name = name; this->amount = amount; this->price = price;
	}
	int Show() {
		cout << "��ǰ�� : " << name << endl << "���� : " << price << endl << "���� : " << amount << endl << "�ݾ� : " << amount*price << endl;	
		return amount*price;
	}
	string getName() { return name; }
	void Sum(int amount) { this->amount += amount; }  
};


#endif
