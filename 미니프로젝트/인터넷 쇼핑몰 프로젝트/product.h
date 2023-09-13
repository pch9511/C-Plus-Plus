#ifndef PRODUCT_H
#define PRODUCT_H
#include "common.h"

class Product {			//상품클래스
	string name;		//상품명 
	string info;		//상품설명 
	string jpeg;		//상품사진 경로 
//	ifstream fsrc;		//상품사진 
	int price;			//가격 
	string date;		//등록일자 
	string category;	//카테고리 
public:
	Product(string name = "",string info = "",string jpeg = "",int price = 0,string date = "",string category = "") {
		this->name = name; this->info = info; this->jpeg = jpeg; this->price = price; this->date = date; this->category = category;
		/*fsrc(this->jpeg, ios::in | ios::binary);
		if(!fsrc) {
		cout << srcFile << " 열기 오류" << endl;
		}*/
	}
	string getCategory() { return category; }
	string getName() { return name; }
	int getPrice() { return price; }
	void Show() { 
		cout << "상품명 : " << name << endl << "상품 사진 : " << jpeg << endl << "상품 설명 : " << info << endl 
		<< "가격 : " << price << endl << "등록일자 : " << date << endl << "--------------" << endl; }
	void Mod(string name,string info,string jpeg,int price,string date,string category) { 
		this->name = name; this->info = info; this->jpeg = jpeg; this->price = price; this->date = date; this->category = category;
	}
};


#endif			
