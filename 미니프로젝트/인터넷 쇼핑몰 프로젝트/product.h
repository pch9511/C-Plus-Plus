#ifndef PRODUCT_H
#define PRODUCT_H
#include "common.h"

class Product {			//��ǰŬ����
	string name;		//��ǰ�� 
	string info;		//��ǰ���� 
	string jpeg;		//��ǰ���� ��� 
//	ifstream fsrc;		//��ǰ���� 
	int price;			//���� 
	string date;		//������� 
	string category;	//ī�װ� 
public:
	Product(string name = "",string info = "",string jpeg = "",int price = 0,string date = "",string category = "") {
		this->name = name; this->info = info; this->jpeg = jpeg; this->price = price; this->date = date; this->category = category;
		/*fsrc(this->jpeg, ios::in | ios::binary);
		if(!fsrc) {
		cout << srcFile << " ���� ����" << endl;
		}*/
	}
	string getCategory() { return category; }
	string getName() { return name; }
	int getPrice() { return price; }
	void Show() { 
		cout << "��ǰ�� : " << name << endl << "��ǰ ���� : " << jpeg << endl << "��ǰ ���� : " << info << endl 
		<< "���� : " << price << endl << "������� : " << date << endl << "--------------" << endl; }
	void Mod(string name,string info,string jpeg,int price,string date,string category) { 
		this->name = name; this->info = info; this->jpeg = jpeg; this->price = price; this->date = date; this->category = category;
	}
};


#endif			
