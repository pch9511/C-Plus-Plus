#include "customer.h"
#include "common.h"
#include "menu.h"

void Menu :: NewAccount() {
	try {
		cout << "회원 ID : ";
		cin >> ID;
		if(ID == "admin") throw ID; 
		for(int i=0; i<c.size(); i++) { 
			if(ID == c[i]->getID()) throw ID;	
		}
		try {
			cout << "주민등록번호 : ";
			cin >> RRN;
			for(int i=0; i<c.size(); i++) { 
				if(RRN == c[i]->getRRN()) throw "이미 가입된 주민등록번호 입니다.";	
			}
		}
		catch(const char* s){
			cout <<	s << endl;
			return; 
		}
	}
	catch (string s) {
		cout << ID << "은 이미 등록된 ID입니다." << endl;
		return; 
	}
	cout << "이름 : ";
	cin >> name;
	cout << "주소 : ";
	cin >> address;
	cout << "비밀번호 : ";
	cin >> PW;
	cout << "메일 : ";
	cin >> mail;
	cout << "휴대폰번호 : ";
	cin >> Pnum; 
	
	c.push_back(new Customer(ID,RRN,name,address,PW,mail,Pnum));
}

void Menu :: accountMenu() {
	while((i=accountSelect())!=3) {
		switch(i) {
			case 1:
			cout << "ID를 입력하세요 : ";
			cin >> ID;
			try{
				for(int i=0; i<c.size(); i++) {
					if(c[i]->getID() == ID) {
						c[i]->Show();	
						return;
					}
				}
				throw "해당 ID를 가진 회원이 존재하지 않습니다.";
			}
			catch(const char* s) {
				cout << s << endl;	
			}
			break;
			
			case 2: {
				cout << "ID를 입력하세요 : ";
				cin >> ID;
				vector<Customer* > :: iterator it = c.begin();
				try{
					while(it != c.end()) {
						Customer* t = *it;
						if(t->getID() == ID) {
							it = c.erase(it);
							cout << "삭제 완료!" << endl;
							return;
	 					}
						it++;
					}
					throw "해당 연락처를 가진 회원이 존재하지 않습니다."; 
				}
				catch(const char* s) {
					cout << s << endl;				
				}
			}
			break;
			
			default:
			SELERROR;
			break;
		}
	}
}	

void Menu :: productSearch() {
	while((i=nonmemberSelect())!=3) {
		switch(i) {
			case 1:	
			try {
				i = categorySearch();	//카테고리 선택 
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
				check = false;
				for(int j=0; j<p.size(); j++) {
					if((g[i]->getName() == p[j]->getCategory()) && (p[j]->getName() == name)) {
						cout << "<< 상품 정보 >>" << endl; 
						p[j]->Show();	
						check = true;
						price = j;
						break;
					}
				}
				if(check == false) throw "해당 카테고리에 없거나 존재하지 않는 상품명입니다."; 
				cout << "해당 상품을 장바구니에 담으시려면 'Y'를 입력해주세요 : ";
				cin >> RRN;
				if(RRN != "Y" ) throw "메뉴로 돌아갑니다.";
				cout << "구매 수량을 입력해주세요 : ";
				cin >> i;
				if(i < 0) throw "잘못된 수량을 입력하셨습니다."; 
				check = c[num]->basketEqual(name);
				if(!check) { 
					c[num]->BasketCreate(p[price],i);
					cout << "장바구니 담기 완료" << endl; 
				}
				else {
					cout << "해당 상품이 이미 존재하므로 수량이 증가됩니다." << endl;
					c[num]->BasketIn(name,i);		
				} 
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
				check =false;
				for(int j=0; j<p.size(); j++) {
					if(p[j]->getName() == name) {
						p[j]->Show();
						price = j;
						check = true;
						return;
					}
				}
				if(check == false) throw "해당하는 상품명이 없습니다."; 
				cout << "해당 상품을 장바구니에 담으시려면 'Y'를 입력해주세요 : ";
				cin >> RRN;
				if(RRN != "Y" ) throw "메뉴로 돌아갑니다.";
				cout << "구매 수량을 입력해주세요 : ";
				if(i < 0) throw "잘못된 수량을 입력하셨습니다."; 
				cin >> i;
				check = c[num]->basketEqual(name);
				if(!check) { 
					c[num]->BasketCreate(p[price],i);
					cout << "장바구니 담기 완료" << endl; 
				}
				else {
					cout << "해당 상품이 이미 존재하므로 수량이 증가됩니다." << endl;
					c[num]->BasketIn(name,i);		
				}
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

void Customer :: BasketDelete(string name) {
	vector<Basket* > :: iterator it = basket.begin();
	while(it != basket.end()) {
		Basket* t = *it;
		if(t->getName() == name) {
			it = basket.erase(it);
			return;		
		}
		it++;
	}
}

