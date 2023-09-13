#include "basket.h"
#include "menu.h"

void Menu :: BasketDelete() {	
	try {
		check =c[num]->BasketList();	
		if(check == false) throw "장바구니에 상품이 없습니다.";
		cout << "장바구니에서 삭제할 상품명을 입력하세요";
		cin >> name;
		if(c[num]->basketEqual(name)==false) throw "해당 상품명은 장바구니에 없습니다";
		c[num]->BasketDelete(name);
		cout << "장바구니에서 해당 상품을 삭제했습니다.";
	}
	catch(const char* s) {
		cout << s << endl;
	}
}
 
