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
	cout << "1.��ȸ��\n2.�α���\n3.ȸ������\n4.����\n>> ";
	cin >> i;
	return i;	
}

void Menu :: Login() {
	cout << "ID : ";
	cin >> ID;
	cout << "�н����� : ";
	cin >> PW;	
	if(ID == "admin" && PW == "999") {
		cout << "������ ���� �α��� ����!" << endl;	
		adminMenu();
		cout << "--�α׾ƿ�--" << endl;
		return;
	}
	try {
		for(int i=0; i<c.size(); i++) {
			if(ID == c[i]->getID() && PW == c[i]->getPW()) {
				cout << "�α��� ����!" << endl;	
				num = i;
				memberMenu();
				cout << "--�α׾ƿ�--" << endl;
				return; 
			}
		}
		throw "ID Ȥ�� PW�� �߸� �Է��ϼ̽��ϴ�."; 
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
						cout << "<< ������ ī�װ��� ��ϵ� ��ǰ ��� >>" << endl; 
						check = true;
						break;
					}
				}
				if(check == false) throw "�ش� ī�װ��� ��ǰ�� �����ϴ�.";
				for(int j=0; j<p.size(); j++) {
					if(g[i]->getName() == p[j]->getCategory()) cout << p[j]->getName() << endl;
				} 	
				cout << "��ȸ�� ��ǰ���� �Է��ϼ��� : ";
				cin >> name;
				for(int j=0; j<p.size(); j++) {
					if((g[i]->getName() == p[j]->getCategory()) && (p[j]->getName() == name)) {
						p[j]->Show();	
						return;
					}
				}
				throw "�ش� ī�װ��� ���ų� �������� �ʴ� ��ǰ���Դϴ�."; 
			}
			catch(const char* s) {
				cout << s << endl;
				return;
			}
			break;
			
			case 2:
			cout << "ã���ִ� ��ǰ���� �Է����ּ��� : ";
			cin >> name;
			try {	
				for(int i=0; i<p.size(); i++) {
					if(p[i]->getName() == name) {
						p[i]->Show();
						return;
					}
				}
				throw "�ش��ϴ� ��ǰ���� �����ϴ�."; 
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
	cout << "1.��ǰ ��ȸ\n2.��ǰ �˻�\n3.�ڷΰ���\n>>";
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
	cout << "1.��ǰ ��ȸ\n2.��ǰ �ֹ�\n3.�ֹ� ����\n4.��ٱ��� ��ǰ ���\n5.��ٱ��� ��ǰ ����\n6.ī�� ���\n7.�α׾ƿ�\n>>";
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
	cout << "1.��ǰ ����\n2.ȸ�� ����\n3.ī�װ� ����\n4.�α׾ƿ�\n>>";
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
	cout << "1.ī�װ� ���\n2.ī�װ� ����\n3.ī�װ� ����\n4.�ڷΰ���\n>>";
	cin >> i;
	return i; 
}


int Menu :: accountSelect() {
	cout << "1.ȸ�� ��ȸ\n2.ȸ�� ����\n3.�ڷΰ���\n>>";
	cin >> i;
	return i;	
}

int Menu :: productSelect() {
	cout << "1.��ǰ ���\n2.��ǰ ����\n3.��ǰ ����\n4.�ڷΰ���\n>>";
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
	cout << "1.�ſ�ī�� ����\n2.�¶��� �Ա�\n3.�ڷΰ���\n>>;";
	cin >>i;
	return i;
}


