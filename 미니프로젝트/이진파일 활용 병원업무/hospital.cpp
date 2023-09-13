#include "hospital.h"

int Hospital :: i = 0;
int Hospital :: a = 0;
int Hospital :: rn = 1;
string Hospital :: s = "";
string Hospital :: t = "";

Hospital :: Hospital() {
	//E:\\박찬혁\\C++\\병원관리\\파일\\Doctor.txt
	const char* file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\파일\\Doctor.txt";
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if(fin) {
		int i = 0;
		string k;
		while(!fin.eof()) {
			switch(i) {
				case 0:	
				getline(fin,s);
				if(s == "") break; 
				a = stoi(s);
				break;
				
				case 1:
				getline(fin,s);
				break;
				
				case 2:
				getline(fin,t);
				break;
				
				case 3:
				getline(fin,k);	
				break;
				
				case 4:
				i = -1;
				D.push_back(new Doctor(a,s,t,k));
				break;
			}
			i++;
		}
	}
	fin.close();
	//E:\\박찬혁\\C++\\병원관리\\파일\\Patient.txt
	file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\파일\\patient.txt";
	fin.open(file, ios::in | ios::binary);
	int b,c,d;
	string v;
	if(fin) {
		int i = 0;
		while(!fin.eof()) {
			switch(i) {
				case 0:	
				getline(fin,s);
				if(s == "") return;
				break;
				
				case 1:
				getline(fin,t);
				a = stoi(t);
				break;
				
				case 2:
				getline(fin,t);
				break;
				
				case 3:
				getline(fin,v);
				b = stoi(v);	
				break;
				
				case 4:
				getline(fin,v);
				c = stoi(v);
				break;
				
				case 5:
				getline(fin,v);
				d = stoi(v);
				rn = d+1;	
				break;
				
				case 6:
				i = -1;
				P.push_back(new Patient(s,a,t,b,c,d));					
				break;
			}
			i++;
		}
	}	
	fin.close();
}

void Hospital :: Menu() { 
	while((i=MenuSelect())!=3) {
		switch(i) {
			case 1:
			HMenu();
			break;
			
			case 2:
			PMenu();
			break;
			
			default:
			SELERROR;	
			break;
		}
	}
}

int Hospital :: MenuSelect() {
	cout << "1. 병원업무\n2. 환자업무\n3. 종료\n>>";
	cin >> i;
	return i; 	
};

void Hospital :: HMenu() {
	while((i=HMenuSelect())!=3) {
		switch(i) {
			case 1:
			TMenu();
			break;
			
			case 2:
			DMenu();
			break;
			
			default:
			SELERROR;
			break;
		}
	}
}

int Hospital :: HMenuSelect() {
	cout << "1. 진료과목\n2. 담당의\n3. 뒤로가기\n>>";
	cin >> i;	
	return i;
}

void Hospital :: DMenu() {
	while((i=DMenuSelect())!=5) {
		switch(i) {
			case 1:
			try {
				if(T.Nothing()) throw "진료과목을 먼저 생성해주세요."; 
			}
			catch(const char* s) {
				cout << s << endl;
				return;	
			}
			cout << "이름을 입력하세요 : ";
			cin >> s; 
			while(1) {
				T.Print(); 
				cout << "담당이 될 진료과목을 고르세요 : ";
				cin >> t;
				try {
					if(!T.Check(t)) throw "해당 진료과목은 존재하지않습니다.";
					break;
				}
				catch(const char* s) {
					cout << s << endl;
				}
			}	
			D.push_back(new Doctor(D.size()+1,s,t));
			DSave();
			cout << "등록 완료!" << endl; 
			break;
			
			case 2:
			try {
				cout << "식별번호를 입력하세요 : ";
				cin >> a;
				for(int i=0; i<D.size(); i++) {
					if(D[i]->getCode() == a) {
						cout << "수정할 이름을 입력하세요 : ";
						cin >> s;
						T.Print();
						cout << "담당이 될 진료과목을 고르세요 : ";
						cin >> t;
						if(!T.Check(t)) throw "해당 진료과목은 존재하지않습니다.";
						D[i]->Mod(s,t);
						DSave();
						cout << "수정 완료!"<< endl;
						return; 
					}
				}
				throw "해당 식별번호는 존재하지않습니다."; 
			}
			catch(const char* s) {
				cout << s << endl;
			}
			break;
			
			case 3:
			try {
				cout << "식별번호를 입력하세요 : ";
				cin >> a;
				for(int i=0; i<D.size(); i++) {
					if(D[i]->getCode() == a) {
						Move(D[i]->getTL(),a,i);
						D[i]->CErase();
						D.erase(D.begin()+i);
						DSave();
						cout << "삭제 완료!" << endl;
						return; 
					}
				}
				throw "해당 식별번호는 존재하지않습니다."; 
			}
			catch(const char* s) {
				cout << s << endl;
			}				
			break;
		
			case 4:
			try {
				if(D.size() == 0) throw "리스트가 없습니다."; 
				cout << "<< 의사 정보 >>" << endl; 
				for(int i=0; i<D.size(); i++) {
					D[i]->View();	
					cout << "------------------" << endl;
				}
			}
			catch(const char* s) {
				cout << s << endl;
			}
			break;
			default:
			SELERROR;
			break;
		}
	}
}

int Hospital :: DMenuSelect() {
	cout << "1. 등록\n2. 수정\n3. 삭제\n4. 조회\n5. 뒤로가기\n>>";
	cin >> i;	
	return i;	
}

void Hospital :: TMenu() {
	while((i=TMenuSelect())!=5) {
		switch(i) {
			case 1:
			T.Add();	
			break;
			
			case 2:
			T.Mod();	
			break;
			
			case 3:
			T.Del();
			break;
			
			case 4:
			T.Print();
			break;
			
			default:
			SELERROR;
			break;	
		}
	}		
}

int Hospital :: TMenuSelect() {
	cout << "1. 등록\n2. 수정\n3. 삭제\n4. 조회\n5. 뒤로가기\n>>";
	cin >> i;	
	return i;	
}

void Hospital :: DSave() {
	//E:\\박찬혁\\C++\\병원관리\\파일\\Doctor.txt
	const char* file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\파일\\Doctor.txt";
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "파일 열기 오류";
		return;
	}
	for(int i=0; i<D.size(); i++) {
		fout << D[i]->getCode() << endl;
		fout << D[i]->getName() << endl;
		fout << D[i]->getTL() << endl;
		fout << D[i]->getTime() << endl;
	}	
	fout.close();
}

void Hospital :: PMenu() {
	int k;
	string ss;
	bool check = false;
	while((i=PMenuSelect())!=5) {
		switch(i) {
			case 1:
			try {
				if(T.Nothing()) throw "진료과목이 없습니다."; 
				if(D.size()==0) throw "의사가 없습니다."; 
				cout << "어디가 아픈가요?\n>>";
				cin >> s;
				ss = T.getName(s);
				if(ss == "없음") throw "관련된 진료과목이 존재하지 않습니다.";
				cout << "연락처를 입력해주세요 : ";
				cin >> a;
				cout << "이름을 입력해주세요 : ";
				cin >> t;
				int cnt = 0;
				for(int j=0; j<D.size(); j++) {
					if(D[j]->getTL() == ss) cnt++;
				}
				if(cnt == 0) throw "해당 진료과목의 담당의사가 존재하지 않습니다."; 
				else if(cnt == 1) {
					for(int j=0; j<D.size(); j++) {
						if(D[j]->getTL() == ss) {
							i = D[j]->getCode();
							k = j;
							break;
						}
					}
				}
				else {
					cout << "<< 해당 진료과 담당의 목록 >>" << endl; 
					for(int j=0; j<D.size(); j++) {
						if(D[j]->getTL() == ss) D[j]->View();
					}
					while(1){
						try {
							cout << "진료를 담당할 의사의 식별번호를 입력하세요 : ";
							cin >> i;
							bool check = false;
							for(int j=0; j<D.size(); j++) {
								if(D[j]->getTL() == ss && D[j]->getCode() != i) {
									if(D[j]->PCheck(a,t)) throw "담당의가 아닙니다."; 
								}									
							}
							for(int j=0; j<D.size(); j++) {
								if(D[j]->getTL() == ss && D[j]->getCode() == i) {
									check = true;
									k = j;
									break;
								}
							}
							if(check == false) throw "잘못된 식별번호입니다."; 
							break;
						}
						catch(const char* s) {
							cout << s << endl;	
						}
					}
				}
				D[k]->TimeView();
				int time = D[k]->getTimeView();
				if(time == -1) throw "예약이 꽉 찼습니다."; 
				cout << time << "타임 예약이시고 예약번호는 " << rn << "입니다." << endl;;
				P.push_back(new Patient(t,i,ss,a,time,rn));
				PSave();
				D[k]->ContentIn(s,a,t,time,rn);
				rn++;
			}
			catch(const char* s) {
				cout << s << endl;
			}
			break;
			
			case 2:
			try {
				cout << "예약번호를 입력하세요 : ";
				cin >> i; 
				for(int j=0; j<P.size(); j++) {
					if(P[j]->getRN() == i) {
						for(int k=0; k<D.size(); k++) {
							if(D[k]->getCode() == P[j]->getCode()) {
								if(D[k]->RCheck(P[j]->getTime()-1)) {
									DSave();	
									return;
								}
							}
						}
						throw "예약시간이 아닙니다."; 
					}
				}
				throw "해당하는 예약번호는 존재하지 않습니다."; 
			}
			catch(const char* s) {
				cout << s << endl;	
			}
			break;
			
			case 3:
			try {
				cout << "예약번호를 입력하세요 : ";
				cin >> i; 
				for(int j=0; j<P.size(); j++) {
					if(P[j]->getRN() == i) {
						for(int k=0; k<D.size(); k++) {
							if(D[k]->getCode() == P[j]->getCode()) {
								if(D[k]->OCheck(P[j]->getTime()-1)) {
									P.erase(P.begin()+j);
									PSave();	
									return;
								}
							}
						}
						throw "예약시간이 아닙니다."; 
					}
				}
				throw "해당하는 예약번호는 존재하지 않습니다."; 
			}
			catch(const char* s) {
				cout << s << endl;	
			}				
			break;
			
			case 4:
			try {
				cout << "예약번호를 입력하세요 : ";
				cin >> i; 
				for(int j=0; j<D.size(); j++) {
					check = D[j]->CView(i);	
					if(check == true) return;
				}
				throw "해당하는 예약번호는 존재하지 않습니다."; 
			}
			catch(const char* s) {
				cout << s << endl;	
			}					
			break;
			
			default:
			SELERROR;
			break;
		}
	}
}

int Hospital :: PMenuSelect() {
	cout << "1. 진료예약\n2. 입원\n3. 퇴원\n4. 진료내역\n5. 뒤로가기\n>>";
	cin >> i;
	return i;	
}
//E:\\박찬혁\\C++\\병원관리\\파일\\Patient.txt
void Hospital :: PSave() {
	const char* file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\파일\\patient.txt";
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "파일 열기 오류";
		return;
	}
	for(int i=0; i<P.size(); i++) {
		fout << P[i]->getName() << endl;
		fout << P[i]->getCode() << endl;
		fout << P[i]->getIll() << endl;
		fout << P[i]->getPnum() << endl;
		fout << P[i]->getTime() << endl;
		fout << P[i]->getRN() << endl;
	}	
	fout.close();	
}

void Hospital :: Move(string TL,int code,int p) {
	int tv;
	for(int i=0; i<D.size(); i++) {
		if(D[i]->getTL() == TL && D[i]->getCode() != code) {
			for(int j=0; j<P.size(); j++) {
				if(P[j]->getCode() == code) {
					if((tv=D[i]->getTimeView()) != -1) {
						P[j]->Move(tv,D[i]->getCode());
						PSave();
						D[i]->ContentIn(D[p]->CgetContent(P[j]->getRN()),P[j]->getPnum(),P[j]->getName(),P[j]->getTime(),P[j]->getRN());
					}
				}
			}
		}
	}
}

