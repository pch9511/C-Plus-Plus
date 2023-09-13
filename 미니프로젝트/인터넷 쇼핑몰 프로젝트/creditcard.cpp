#include "creditcard.h"
#include "cardcompany.h"
#include "menu.h"

void Menu :: CardCreate() { 
	try {
		cout << "<< 카드 생성 >>" << endl;
		cout << "카드사를 선택해주세요." << endl;
		cout << "1. KB 2. SH" << endl;
		cin >> i;
		cout << "카드번호를 입력해주세요 : ";
		cin >> price;		//카드회사에 인증요청 -> 회원의 카드번호를 읽어냄 -> 중복이 없다면 승인 ( 프렌드 선언해서 만들면 가능) 
		for(int j=0; j<c.size(); j++) {
			if(company.CardNumCheck(c[j],price)) throw "이미 존재하는 카드번호입니다."; 
		}
		int pw,date,pay; 
		cout << "카드비밀번호를 입력해주세요 : ";
		cin >> pw;
		cout << "유효 기간을 입력해주세요 : ";
		cin >> date;
		cout << "이용 한도를 입력해주세요 : ";
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
		cout << "카드 생성 완료" << endl;
	}
	catch(const char* s) {
		cout << s << endl;
		return;
	}
}

void Menu :: CardPay() {
	try {
		cout << "결제할 신용카드 정보를 입력하세요." << endl;
		cout << "신용카드사 : ";
		cin >> name;
		cout << "신용카드 번호 : ";
		cin >> i; 
		cout << "유효기간 : ";
		cin >> price;
		int pw,date;
		cout << "비밀번호 : ";
		cin >> pw;
		cout << "할부기간 : ";
		cin >> date;
		for(int j=0; j<c.size(); j++) {
			if(company.CardPayCheck(c[j],name,i,price,pw)) throw "이미 존재하는 카드번호입니다."; 
		}
		if(c[num]->CardCheck(name,i,price,pw) == false) throw "입력한 카드는 존재하지않습니다.";
		
	}
	catch(const char* s) {
		cout << s << endl;	
	}
}
