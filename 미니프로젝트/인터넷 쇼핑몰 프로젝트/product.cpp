#include "menu.h"
#include "product.h"

void Menu :: productMenu() {
	while((i=productSelect())!=4) {
		switch(i) {
			case 1:
			try{															
				i = categorySearch();	//ī�װ� ���� 
				if(i == -1) throw "";
				cout << " << ��ǰ ��� >> " << endl;	// ��ǰ ��� 
				while(1) {
					cout << "��ǰ�� : ";				
					cin >> name;
					check = false;
					for(int j=0; j<p.size(); j++) {
						if(p[j]->getName() == name) {
							cout << "��ǰ���� �̹� �����մϴ�." << endl;	
							check = true;
							break;
						}
					}
					if(check != true) break;
				}
			}
			catch(const char *s) {
				cout << s << endl;
				return;
			}
			cout << "���� : " ;
			cin >> price;
			cout << "��ǰ ���� : ";
			cin >> address; 
			cout << "��ǰ ���� : ";
			cin >> mail; 
			cout << "��� ���� : ";
			cin >> PW;
			p.push_back(new Product(name,mail,address,price,PW,g[i]->getName())); 
			cout << "��ǰ ��� �Ϸ�!" << endl; 
			cout << "<< ��ǰ ���� ����Ʈ >>" << endl; 
			for(int j=0; j<p.size(); j++) {
				p[j]->Show();	
			}
			break;
			
			case 2:
			cout << "������ ��ǰ���� �Է����ּ���. : ";
			cin >> name;
			try {
				for(int i=0; i<p.size(); i++) {
					if(name == p[i]->getName())	{
						cout << " << ��ǰ ���� >> " << endl;	//��ǰ ���� 
						while(1) {
							try {
								cout << "��ǰ�� : ";				
								cin >> name;
								for(int j=0; j<p.size(); j++) {
									if(p[j]->getName() == name) throw "��ǰ���� �̹� �����մϴ�.";	
								}
								break; 
							}
							catch(const char* s) {
								cout << s<< endl;
							}
						}
						cout << "���� : " ;
						cin >> price;
						cout << "��ǰ ���� : ";
						cin >> address; 
						cout << "��ǰ ���� : ";
						cin >> mail; 
						cout << "��� ���� : ";
						cin >> PW;
						cout << "ī�װ� : ";
						cin >> ID; 
						try {
							check = false;
							for(int j=0; j<g.size(); j++) {
								if(g[j]->getName() == ID) {
									check = true;
									break;
								}
							}
							if(check == false) throw "�ش� ī�װ��� �������� �ʽ��ϴ�."; 
						}
						catch(const char* s) {
							cout << s << endl;
							return;
						}
						p[i]->Mod(name,mail,address,price,PW,ID);			
						cout << "���� �Ϸ�!" << endl; 	
						return; 
					}
				}
				throw "�ش� ��ǰ���� �������� �ʽ��ϴ�."; 
			}
			catch(const char* s) {
				cout << s << endl;
				return;
			}
			break;
			
			case 3:{
				cout << "������ ��ǰ���� �Է����ּ���. : ";
				cin >> name;
				vector<Product* > :: iterator it = p.begin();
				try {
					while(it != p.end()) {
						Product* t = *it;
						if(t->getName() == name){
							it = p.erase(it);
							cout << "���� �Ϸ�!" << endl; 	
							return;
						}
						it++;
					}
					 throw "�ش� ��ǰ���� �������� �ʽ��ϴ�."; 
				}
				catch(const char* s) {
					cout << s << endl;
					return;
				}		 
			}
			break;
			
			default:
			SELERROR;	
			break;
		}
	}
}
