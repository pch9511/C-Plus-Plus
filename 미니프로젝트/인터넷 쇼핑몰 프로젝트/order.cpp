#include "menu.h"
#include "order.h"

void Menu :: productOrder() {
	string* n;
	i = 0;
	try {
		check = c[num]->BasketList();
		if(check == false) throw "장바구니에 상품이 없습니다."; 
		while(1) {
			cout << "주문하고자 하는 상품명을 입력해주세요('주문'을 입력하면 주문시작) : ";
			n = new string;
			cin >> n[i];
			if(c[num]->basketEqual(n[i]) == false) {
				cout << "해당 상품명은 장바구니에 존재하지 않습니다." << endl; 
				continue;
			}
			if(n[i] == "주문") {
				i-=1;
				break;
			}
			i++;
		}
		if(i == -1) throw "선택한 상품이 없습니다."; 
		price = 0;
		for(int j=0; j<i+1; j++) {
			price+=c[num]->BasketShow(n[j]);	
		}
		cout << "주문 총액 : " << price << endl;
		cout << "<< 주문 정보 >>" << endl;
		cout << "수령인 이름 : ";
		getline(cin,name,'\n');
		cout << "배송지 주소 : ";
		getline(cin,address,'\n');
		cout << "배송지 연락처 : ";
		getline(cin,Pnum,'\n');
		if(name == "" | address == "" | Pnum == "") throw "입력되지 않은 주문 정보가 있습니다.";
		//회원 안에 주문이 들어가야함(그 회원의 주문 정보이기때문) 
		c[num]->OrderCreate(name,address,Pnum,price);
		
		for(int j=0; j<i+1; j++) {
			c[num]->BasketDelete(n[j]);	
		}
		cout << "주문한 상품들은 장바구니에서 삭제됩니다." << endl; 
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}
}
 
