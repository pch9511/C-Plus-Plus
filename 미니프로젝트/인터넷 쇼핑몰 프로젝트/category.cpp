#include "category.h"
#include "menu.h"

void Menu :: categoryCreate() {
	try {
		cout << "ī�װ��� : ";
		cin >> name;  
		for(int i=0; i<g.size(); i++) {
			if(g[i]->getName() == name) throw name;	
		}
	}
	catch(string s) {
		cout << name << "�� ī�װ����� �����մϴ�." << endl;
		return; 
	}
	cout << "1.�ֻ���\n2.����\n3.����\n>>";
	cin >> i;
	switch(i) {
		case 1:
		g.push_back(new Category(name,1));
		cout << "��� �Ϸ� !" << endl; 
		break;
		
		case 2:
		try {
			check = false;
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getLevel() == 1) check = true;
			}
			if(check == false) throw "�ֻ��� ī�װ��� ���� ������ �ֽʽÿ�."; 
		}
		catch(const char* s) {
			cout << s << endl;
			return;
		}
		cout << "<< �ֻ��� ī�װ� ����Ʈ >>" << endl; 
		for(int i=0; i<g.size(); i++) {
			if(g[i]->getLevel() == 1) {
				cout << g[i]->getName() << endl;
			}
		}
		cout << "��ӵ� ī�װ� ���� �Է��ϼ��� : ";
		cin >> ID;
		try {
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getName() == ID) {
					g.push_back(new Category(name,2,i));
					cout << "��� �Ϸ� !" << endl; 
					return;	
				}
			}
			throw ID; 
		}
		catch(string s) {
			cout << ID << "�� ��ϵ��� �ʾҰų� �ֻ��� ī�װ��� �ƴմϴ�." << endl;	
			return;
		}
		break;
		
		case 3:
		try {
			check = false;
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getLevel() == 2) check = true;
			}
			if(check == false) throw "���� ī�װ��� ���� ������ �ֽʽÿ�."; 
		}
		catch(const char* s) {
			cout << s << endl;
			return;
		}
		catch(const char* s) {
			cout << s << endl;
			return;
		}
		cout << "<< ���� ī�װ� ����Ʈ >> " << endl;
		for(int i=0; i<g.size(); i++) {
			if(g[i]->getLevel() == 2) {
				cout << g[i]->getName() << endl;
			}
		}
		cout << "��ӵ� ī�װ� ���� �Է��ϼ��� : ";
		cin >> ID;
		try {
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getName() == ID) {
					g.push_back(new Category(name,3,g[i]->getTop(),i));
					cout << "��� �Ϸ� !" << endl; 
					return;	
				}
			}
			throw ID; 
		}
		catch(string s) {
			cout << ID << "�� ��ϵ��� �ʾҰų� �ֻ��� ī�װ��� �ƴմϴ�." << endl;	
			return;
		}		 
		break;
		
		default:
		SELERROR;
		break;
	}
}

void Menu :: categoryMod() {
	cout << "�����ϰ��� �ϴ� ī�װ����� �Է����ּ��� : ";
	cin >> name;
	try {
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getName() == name) {
				cout << "ī�װ��� : ";
				cin >> name;
				for(int k=0; k<g.size(); k++) {
					if(g[k]->getName() == name) throw "�ߺ��� ī�װ����Դϴ�.";
				}
				cout << "1.�ֻ��� 2.���� 3.���� : ";
				cin >> i; 
				if(g[j]->getLevel() != i) { 
					for(int k=0; k<g.size(); k++) {
						if(g[k]->getTop() == j || g[k]->getMid() == j) throw "������ ī�װ��� �־� ���� �Ұ����մϴ�."; 
					}
				}
				g[j]->Mod(name,i);
				cout << "���� �Ϸ�!" << endl;
				return; 
			}
		}
		throw "�ش��ϴ� ī�װ����� �����ϴ�.";
	}
	catch(const char* s) {
		cout << s << endl;
		return;
	}
}

void Menu :: categoryDel() {
	cout << "�����ϰ��� �ϴ� ī�װ����� �Է����ּ��� : ";
	cin >> name;
	vector<Category* > :: iterator it = g.begin();
	try {
		while(it != g.end()){
			Category *t = *it;
			if(t->getName() == name) {
				it = g.erase(it);
				cout << "���� �Ϸ�!" << endl;
				return; 
			}
			it++;
		}
		throw name; 
	}
	catch(string s){
		cout << s << "�� �������� �ʴ� ī�װ����Դϴ�." << endl; 
		return;
	}
}

int Menu :: categorySearch() {
	try{															
		check = false;
		cout << "<< �ֻ��� ī�װ� >>" << endl; 
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getLevel() == 1) {
				cout << "No." << j << " -> " << g[j]->getName() << endl;
				check = true;
			}
		}
		if(check == false) throw "ī�װ��� ���� �����ؾ��մϴ�."; 
		check = false;
		cout << "��ȸ�ϰ��� �ϴ� ī�װ� ��ȣ�� �Է����ּ���. : ";
		cin >> i;
		cout << "<< ���� ī�װ� >>" << endl;
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getTop() == i && g[j]->getLevel() == 2) {
				cout << "No." << j << " -> " << g[j]->getName() << endl;
				check = true;
			}
		}
		if(check == false) throw "ī�װ��� ���ų� �߸��� ī�װ� ��ȣ�Դϴ�."; 	
		check = false;
		cout << "��ȸ�ϰ��� �ϴ� ī�װ� ��ȣ�� �Է����ּ���. : ";
		cin >> i;
		cout << "<< ���� ī�װ� >>" << endl;
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getMid() == i && g[j]->getLevel() == 3) {
				cout << "No." << j << " -> " << g[j]->getName() << endl;
				check = true;
			}
		}
		if(check == false) throw "ī�װ��� ���ų� �߸��� ī�װ� ��ȣ�Դϴ�."; 			
		cout << "��ǰ ��ȸ �� ī�װ� ��ȣ�� �Է����ּ���. : ";
		cin >> i;
		if(g[i]->getLevel() != 3) throw "���� ī�װ��� �ƴմϴ�."; 
		return i;
	}
	catch(const char *s) {
		cout << s << endl;
		return -1;
	}	
}
