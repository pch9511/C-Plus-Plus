#include "menu.h"
#include "customer.h"

int mainMenuSelect() {
	cout << "1.ȸ������\n2.�α���\n3.����\n>>";
	cin >> i;
	return i;	
}

void Create(const vector<Customer* > c, Customer *tc) {
	string id;
	int pw,pn;
	try{
		cout << "<< ȸ�� ���� >>" << endl;
		cout << "ID : ";
		cin >> id;
		for(int i=0; i<c.size(); i++) {
			if(c[i]->getID() == id) throw "�̹� �����ϴ� ID�Դϴ�.";		
		}
		cout << "PW : ";
		cin >> pw;
		cout << "��ȭ��ȣ : ";
		cin >> pn;
		for(int i=0; i<c.size(); i++) {
			if(c[i]->getPN() == pn) throw "�̹� �����ϴ� ��ȭ��ȣ�Դϴ�."; 
		}
		tc->infoIn(id,pw,pn);
		cout << "ȸ������ ����!" << endl; 
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
		cout << "<< �α��� >>" << endl; 
		cout << "ID : ";
		cin >> id;	
		cout << "PW : ";
		cin >> pw;
		if(id == "admin" && pw == 999) {
			cout << "�����ڽ���" << endl; 
			return -1;
		}
		for(int i=0; i<c.size(); i++) {
			if(c[i]->getID() == id && c[i]->getPW() == pw) {
				cout << c[i]->getID() << "�� �α��� ����! " << endl;
				return i;
			}
		}	
		throw "�α��� ����!"; 
	}
	catch(const char* s) {
		cout << s << endl;	
		return -2;
	}
}

int AdMenuSelect() {
	cout << "1.�¼���ġ\n2.���� ����\n3.�¼� ��Ȳ\n4.�ð�ǥ ����\n5.����\n6.�α� �ƿ�\n>>";
	cin >> i;	
	return i;
}

int CtMenuSelect() {
	cout << "1.����\n2.����\n3.����\n4.ȸ��Ż��\n5.�¼� ��Ȳ\n6.�α� �ƿ�\n>>";
	cin >> i;
	return i;	
}

