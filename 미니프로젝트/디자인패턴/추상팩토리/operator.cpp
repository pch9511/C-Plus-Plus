#include "operator.h"

int Operator :: Otime = -1;
int Operator :: totalP = 0;
int Operator :: timeP = 1;
void Operator :: seatSet() {
	try {
		if(Otime < 0) throw "�ð�ǥ ������ ���� ���ּ���."; 
		if(seat.size() > 0) throw "�̹� �¼� ��ġ�� �������ϴ�."; 
		cout << "<< �¼� ��ġ >>" << endl; 
		cout << "�� Ÿ�Ӵ� �¼� ������ �Է����ּ��� : ";
		cin >> i;
		if(i <= 0) throw "�޴��� ���ư��ϴ�."; 
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
				throw "����� �¼��� �����Ƿ� �缳���� �Ұ����մϴ�."; 
			}
			seat[0]->CntReset();
		}
		vector<Seat *> :: iterator it = seat.begin();
		while(it != seat.end()) {
			it = seat.erase(it);
		}
		cout << "<< �ð�ǥ ���� >>" << endl;
		cout << "�� Ÿ�� ���� ���� �Է����ּ��� : ";
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
		if(check == false) throw "����� �¼��� �����ϴ�."; 
		cout << "<< ���� ��Ȳ >>" << endl; 
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
		if(Otime < 0) throw "�ð�ǥ�� �����ϴ�.";
		if(seat.size() == 0) throw "�¼��� �����ϴ�."; 
		cout << Otime << "Ÿ���� �ð��밡 �ֽ��ϴ�. �ð��븦 �Է��ϼ��� : ";
		cin >> i;
		if(i<=0 && i>Otime) throw "�߸� �Է��ϼ̽��ϴ�."; 
		bool check = false;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getStime() == i) {
				check = true;
				break;
			}
		}
		if(check == false) throw "�ش� �ð��뿡 �¼��� �����ϴ�.";	
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
	cout << "<< " << time << "�ð��� >>" << endl; 
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
			cout << "��\t"; 
		}
		else if(seat[j]->getState() == "R") {
			cout << "��\t"; 
		}	
		else if(seat[j]->getState() == "I") {
			cout << "��\t";	
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
	cout << "�� ���� : " << totalP << endl; 
}

void Operator :: reservation(int PN) {
	int SN;
	SN = SState();	
	try {
		if(SN == -1) throw "���� ȭ������ ���ư��ϴ�."; 
		cout << "������ �¼���ȣ�� �Է��ϼ��� : ";
		cin >> i;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getSeatNum() == i && seat[j]->getStime() == SN) { 
				if(seat[j]->getState() == "R" ) throw "�̹� ����� �¼��Դϴ�."; 
				if(seat[j]->getState() == "I" ) throw "�̹� ������ �¼��Դϴ�."; 
				seat[j]->Show();
				string s;
				cout << "�����Ͻðڽ��ϱ�? (Y/N) : ";
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
							cout << "���� ��ȣ�� " << r << "�Դϴ�." << endl; 
							seat[j]->Sreserve(r,PN);
							break;
						}
					}
				}
				else throw "���� ȭ������ ���ư��ϴ�.";				
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
		cout << "�����ȣ�� �Է��ϼ��� : ";
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
					cout << "�����Ͻðڽ��ϱ�? (Y/N) : ";
					string s;
					cin >> s;
					if(s == "Y") {
						seat[j]->In();
						cout << "����Ϸ�!" << endl;
						return;
					}
					else throw "���� ȭ������ ���ư��ϴ�."; 
				}
				else throw "���� ���� �ð��밡 �ƴϰų� �̹� ������ �����Դϴ�."; 
			}
		}
		cout << "�����ȣ�� Ʋ�Ƚ��ϴ�.\n��ȭ��ȣ�� �Է����ּ��� : ";
		cin >> i;
		if(PN != i) throw "�ش� ID ��ȭ��ȣ�� �ٸ��ϴ�."; 
		check = false;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getPnum() == i) {
				check = true;
				break;
			}	
		}
		if(check == false) throw "�޴��� ���ư��ϴ�."; 
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getPnum() == i) {
				cout << seat[j]->getStime()  << "�ð��� " << "�����ȣ : " << seat[j]->getRNum() << endl;	
			}
		}
		cout << "�����ȣ�� �Է��ϼ��� : ";
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
					cout << "�����Ͻðڽ��ϱ�? (Y/N) : ";
					string s;
					cin >> s;
					if(s == "Y") {
						seat[j]->In();
						cout << "����Ϸ�!" << endl; 
						return;
					}
					else throw "���� ȭ������ ���ư��ϴ�."; 
				}
				else throw "���� ���� �ð��밡 �ƴϰų� �̹� ������ �����Դϴ�."; 
			}
		}
		throw "�ش� �����ȣ�� �������� �ʽ��ϴ�."; 
	}
	catch(const char* s) {
		cout << s << endl;
		return;	
	}
}

void Operator :: Out() {
	try{
		cout << "�¼���ȣ�� �Է��ϼ��� : ";
		cin >> i;
		for(int j=0; j<seat.size(); j++) {
			if(seat[j]->getSeatNum() == i) {
				if(seat[j]->getState() == "I") {
					cout << "�����Ͻðڽ��ϱ� (Y/N) : ";
					string s;
					cin >> s;
					if(s == "Y") {
						seat[j]->Out();
						totalP+=seat[j]->getPrice();
						cout << "����Ϸ�!" << endl; 
						return;
					}
					else throw "���� ȭ������ ���ư��ϴ�."; 
				}
			}
		}
		throw "�߸��� �¼���ȣ�ų� ������ �Ұ����� �¼���ȣ �Դϴ�."; 
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
			if(seat[i]->getPnum() == PN && seat[i]->getState() == "I") throw "����Ǿ� �ִ� ���¸� Ż�� �Ұ����մϴ�."; 	
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
