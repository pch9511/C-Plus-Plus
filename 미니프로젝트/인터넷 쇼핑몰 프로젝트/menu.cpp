#include "menu.h"

int Menu :: i = 0;
int Menu :: price = 0;
int Menu :: num = 0;
string Menu :: ID = "";		
string Menu :: RRN = "";		
string Menu :: name = "";
string Menu :: address = "";	
string Menu :: PW = "";		
string Menu :: mail = "";	 
string Menu :: Pnum = "";
bool Menu :: check = false;

void Menu :: menu() {
	while((i=MenuSelect())!=4) {
		switch(i) {
			case 1:
			nonmemberMenu();
			break;
			
			case 2:
			Login();
			break;
			
			case 3:
			NewAccount();
			break;
			
			default:
			SELERROR;
			break;
		}
	}
	
}
int Menu :: MenuSelect() {
	cout << "1.비회원\n2.로그인\n3.회원가입\n4.종료\n>> ";
	cin >> i;
	return i;	
}

void Menu :: Login() {
	cout << "ID : ";
	cin >> ID;
	cout << "패스워드 : ";
	cin >> PW;	
	if(ID == "admin" && PW == "999") {
		cout << "관리자 계정 로그인 성공!" << endl;	
		adminMenu();
		cout << "--로그아웃--" << endl;
		return;
	}
	try {
		for(int i=0; i<c.size(); i++) {
			if(ID == c[i]->getID() && PW == c[i]->getPW()) {
				cout << "로그인 성공!" << endl;	
				num = i;
				memberMenu();
				cout << "--로그아웃--" << endl;
				return; 
			}
		}
		throw "ID 혹은 PW를 잘못 입력하셨습니다."; 
	}
	catch(const char* s) {
		cout << s << endl;
		return;
	}
}

void Menu :: nonmemberMenu() {
	while((i=nonmemberSelect())!=3) {
		switch(i) {
			case 1:
			try {
				i=categorySearch();				
				if(i == -1) throw "";
				check = false;		
				for(int j=0; j<p.size(); j++) {
					if(g[i]->getName() == p[j]->getCategory()) {
						cout << "<< 선택한 카테고리에 등록된 상품 목록 >>" << endl; 
						check = true;
						break;
					}
				}
				if(check == false) throw "해당 카테고리에 상품이 없습니다.";
				for(int j=0; j<p.size(); j++) {
					if(g[i]->getName() == p[j]->getCategory()) cout << p[j]->getName() << endl;
				} 	
				cout << "조회할 상품명을 입력하세요 : ";
				cin >> name;
				for(int j=0; j<p.size(); j++) {
					if((g[i]->getName() == p[j]->getCategory()) && (p[j]->getName() == name)) {
						p[j]->Show();	
						return;
					}
				}
				throw "해당 카테고리에 없거나 존재하지 않는 상품명입니다."; 
			}
			catch(const char* s) {
				cout << s << endl;
				return;
			}
			break;
			
			case 2:
			cout << "찾고있는 상품명을 입력해주세요 : ";
			cin >> name;
			try {	
				for(int i=0; i<p.size(); i++) {
					if(p[i]->getName() == name) {
						p[i]->Show();
						return;
					}
				}
				throw "해당하는 상품명이 없습니다."; 
			}
			catch(const char* s) {
				cout << s<< endl;
				return;	
			}
			break;
			
			default:
			SELERROR;
			break;	
		}
	}
}

int Menu :: nonmemberSelect() {
	cout << "1.상품 조회\n2.상품 검색\n3.뒤로가기\n>>";
	cin >> i;
	return i; 
}	

void Menu :: memberMenu() {
	while((i=memberSelect())!=7) {
		switch(i) {
			case 1:
			productSearch();	
			break;
			
			case 2:
			productOrder();	
			break;
			
			case 3:
			OrderPay();
			break;
			
			case 4:
			productSearch();	
			break;
			
			case 5:
			BasketDelete();
			break;
			
			case 6:
			CardCreate();	
			break;	
			 
			default:
			SELERROR;
			break;
		}
	}
}

int Menu :: memberSelect() {
	cout << "1.상품 조회\n2.상품 주문\n3.주문 결제\n4.장바구니 상품 담기\n5.장바구니 상품 삭제\n6.카드 등록\n7.로그아웃\n>>";
	cin >> i;
	return i;	
}

void Menu :: adminMenu() {
	while((i=adminSelect())!=4) {
		switch(i) {
			case 1:
			productMenu();
			break;
			
			case 2:
			accountMenu();	
			break;
			
			case 3:
			categoryMenu();
			break;
			
			default:
			SELERROR;
			break;
		}
	}
}

int Menu :: adminSelect() {
	cout << "1.상품 관리\n2.회원 관리\n3.카테고리 관리\n4.로그아웃\n>>";
	cin >> i;	
	return i;
}

void Menu :: categoryMenu() {
	while((i=categorySelect())!=4) {
		switch(i) {
			case 1:
			categoryCreate();
			break;
			
			case 2:
			categoryMod();
			break;
			
			case 3:
			categoryDel();
			break;
			
			default:
			SELERROR;
			break;	
		}
	}
}

int Menu :: categorySelect() {
	cout << "1.카테고리 등록\n2.카테고리 수정\n3.카테고리 삭제\n4.뒤로가기\n>>";
	cin >> i;
	return i; 
}


int Menu :: accountSelect() {
	cout << "1.회원 조회\n2.회원 삭제\n3.뒤로가기\n>>";
	cin >> i;
	return i;	
}

int Menu :: productSelect() {
	cout << "1.상품 등록\n2.상품 수정\n3.상품 삭제\n4.뒤로가기\n>>";
	cin >> i;
	return i;	
}

void Menu :: OrderPay() {
	
	while((i=OrderPaySelect())!=3) {
		switch(i) {
			case 1:
			CardPay();
			break;
			
			case 2:
			//OnlinePay();	
			break;
			
			default:
			SELERROR;
			break;
		}
	}
}

int Menu :: OrderPaySelect() {
	cout << "1.신용카드 결제\n2.온라인 입금\n3.뒤로가기\n>>;";
	cin >>i;
	return i;
}


