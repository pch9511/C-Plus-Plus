#include "treat.h"
#include "binaryfile.h"

Treat :: Treat() {
	h = NULL;
	//E:\\������\\C++\\��������\\����\\Treat.txt
	file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\����\\Treat.txt";
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if(fin) {
		string s;
		while(!fin.eof()) {
			getline(fin,s);
			if(s == "") break;
			TreatList* t = new TreatList;
			t->name = s;
			t->link = NULL;
			TreatList* a = h;
			if(h!=NULL) { 
				while(a->link!=NULL) {
					a = a->link;	
				}
				a->link = t;
			}
			else { 
				h = t;	
			}			
		}
	}
	fin.close();
}

void Treat :: Add() {
	string s[5] = { "�̺����İ�","�Ȱ�","ġ��","�ܰ�","����" };
	try {
		/*cout << "��������� �Է��ϼ���(�̺����İ�,�Ȱ�,ġ��,�ܰ�,����)\n>>";
		cin >> s; 
		if(s != "�̺����İ�" && s != "�Ȱ�" && s != "ġ��" && s != "�ܰ�" && s != "����") throw "�Է��� ���� ���� �Ұ���"; 
		if(Check(s) == true) throw "�̹� �����ϴ� ��������Դϴ�."; */
		for(int i=0; i<5; i++) {
			if(!Check(s[i])) {
				TreatList* t = new TreatList;
				t->name = s[i];
				t->link = NULL;
				TreatList* a = h;
				if(h!=NULL) { 
					while(a->link!=NULL) {
						a = a->link;	
					}
					a->link = t;
				}
				else { 
					h = t;	
				}
			}
		}
		Save();
		cout << "�߰��Ϸ�! " << endl; 
	}
	catch(const char* s) {
		cout << s << endl;
	}
}

void Treat :: Print() { 
	TreatList* t = h;
	try {
		if(t == NULL) throw "��������� �������� �ʽ��ϴ�."; 
		cout << " << ������� ����Ʈ >> " << endl; 
		int cnt = 1;
		while(t!=NULL) {
			cout << cnt << ". " << t->name << endl;	
			t = t->link;
			cnt++;
		}
		cout << "------------------" << endl;	
	}
	catch(const char* s) {
		cout << s<< endl;	
	}
}

bool Treat :: Check(string s) {
	TreatList* t = h;
	while(t!=NULL) {
		if(t->name == s) return true;
		t = t->link;
	}	
}

void Treat :: Mod() {
	string s;
	cout << "������ ��������� �Է��ϼ��� : ";
	cin >> s;
	try { 
		if(Check(s)) throw "�̹� �����ϴ� ��������Դϴ�."; 
		TreatList* t = h;
		while(t!=NULL) {
			if(t->name == s) {
				cout << "������ �̸��� �Է��ϼ��� : ";
				cin >> t->name; 
				Save();
				cout << "���� �Ϸ�!" << endl;
				return; 
			}
			t=t->link;
		}
		
	}
	catch(const char* s) {
		cout << s << endl;
	}	 
}

void Treat :: Del() {
	string s;
	cout << "������ ��������� �Է��ϼ��� : ";
	cin >> s;
	try { 
		if(Check(s) == false) throw "�������� �ʴ� ��������Դϴ�."; 
		TreatList* t = h;
		TreatList* o = t;
		while(t!=NULL) {	 
			if(t->name == s) {
				if(h == t) h = h->link;	
				else {
					o->link = t->link;
					t->link = NULL;
					delete t;
				}
				Save();
				cout << "���� �Ϸ�!" << endl;
				return; 
			}
			o = t;
			t=t->link;
		}
		
	}
	catch(const char* s) {
		cout << s << endl;
	}	 	
}

void Treat :: Save() {
	TreatList* t = h;
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "���� ���� ����";
		return; 
	}
	while(t!=NULL) {
		fout << t->name << endl;	
		t=t->link;
	}
	fout.close();
}

bool Treat :: Nothing() {
	if(h == NULL) return true;
	return false;	
}

string Treat :: getName(string s) {
	TreatList* t = h;	
	while(t!=NULL) {
		if(!s.find("��ó") && t->name == "�ܰ�") return t->name;
		else if(!s.find("��") && t->name == "�Ȱ�") return t->name;  
	 	else if(!s.find("ġ��") && t->name == "ġ��") return t->name;
		else if(!s.find("��ȭ") && t->name == "����") return t->name;
		else if(!s.find("��") && t->name == "�̺����İ�") return t->name;
		t=t->link;
	}
	return "����"; 
}
