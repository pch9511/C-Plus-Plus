#include "doctor.h"
/*E:\\������\\C++\\��������\\����\\*/
Doctor :: Doctor(int i,string n,string t,string tm) { 
	code = i; name = n; TL = t; time = tm; 
	string ex = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\����\\";
	ex += to_string(code);
	ex += ".txt";
	const char* file = ex.c_str();	
	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if(fin) {
		int j = 0,a,b,c;
		string e,f,g,ee;
		bool h;
		while(!fin.eof()) {
			switch(j) {
				case 0:	
				getline(fin,e);
				if(e == "") return;
				break;
				
				case 1:
				getline(fin,f);
				a = stoi(f);
				break;
				
				case 2:
				getline(fin,f);
				b = stoi(f);
				break;
				
				case 3:
				getline(fin,f);
				c = stoi(f);
				break;
				
				case 4:
				getline(fin,g);	
				break;
				
				case 5:
				getline(fin,ee);
				if(stoi(ee)) h = true;
				else h = false;
				break;
				
				case 6:
				j = -1;
				C.push_back(new Content(g,a,e,c,b,h));
				break;
			}
			j++;
		}
	}
	fin.close();
}

void Doctor :: View() {
	cout << "�ĺ���ȣ: " << code << endl << "�̸� : " << name << endl << "������ : " 	<< TL << endl;
}

void Doctor :: TimeView() {
	cout << "<< �ð�ǥ >>" << endl; 
	for(int i=0; i<time.size(); i++) {
		if(time[i] == 'O') {
			cout << "��" << ' ';	
		}
		else if(time[i] == 'I') {
			cout << "��" << ' ';	
		}
		else if(time[i] == 'R') {
			cout << "��" << ' '; 
		}
		else if(time[i] == 'X') {
			cout << "��" << ' '; 
		}
		if(time.size()/2 == i+1) cout << endl;
	}
	cout << "----------------"<< endl;
}

int Doctor :: getTimeView() {
	for(int i=0; i<time.size(); i++) {
		if(time[i] == 'O') {
			time[i] = 'R';
			return (i+1);
		}
	}
	cout << "----------------"<< endl;
	return -1;
}

bool Doctor :: RCheck(int t) {
	for(int i=0; i<t; i++) {
		if(time[i] != 'X') return false;	
	}
	cout << "���� ����!" << endl;
	time[t] = 'I';
	return true;
}	

bool Doctor :: OCheck(int t) {
	if(time[t] == 'I') {
		cout << "���� ����!" << endl;
		time[t] == 'X';
		if(t == time.size()-1) {
			for(int i=0; i<time.size(); i++) {
				time[i] == 'O';
			}
		}
		for(int i=0; i<C.size(); i++) {
			if(t+1 == C[i]->getTime() && C[i]->getState() == false) {
				C[i]->Complete();
				CSave();
				return true;
			}
		}
	}
	return false;
}

void Doctor :: CSave() {
	string ex = "C:\\Users\\USER\\Desktop\\6_binaryfile.cpp_220805\\����\\";
	ex += to_string(code);
	ex += ".txt";
	const char* file = ex.c_str();
	ofstream fout;
	fout.open(file, ios::out | ios::binary);
	if(!fout) {
		cout << "���� ���� ����";
		return;
	}
	for(int i=0; i<C.size(); i++) {
		fout << C[i]->getName() << endl;
		fout << C[i]->getPnum() << endl;
		fout << C[i]->getNum() << endl;
		fout << C[i]->getTime() << endl;
		fout << C[i]->getContent() << endl;
		fout << C[i]->getState() << endl;		
	}	
	fout.close();	
}

bool Doctor :: CView(int code) {
	for(int i=0; i<C.size(); i++) {
		if(C[i]->getNum() == code) {
			cout << "<< ���� ���� >> " << endl; 
			C[i]->View(this->code);	
			cout << "----------------"<< endl;
			return true;
		}
	}
}

string Doctor :: CgetContent(int num) {
	for(int i=0; i<C.size(); i++) {
		if(C[i]->getNum() == num && C[i]->getState() == false) {
			return C[i]->getContent();
		}
	}
}

bool Doctor :: PCheck(int p,string n) {
	for(int i=0; i<C.size(); i++) {
		if(C[i]->getPnum() == p && C[i]->getName() == n) return true;
	}
}

void Doctor :: CErase() {
	C.erase(C.begin(),C.begin()+C.size());	
	CSave();
}
