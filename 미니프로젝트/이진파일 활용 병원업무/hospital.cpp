#include "hospital.h"

int Hospital :: i = 0;
int Hospital :: a = 0;
int Hospital :: rn = 1;
string Hospital :: s = "";
string Hospital :: t = "";

Hospital :: Hospital() {
	//E:\\������\\C++\\��������\\����\\Doctor.txt
	const char* file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\����\\Doctor.txt";
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
	//E:\\������\\C++\\��������\\����\\Patient.txt
	file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\����\\patient.txt";
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
	cout << "1. ��������\n2. ȯ�ھ���\n3. ����\n>>";
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
	cout << "1. �������\n2. �����\n3. �ڷΰ���\n>>";
	cin >> i;	
	return i;
}

void Hospital :: DMenu() {
	while((i=DMenuSelect())!=5) {
		switch(i) {
			case 1:
			try {
				if(T.Nothing()) throw "��������� ���� �������ּ���."; 
			}
			catch(const char* s) {
				cout << s << endl;
				return;	
			}
			cout << "�̸��� �Է��ϼ��� : ";
			cin >> s; 
			while(1) {
				T.Print(); 
				cout << "����� �� ��������� ������ : ";
				cin >> t;
				try {
					if(!T.Check(t)) throw "�ش� ��������� ���������ʽ��ϴ�.";
					break;
				}
				catch(const char* s) {
					cout << s << endl;
				}
			}	
			D.push_back(new Doctor(D.size()+1,s,t));
			DSave();
			cout << "��� �Ϸ�!" << endl; 
			break;
			
			case 2:
			try {
				cout << "�ĺ���ȣ�� �Է��ϼ��� : ";
				cin >> a;
				for(int i=0; i<D.size(); i++) {
					if(D[i]->getCode() == a) {
						cout << "������ �̸��� �Է��ϼ��� : ";
						cin >> s;
						T.Print();
						cout << "����� �� ��������� ������ : ";
						cin >> t;
						if(!T.Check(t)) throw "�ش� ��������� ���������ʽ��ϴ�.";
						D[i]->Mod(s,t);
						DSave();
						cout << "���� �Ϸ�!"<< endl;
						return; 
					}
				}
				throw "�ش� �ĺ���ȣ�� ���������ʽ��ϴ�."; 
			}
			catch(const char* s) {
				cout << s << endl;
			}
			break;
			
			case 3:
			try {
				cout << "�ĺ���ȣ�� �Է��ϼ��� : ";
				cin >> a;
				for(int i=0; i<D.size(); i++) {
					if(D[i]->getCode() == a) {
						Move(D[i]->getTL(),a,i);
						D[i]->CErase();
						D.erase(D.begin()+i);
						DSave();
						cout << "���� �Ϸ�!" << endl;
						return; 
					}
				}
				throw "�ش� �ĺ���ȣ�� ���������ʽ��ϴ�."; 
			}
			catch(const char* s) {
				cout << s << endl;
			}				
			break;
		
			case 4:
			try {
				if(D.size() == 0) throw "����Ʈ�� �����ϴ�."; 
				cout << "<< �ǻ� ���� >>" << endl; 
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
	cout << "1. ���\n2. ����\n3. ����\n4. ��ȸ\n5. �ڷΰ���\n>>";
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
	cout << "1. ���\n2. ����\n3. ����\n4. ��ȸ\n5. �ڷΰ���\n>>";
	cin >> i;	
	return i;	
}

void Hospital :: DSave() {
	//E:\\������\\C++\\��������\\����\\Doctor.txt
	const char* file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\����\\Doctor.txt";
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "���� ���� ����";
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
				if(T.Nothing()) throw "��������� �����ϴ�."; 
				if(D.size()==0) throw "�ǻ簡 �����ϴ�."; 
				cout << "��� ���°���?\n>>";
				cin >> s;
				ss = T.getName(s);
				if(ss == "����") throw "���õ� ��������� �������� �ʽ��ϴ�.";
				cout << "����ó�� �Է����ּ��� : ";
				cin >> a;
				cout << "�̸��� �Է����ּ��� : ";
				cin >> t;
				int cnt = 0;
				for(int j=0; j<D.size(); j++) {
					if(D[j]->getTL() == ss) cnt++;
				}
				if(cnt == 0) throw "�ش� ��������� ����ǻ簡 �������� �ʽ��ϴ�."; 
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
					cout << "<< �ش� ����� ����� ��� >>" << endl; 
					for(int j=0; j<D.size(); j++) {
						if(D[j]->getTL() == ss) D[j]->View();
					}
					while(1){
						try {
							cout << "���Ḧ ����� �ǻ��� �ĺ���ȣ�� �Է��ϼ��� : ";
							cin >> i;
							bool check = false;
							for(int j=0; j<D.size(); j++) {
								if(D[j]->getTL() == ss && D[j]->getCode() != i) {
									if(D[j]->PCheck(a,t)) throw "����ǰ� �ƴմϴ�."; 
								}									
							}
							for(int j=0; j<D.size(); j++) {
								if(D[j]->getTL() == ss && D[j]->getCode() == i) {
									check = true;
									k = j;
									break;
								}
							}
							if(check == false) throw "�߸��� �ĺ���ȣ�Դϴ�."; 
							break;
						}
						catch(const char* s) {
							cout << s << endl;	
						}
					}
				}
				D[k]->TimeView();
				int time = D[k]->getTimeView();
				if(time == -1) throw "������ �� á���ϴ�."; 
				cout << time << "Ÿ�� �����̽ð� �����ȣ�� " << rn << "�Դϴ�." << endl;;
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
				cout << "�����ȣ�� �Է��ϼ��� : ";
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
						throw "����ð��� �ƴմϴ�."; 
					}
				}
				throw "�ش��ϴ� �����ȣ�� �������� �ʽ��ϴ�."; 
			}
			catch(const char* s) {
				cout << s << endl;	
			}
			break;
			
			case 3:
			try {
				cout << "�����ȣ�� �Է��ϼ��� : ";
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
						throw "����ð��� �ƴմϴ�."; 
					}
				}
				throw "�ش��ϴ� �����ȣ�� �������� �ʽ��ϴ�."; 
			}
			catch(const char* s) {
				cout << s << endl;	
			}				
			break;
			
			case 4:
			try {
				cout << "�����ȣ�� �Է��ϼ��� : ";
				cin >> i; 
				for(int j=0; j<D.size(); j++) {
					check = D[j]->CView(i);	
					if(check == true) return;
				}
				throw "�ش��ϴ� �����ȣ�� �������� �ʽ��ϴ�."; 
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
	cout << "1. ���Ό��\n2. �Կ�\n3. ���\n4. ���᳻��\n5. �ڷΰ���\n>>";
	cin >> i;
	return i;	
}
//E:\\������\\C++\\��������\\����\\Patient.txt
void Hospital :: PSave() {
	const char* file = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\����\\patient.txt";
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "���� ���� ����";
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

