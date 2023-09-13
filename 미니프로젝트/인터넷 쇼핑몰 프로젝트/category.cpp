#include "category.h"
#include "menu.h"

void Menu :: categoryCreate() {
	try {
		cout << "카테고리명 : ";
		cin >> name;  
		for(int i=0; i<g.size(); i++) {
			if(g[i]->getName() == name) throw name;	
		}
	}
	catch(string s) {
		cout << name << "의 카테고리명이 존재합니다." << endl;
		return; 
	}
	cout << "1.최상위\n2.상위\n3.하위\n>>";
	cin >> i;
	switch(i) {
		case 1:
		g.push_back(new Category(name,1));
		cout << "등록 완료 !" << endl; 
		break;
		
		case 2:
		try {
			check = false;
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getLevel() == 1) check = true;
			}
			if(check == false) throw "최상위 카테고리를 먼저 생성해 주십시오."; 
		}
		catch(const char* s) {
			cout << s << endl;
			return;
		}
		cout << "<< 최상위 카테고리 리스트 >>" << endl; 
		for(int i=0; i<g.size(); i++) {
			if(g[i]->getLevel() == 1) {
				cout << g[i]->getName() << endl;
			}
		}
		cout << "상속될 카테고리 명을 입력하세요 : ";
		cin >> ID;
		try {
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getName() == ID) {
					g.push_back(new Category(name,2,i));
					cout << "등록 완료 !" << endl; 
					return;	
				}
			}
			throw ID; 
		}
		catch(string s) {
			cout << ID << "는 등록되지 않았거나 최상위 카테고리가 아닙니다." << endl;	
			return;
		}
		break;
		
		case 3:
		try {
			check = false;
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getLevel() == 2) check = true;
			}
			if(check == false) throw "상위 카테고리를 먼저 생성해 주십시오."; 
		}
		catch(const char* s) {
			cout << s << endl;
			return;
		}
		catch(const char* s) {
			cout << s << endl;
			return;
		}
		cout << "<< 상위 카테고리 리스트 >> " << endl;
		for(int i=0; i<g.size(); i++) {
			if(g[i]->getLevel() == 2) {
				cout << g[i]->getName() << endl;
			}
		}
		cout << "상속될 카테고리 명을 입력하세요 : ";
		cin >> ID;
		try {
			for(int i=0; i<g.size(); i++) {
				if(g[i]->getName() == ID) {
					g.push_back(new Category(name,3,g[i]->getTop(),i));
					cout << "등록 완료 !" << endl; 
					return;	
				}
			}
			throw ID; 
		}
		catch(string s) {
			cout << ID << "는 등록되지 않았거나 최상위 카테고리가 아닙니다." << endl;	
			return;
		}		 
		break;
		
		default:
		SELERROR;
		break;
	}
}

void Menu :: categoryMod() {
	cout << "수정하고자 하는 카테고리명을 입력해주세요 : ";
	cin >> name;
	try {
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getName() == name) {
				cout << "카테고리명 : ";
				cin >> name;
				for(int k=0; k<g.size(); k++) {
					if(g[k]->getName() == name) throw "중복된 카테고리명입니다.";
				}
				cout << "1.최상위 2.상위 3.하위 : ";
				cin >> i; 
				if(g[j]->getLevel() != i) { 
					for(int k=0; k<g.size(); k++) {
						if(g[k]->getTop() == j || g[k]->getMid() == j) throw "연관된 카테고리가 있어 변동 불가능합니다."; 
					}
				}
				g[j]->Mod(name,i);
				cout << "수정 완료!" << endl;
				return; 
			}
		}
		throw "해당하는 카테고리명이 없습니다.";
	}
	catch(const char* s) {
		cout << s << endl;
		return;
	}
}

void Menu :: categoryDel() {
	cout << "삭제하고자 하는 카테고리명을 입력해주세요 : ";
	cin >> name;
	vector<Category* > :: iterator it = g.begin();
	try {
		while(it != g.end()){
			Category *t = *it;
			if(t->getName() == name) {
				it = g.erase(it);
				cout << "삭제 완료!" << endl;
				return; 
			}
			it++;
		}
		throw name; 
	}
	catch(string s){
		cout << s << "는 존재하지 않는 카테고리명입니다." << endl; 
		return;
	}
}

int Menu :: categorySearch() {
	try{															
		check = false;
		cout << "<< 최상위 카테고리 >>" << endl; 
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getLevel() == 1) {
				cout << "No." << j << " -> " << g[j]->getName() << endl;
				check = true;
			}
		}
		if(check == false) throw "카테고리를 먼저 설정해야합니다."; 
		check = false;
		cout << "조회하고자 하는 카테고리 번호를 입력해주세요. : ";
		cin >> i;
		cout << "<< 상위 카테고리 >>" << endl;
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getTop() == i && g[j]->getLevel() == 2) {
				cout << "No." << j << " -> " << g[j]->getName() << endl;
				check = true;
			}
		}
		if(check == false) throw "카테고리가 없거나 잘못된 카테고리 번호입니다."; 	
		check = false;
		cout << "조회하고자 하는 카테고리 번호를 입력해주세요. : ";
		cin >> i;
		cout << "<< 하위 카테고리 >>" << endl;
		for(int j=0; j<g.size(); j++) {
			if(g[j]->getMid() == i && g[j]->getLevel() == 3) {
				cout << "No." << j << " -> " << g[j]->getName() << endl;
				check = true;
			}
		}
		if(check == false) throw "카테고리가 없거나 잘못된 카테고리 번호입니다."; 			
		cout << "상품 조회 할 카테고리 번호를 입력해주세요. : ";
		cin >> i;
		if(g[i]->getLevel() != 3) throw "하위 카테고리가 아닙니다."; 
		return i;
	}
	catch(const char *s) {
		cout << s << endl;
		return -1;
	}	
}
