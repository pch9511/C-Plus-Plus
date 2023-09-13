#include "treat.h"
#include "binaryfile.h"

Treat :: Treat() {
	h = NULL;
	//E:\\박찬혁\\C++\\병원관리\\파일\\Treat.txt
	file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\파일\\Treat.txt";
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
	string s[5] = { "이비인후과","안과","치과","외과","내과" };
	try {
		/*cout << "진료과목을 입력하세요(이비인후과,안과,치과,외과,내과)\n>>";
		cin >> s; 
		if(s != "이비인후과" && s != "안과" && s != "치과" && s != "외과" && s != "내과") throw "입력한 과는 생성 불가능"; 
		if(Check(s) == true) throw "이미 존재하는 진료과목입니다."; */
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
		cout << "추가완료! " << endl; 
	}
	catch(const char* s) {
		cout << s << endl;
	}
}

void Treat :: Print() { 
	TreatList* t = h;
	try {
		if(t == NULL) throw "진료과목이 존재하지 않습니다."; 
		cout << " << 진료과목 리스트 >> " << endl; 
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
	cout << "수정할 진료과목을 입력하세요 : ";
	cin >> s;
	try { 
		if(Check(s)) throw "이미 존재하는 진료과목입니다."; 
		TreatList* t = h;
		while(t!=NULL) {
			if(t->name == s) {
				cout << "수정할 이름을 입력하세요 : ";
				cin >> t->name; 
				Save();
				cout << "수정 완료!" << endl;
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
	cout << "삭제할 진료과목을 입력하세요 : ";
	cin >> s;
	try { 
		if(Check(s) == false) throw "존재하지 않는 진료과목입니다."; 
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
				cout << "삭제 완료!" << endl;
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
		cout << "파일 열기 오류";
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
		if(!s.find("상처") && t->name == "외과") return t->name;
		else if(!s.find("눈") && t->name == "안과") return t->name;  
	 	else if(!s.find("치아") && t->name == "치과") return t->name;
		else if(!s.find("소화") && t->name == "내과") return t->name;
		else if(!s.find("목") && t->name == "이비인후과") return t->name;
		t=t->link;
	}
	return "없음"; 
}
