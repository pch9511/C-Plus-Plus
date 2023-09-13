#include "menu.h"
#include "product.h"

void Menu :: productMenu() {
	while((i=productSelect())!=4) {
		switch(i) {
			case 1:
			try{															
				i = categorySearch();	//카테고리 선택 
				if(i == -1) throw "";
				cout << " << 상품 등록 >> " << endl;	// 상품 등록 
				while(1) {
					cout << "상품명 : ";				
					cin >> name;
					check = false;
					for(int j=0; j<p.size(); j++) {
						if(p[j]->getName() == name) {
							cout << "상품명이 이미 존재합니다." << endl;	
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
			cout << "가격 : " ;
			cin >> price;
			cout << "상품 사진 : ";
			cin >> address; 
			cout << "상품 설명 : ";
			cin >> mail; 
			cout << "등록 일자 : ";
			cin >> PW;
			p.push_back(new Product(name,mail,address,price,PW,g[i]->getName())); 
			cout << "상품 등록 완료!" << endl; 
			cout << "<< 상품 전제 리스트 >>" << endl; 
			for(int j=0; j<p.size(); j++) {
				p[j]->Show();	
			}
			break;
			
			case 2:
			cout << "수정할 상품명을 입력해주세요. : ";
			cin >> name;
			try {
				for(int i=0; i<p.size(); i++) {
					if(name == p[i]->getName())	{
						cout << " << 상품 수정 >> " << endl;	//상품 수정 
						while(1) {
							try {
								cout << "상품명 : ";				
								cin >> name;
								for(int j=0; j<p.size(); j++) {
									if(p[j]->getName() == name) throw "상품명이 이미 존재합니다.";	
								}
								break; 
							}
							catch(const char* s) {
								cout << s<< endl;
							}
						}
						cout << "가격 : " ;
						cin >> price;
						cout << "상품 사진 : ";
						cin >> address; 
						cout << "상품 설명 : ";
						cin >> mail; 
						cout << "등록 일자 : ";
						cin >> PW;
						cout << "카테고리 : ";
						cin >> ID; 
						try {
							check = false;
							for(int j=0; j<g.size(); j++) {
								if(g[j]->getName() == ID) {
									check = true;
									break;
								}
							}
							if(check == false) throw "해당 카테고리는 존재하지 않습니다."; 
						}
						catch(const char* s) {
							cout << s << endl;
							return;
						}
						p[i]->Mod(name,mail,address,price,PW,ID);			
						cout << "수정 완료!" << endl; 	
						return; 
					}
				}
				throw "해당 상품명은 존재하지 않습니다."; 
			}
			catch(const char* s) {
				cout << s << endl;
				return;
			}
			break;
			
			case 3:{
				cout << "삭제할 상품명을 입력해주세요. : ";
				cin >> name;
				vector<Product* > :: iterator it = p.begin();
				try {
					while(it != p.end()) {
						Product* t = *it;
						if(t->getName() == name){
							it = p.erase(it);
							cout << "삭제 완료!" << endl; 	
							return;
						}
						it++;
					}
					 throw "해당 상품명은 존재하지 않습니다."; 
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
