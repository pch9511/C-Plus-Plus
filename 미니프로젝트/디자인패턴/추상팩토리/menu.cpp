#include "menu.h"
#include "customer.h"

int mainMenuSelect() {
	cout << "1.회원가입\n2.로그인\n3.종료\n>>";
	cin >> i;
	return i;	
}

void Create(const vector<Customer* > c, Customer *tc) {
	string id;
	int pw,pn;
	try{
		cout << "<< 회원 가입 >>" << endl;
		cout << "ID : ";
		cin >> id;
		for(int i=0; i<c.size(); i++) {
			if(c[i]->getID() == id) throw "이미 존재하는 ID입니다.";		
		}
		cout << "PW : ";
		cin >> pw;
		cout << "전화번호 : ";
		cin >> pn;
		for(int i=0; i<c.size(); i++) {
			if(c[i]->getPN() == pn) throw "이미 존재하는 전화번호입니다."; 
		}
		tc->infoIn(id,pw,pn);
		cout << "회원가입 성공!" << endl; 
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}
}

int Login(const vector<Customer* > c) {
	string id;
	int pw;	
	try {
		cout << "<< 로그인 >>" << endl; 
		cout << "ID : ";
		cin >> id;	
		cout << "PW : ";
		cin >> pw;
		if(id == "admin" && pw == 999) {
			cout << "관리자실행" << endl; 
			return -1;
		}
		for(int i=0; i<c.size(); i++) {
			if(c[i]->getID() == id && c[i]->getPW() == pw) {
				cout << c[i]->getID() << "님 로그인 성공! " << endl;
				return i;
			}
		}	
		throw "로그인 실패!"; 
	}
	catch(const char* s) {
		cout << s << endl;	
		return -2;
	}
}

int AdMenuSelect() {
	cout << "1.좌석배치\n2.예약 내역\n3.좌석 현황\n4.시간표 설정\n5.정산\n6.로그 아웃\n>>";
	cin >> i;	
	return i;
}

int CtMenuSelect() {
	cout << "1.예약\n2.입장\n3.퇴장\n4.회원탈퇴\n5.좌석 현황\n6.로그 아웃\n>>";
	cin >> i;
	return i;	
}

