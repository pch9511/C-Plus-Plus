#include "customer.h"
#include "common.h"
#include "menu.h"

void Menu :: NewAccount() {
	try {
		cout << "ȸ�� ID : ";
		cin >> ID;
		if(ID == "admin") throw ID; 
		for(int i=0; i<c.size(); i++) { 
			if(ID == c[i]->getID()) throw ID;	
		}
		try {
			cout << "�ֹε�Ϲ�ȣ : ";
			cin >> RRN;
			for(int i=0; i<c.size(); i++) { 
				if(RRN == c[i]->getRRN()) throw "�̹� ���Ե� �ֹε�Ϲ�ȣ �Դϴ�.";	
			}
		}
		catch(const char* s){
			cout <<	s << endl;
			return; 
		}
	}
	catch (string s) {
		cout << ID << "�� �̹� ��ϵ� ID�Դϴ�." << endl;
		return; 
	}
	cout << "�̸� : ";
	cin >> name;
	cout << "�ּ� : ";
	cin >> address;
	cout << "��й�ȣ : ";
	cin >> PW;
	cout << "���� : ";
	cin >> mail;
	cout << "�޴�����ȣ : ";
	cin >> Pnum; 
	
	c.push_back(new Customer(ID,RRN,name,address,PW,mail,Pnum));
}

void Menu :: accountMenu() {
	while((i=accountSelect())!=3) {
		switch(i) {
			case 1:
			cout << "ID�� �Է��ϼ��� : ";
			cin >> ID;
			try{
				for(int i=0; i<c.size(); i++) {
					if(c[i]->getID() == ID) {
						c[i]->Show();	
						return;
					}
				}
				throw "�ش� ID�� ���� ȸ���� �������� �ʽ��ϴ�.";
			}
			catch(const char* s) {
				cout << s << endl;	
			}
			break;
			
			case 2: {
				cout << "ID�� �Է��ϼ��� : ";
				cin >> ID;
				vector<Customer* > :: iterator it = c.begin();
				try{
					while(it != c.end()) {
						Customer* t = *it;
						if(t->getID() == ID) {
							it = c.erase(it);
							cout << "���� �Ϸ�!" << endl;
							return;
	 					}
						it++;
					}
					throw "�ش� ����ó�� ���� ȸ���� �������� �ʽ��ϴ�."; 
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
				i = categorySearch();	//ī�װ� ���� 
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
				check = false;
				for(int j=0; j<p.size(); j++) {
					if((g[i]->getName() == p[j]->getCategory()) && (p[j]->getName() == name)) {
						cout << "<< ��ǰ ���� >>" << endl; 
						p[j]->Show();	
						check = true;
						price = j;
						break;
					}
				}
				if(check == false) throw "�ش� ī�װ��� ���ų� �������� �ʴ� ��ǰ���Դϴ�."; 
				cout << "�ش� ��ǰ�� ��ٱ��Ͽ� �����÷��� 'Y'�� �Է����ּ��� : ";
				cin >> RRN;
				if(RRN != "Y" ) throw "�޴��� ���ư��ϴ�.";
				cout << "���� ������ �Է����ּ��� : ";
				cin >> i;
				if(i < 0) throw "�߸��� ������ �Է��ϼ̽��ϴ�."; 
				check = c[num]->basketEqual(name);
				if(!check) { 
					c[num]->BasketCreate(p[price],i);
					cout << "��ٱ��� ��� �Ϸ�" << endl; 
				}
				else {
					cout << "�ش� ��ǰ�� �̹� �����ϹǷ� ������ �����˴ϴ�." << endl;
					c[num]->BasketIn(name,i);		
				} 
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
				check =false;
				for(int j=0; j<p.size(); j++) {
					if(p[j]->getName() == name) {
						p[j]->Show();
						price = j;
						check = true;
						return;
					}
				}
				if(check == false) throw "�ش��ϴ� ��ǰ���� �����ϴ�."; 
				cout << "�ش� ��ǰ�� ��ٱ��Ͽ� �����÷��� 'Y'�� �Է����ּ��� : ";
				cin >> RRN;
				if(RRN != "Y" ) throw "�޴��� ���ư��ϴ�.";
				cout << "���� ������ �Է����ּ��� : ";
				if(i < 0) throw "�߸��� ������ �Է��ϼ̽��ϴ�."; 
				cin >> i;
				check = c[num]->basketEqual(name);
				if(!check) { 
					c[num]->BasketCreate(p[price],i);
					cout << "��ٱ��� ��� �Ϸ�" << endl; 
				}
				else {
					cout << "�ش� ��ǰ�� �̹� �����ϹǷ� ������ �����˴ϴ�." << endl;
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

