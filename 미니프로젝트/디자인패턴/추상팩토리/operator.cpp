#include "operator.h"

int Operator :: Otime = -1;
int Operator :: totalP = 0;
int Operator :: timeP = 1;
void Operator :: seatSet() {
	try {
		if(Otime < 0) throw "시간표 설정을 먼저 해주세요."; 
		if(seat.size() > 0) throw "이미 좌석 배치가 끝났습니다."; 
		cout << "<< 좌석 배치 >>" << endl; 
		cout << "한 타임당 좌석 개수를 입력해주세요 : ";
		cin >> i;
		if(i <= 0) throw "메뉴로 돌아갑니다."; 
		for(int j=0; j<Otime; j++) {
			for(int k=0; k<i; k++) {
				seat.push_back(new Seat());	
			}
			seat[j]->CntReset();
		}
		for(int j=0; j<Otime; j++) {
			for(int k=(seat.size()/Otime)*j; k<(seat.size()/Otime)*(j+1); k++) {
				seat[k]->SetStime(j+1);
			}
		}	
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}
}

void Operator :: timeSchedule() {
	try {
		for(int i=0; i<seat.size(); i++) {
			if(seat[i]->getState() == "R") {
				throw "예약된 좌석이 있으므로 재설정이 불가능합니다."; 
			}
			seat[0]->CntReset();
		}
		vector<Seat *> :: iterator it = seat.begin();
		while(it != seat.end()) {
			it = seat.erase(it);
		}
		cout << "<< 시간표 설정 >>" << endl;
		cout << "몇 타임 진행 할지 입력해주세요 : ";
		cin >> Otime;
	}
	catch(const char* s){ 
		cout << s << endl;
		return;
	}
}

void Operator :: RState() {
	bool check = false;
	for(int i=0; i<seat.size(); i++) {
		if(seat[i]->getState() == "R") {
			check = true;
			break;
		}
	}
	try {
		if(check == false) throw "예약된 좌석이 없습니다."; 
		cout << "<< 예약 현황 >>" << endl; 
		for(int i=0; i<seat.size(); i++) {
			if(seat[i]->getState() == "R") {
				seat[i]->Show();
			}
		}	
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}
}

int Operator :: SState() {
	try {
		if(Otime < 0) throw "시간표가 없습니다.";
		if(seat.size() == 0) throw "좌석이 없습니다."; 
		cout << Otime << "타임의 시간대가 있습니다. 시간대를 입력하세요 : ";
		cin >> i;
		if(i<=0 && i>Otime) throw "잘못 입력하셨습니다."; 
		bool check = false;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getStime() == i) {
				check = true;
				break;
			}
		}
		if(check == false) throw "해당 시간대에 좌석이 없습니다.";	
		SShow(i);
		cout << endl;
		return i;
	}
	catch(const char* s) {
		cout << s << endl;
		return -1;
		 
	}
}

void Operator :: SShow(int time) {
	int i = seat.size()/Otime;
	int cnt = 0,k;
	cout << "<< " << time << "시간대 >>" << endl; 
	for(int j=i*(time-1); j<i*time; j++) {
		if(i%2 == 1 && cnt == i/2+1) {
			cout << endl;
			for(k=i*(time-1); k<j; k++) {
				cout << seat[k]->getSeatNum() << "\t";	
			}
			cout << endl;
		}
		if(i%2 == 0 && cnt == i/2) {
			cout << endl;
			for(k=i*(time-1); k<j; k++) {
				cout << seat[k]->getSeatNum() << "\t";	
			}
			cout << endl;
		}
		if(seat[j]->getState() == "O") {
			cout << "□\t"; 
		}
		else if(seat[j]->getState() == "R") {
			cout << "■\t"; 
		}	
		else if(seat[j]->getState() == "I") {
			cout << "●\t";	
		}
		cnt++;
	}
	cout << endl;
	for(int j=k; j<i*time; j++) {
		cout << seat[j]->getSeatNum() << "\t";	 	
		if(i==1) break;
	}
	cout << endl;
}
void Operator :: totalPrice() {
	cout << "총 이익 : " << totalP << endl; 
}

void Operator :: reservation(int PN) {
	int SN;
	SN = SState();	
	try {
		if(SN == -1) throw "이전 화면으로 돌아갑니다."; 
		cout << "예약할 좌석번호를 입력하세요 : ";
		cin >> i;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getSeatNum() == i && seat[j]->getStime() == SN) { 
				if(seat[j]->getState() == "R" ) throw "이미 예약된 좌석입니다."; 
				if(seat[j]->getState() == "I" ) throw "이미 입장한 좌석입니다."; 
				seat[j]->Show();
				string s;
				cout << "예약하시겠습니까? (Y/N) : ";
				cin >> s;
				if(s == "Y") {
					while(1) {
						bool check = false;
						int r = rand()%90+10;
						for(int k=0; k<seat.size(); k++) {
							if(seat[k]->getRNum() == r) {
								check = true; 
								break;
							}
						}
						if(check == false) {
							cout << "예약 번호는 " << r << "입니다." << endl; 
							seat[j]->Sreserve(r,PN);
							break;
						}
					}
				}
				else throw "이전 화면으로 돌아갑니다.";				
			}
		}
	}
	catch(const char* s) {
		cout << s << endl;
		return;
	}
}

void Operator :: In(int PN) {
	try{
		bool check = false;
		cout << "예약번호를 입력하세요 : ";
		cin >> i;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getRNum() == i) {	
				for(int k=0; k<seat.size(); k++) {
					if(seat[k]->getState() == "I") {
						timeP = seat[k]->getStime();
						check = true;
						break;
					}
				}
				if(check == false) timeP = seat[j]->getStime();
				if(seat[j]->getStime() == timeP && seat[j]->getState() == "R") {
					cout << "입장하시겠습니까? (Y/N) : ";
					string s;
					cin >> s;
					if(s == "Y") {
						seat[j]->In();
						cout << "입장완료!" << endl;
						return;
					}
					else throw "이전 화면으로 돌아갑니다."; 
				}
				else throw "현재 입장 시간대가 아니거나 이미 입장한 상태입니다."; 
			}
		}
		cout << "예약번호가 틀렸습니다.\n전화번호를 입력해주세요 : ";
		cin >> i;
		if(PN != i) throw "해당 ID 전화번호와 다릅니다."; 
		check = false;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getPnum() == i) {
				check = true;
				break;
			}	
		}
		if(check == false) throw "메뉴로 돌아갑니다."; 
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getPnum() == i) {
				cout << seat[j]->getStime()  << "시간대 " << "예약번호 : " << seat[j]->getRNum() << endl;	
			}
		}
		cout << "예약번호를 입력하세요 : ";
		cin >> i;
		check = false;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getRNum() == i) {	
				for(int k=0; k<seat.size(); k++) {
					if(seat[k]->getState() == "I") {
						timeP = seat[k]->getStime();
						check = true;
						break;
					}
				}
				if(check == false) timeP = seat[j]->getStime();	
				if(seat[j]->getStime() == timeP && seat[j]->getState() == "R") {
					cout << "입장하시겠습니까? (Y/N) : ";
					string s;
					cin >> s;
					if(s == "Y") {
						seat[j]->In();
						cout << "입장완료!" << endl; 
						return;
					}
					else throw "이전 화면으로 돌아갑니다."; 
				}
				else throw "현재 입장 시간대가 아니거나 이미 입장한 상태입니다."; 
			}
		}
		throw "해당 예약번호는 존재하지 않습니다."; 
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}
}

void Operator :: Out() {
	try{
		cout << "좌석번호를 입력하세요 : ";
		cin >> i;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getSeatNum() == i) {
				if(seat[j]->getState() == "I") {
					cout << "퇴장하시겠습니까 (Y/N) : ";
					string s;
					cin >> s;
					if(s == "Y") {
						seat[j]->Out();
						totalP+=seat[j]->getPrice();
						cout << "퇴장완료!" << endl; 
						return;
					}
					else throw "이전 화면으로 돌아갑니다."; 
				}
			}
		}
		throw "잘못된 좌석번호거나 퇴장이 불가능한 좌석번호 입니다."; 
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}		
}

void Operator :: Get(vector<Seat *> **S) {
	vector<Seat *> :: iterator it = (**S).begin();
	while(it != (**S).end()) {
		it = (**S).erase(it);
	}
	for(int i=0; i<seat.size(); i++) {
		(**S).push_back(new Seat(seat[i]));
	}
}

void Operator :: Set(vector<Seat *> *S) {
	vector<Seat *> :: iterator it = seat.begin();
	while(it != seat.end()) {
		it = seat.erase(it);
	}
	for(int i=0; i<(*S).size(); i++) {
		seat.push_back(new Seat((*S)[i]));
	}
}

int Operator :: AccountDel(int PN) {
	try {
		for(int i=0; i<seat.size(); i++) {
			if(seat[i]->getPnum() == PN && seat[i]->getState() == "I") throw "입장되어 있는 상태면 탈퇴가 불가능합니다."; 	
		}
		for(int i=0; i<seat.size(); i++) {
			if(seat[i]->getPnum() == PN && seat[i]->getState() == "R") {
				totalP += seat[i]->getPrice();
				seat[i]->Out();	
			}
		}
		return -1;
	}
	catch(const char* s){
		cout << s << endl;
		return 1;
	}
}
