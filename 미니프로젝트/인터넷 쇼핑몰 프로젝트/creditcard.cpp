#include "creditcard.h"
#include "cardcompany.h"
#include "menu.h"

void Menu :: CardCreate() { 
	try {
		cout << "<< ī�� ���� >>" << endl;
		cout << "ī��縦 �������ּ���." << endl;
		cout << "1. KB 2. SH" << endl;
		cin >> i;
		cout << "ī���ȣ�� �Է����ּ��� : ";
		cin >> price;		//ī��ȸ�翡 ������û -> ȸ���� ī���ȣ�� �о -> �ߺ��� ���ٸ� ���� ( ������ �����ؼ� ����� ����) 
		for(int j=0; j<c.size(); j++) {
			if(company.CardNumCheck(c[j],price)) throw "�̹� �����ϴ� ī���ȣ�Դϴ�."; 
		}
		int pw,date,pay; 
		cout << "ī���й�ȣ�� �Է����ּ��� : ";
		cin >> pw;
		cout << "��ȿ �Ⱓ�� �Է����ּ��� : ";
		cin >> date;
		cout << "�̿� �ѵ��� �Է����ּ��� : ";
		cin >> pay;
		switch(i) {
			case 1:
			c[num]->CardIn(i,price,pw,date,pay);	
			break;
			
			case 2:
			c[num]->CardIn(i,price,pw,date,pay);	
			break;
			
			default:
			SELERROR;
			break;
		}
		cout << "ī�� ���� �Ϸ�" << endl;
	}
	catch(const char* s) {
		cout << s << endl;
		return;
	}
}

void Menu :: CardPay() {
	try {
		cout << "������ �ſ�ī�� ������ �Է��ϼ���." << endl;
		cout << "�ſ�ī��� : ";
		cin >> name;
		cout << "�ſ�ī�� ��ȣ : ";
		cin >> i; 
		cout << "��ȿ�Ⱓ : ";
		cin >> price;
		int pw,date;
		cout << "��й�ȣ : ";
		cin >> pw;
		cout << "�ҺαⰣ : ";
		cin >> date;
		for(int j=0; j<c.size(); j++) {
			if(company.CardPayCheck(c[j],name,i,price,pw)) throw "�̹� �����ϴ� ī���ȣ�Դϴ�."; 
		}
		if(c[num]->CardCheck(name,i,price,pw) == false) throw "�Է��� ī��� ���������ʽ��ϴ�.";
		
	}
	catch(const char* s) {
		cout << s << endl;	
	}
}
