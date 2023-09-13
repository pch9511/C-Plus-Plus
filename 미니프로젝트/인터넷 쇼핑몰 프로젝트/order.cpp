#include "menu.h"
#include "order.h"

void Menu :: productOrder() {
	string* n;
	i = 0;
	try {
		check = c[num]->BasketList();
		if(check == false) throw "��ٱ��Ͽ� ��ǰ�� �����ϴ�."; 
		while(1) {
			cout << "�ֹ��ϰ��� �ϴ� ��ǰ���� �Է����ּ���('�ֹ�'�� �Է��ϸ� �ֹ�����) : ";
			n = new string;
			cin >> n[i];
			if(c[num]->basketEqual(n[i]) == false) {
				cout << "�ش� ��ǰ���� ��ٱ��Ͽ� �������� �ʽ��ϴ�." << endl; 
				continue;
			}
			if(n[i] == "�ֹ�") {
				i-=1;
				break;
			}
			i++;
		}
		if(i == -1) throw "������ ��ǰ�� �����ϴ�."; 
		price = 0;
		for(int j=0; j<i+1; j++) {
			price+=c[num]->BasketShow(n[j]);	
		}
		cout << "�ֹ� �Ѿ� : " << price << endl;
		cout << "<< �ֹ� ���� >>" << endl;
		cout << "������ �̸� : ";
		getline(cin,name,'\n');
		cout << "����� �ּ� : ";
		getline(cin,address,'\n');
		cout << "����� ����ó : ";
		getline(cin,Pnum,'\n');
		if(name == "" | address == "" | Pnum == "") throw "�Էµ��� ���� �ֹ� ������ �ֽ��ϴ�.";
		//ȸ�� �ȿ� �ֹ��� ������(�� ȸ���� �ֹ� �����̱⶧��) 
		c[num]->OrderCreate(name,address,Pnum,price);
		
		for(int j=0; j<i+1; j++) {
			c[num]->BasketDelete(n[j]);	
		}
		cout << "�ֹ��� ��ǰ���� ��ٱ��Ͽ��� �����˴ϴ�." << endl; 
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}
}
 
