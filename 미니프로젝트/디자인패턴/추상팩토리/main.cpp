#include "common.h"
#include "menu.h"
#include "customer.h"
#include "administrator.h"



int main(int argc, char** argv) {
	srand((unsigned)time(NULL));
	vector<Customer* > c;
	Customer tc;
	Administrator a; 
	int j;
	vector<Seat *> S;
	while((i=mainMenuSelect())!=3) {
		switch(i) {
			case 1: 
			Create(c, &tc);
			c.push_back(new Customer(tc));
			break;
			
			case 2:
			j = Login(c);
			switch(j) {
				case -2:
				cout << "메인화면으로 돌아갑니다." << endl; 	
				break;
				
				case -1:
				a.play(&S);
				break;
		
				default:
				i = c[j]->play(&S);				
				if(i == -1) {
					vector<Customer *> :: iterator it = c.begin();
					while(it != c.end()) {
						Customer *t =  *it;
						if(t->getID() == c[j]->getID()) {
							c.erase(it);
							break;
						}
						it++;	
					}
					cout << "회원 탈퇴 성공!" << endl; 
				}
				break;
			}
			break;
			
			default:
			SELERROR;
			break;	
		}
	}
	return 0;
}
