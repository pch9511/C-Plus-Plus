#include "basket.h"
#include "menu.h"

void Menu :: BasketDelete() {	
	try {
		check =c[num]->BasketList();	
		if(check == false) throw "��ٱ��Ͽ� ��ǰ�� �����ϴ�.";
		cout << "��ٱ��Ͽ��� ������ ��ǰ���� �Է��ϼ���";
		cin >> name;
		if(c[num]->basketEqual(name)==false) throw "�ش� ��ǰ���� ��ٱ��Ͽ� �����ϴ�";
		c[num]->BasketDelete(name);
		cout << "��ٱ��Ͽ��� �ش� ��ǰ�� �����߽��ϴ�.";
	}
	catch(const char* s) {
		cout << s << endl;
	}
}
 
