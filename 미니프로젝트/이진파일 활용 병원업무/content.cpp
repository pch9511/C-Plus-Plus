#include "content.h"

Content :: Content(string s,int a,string t,int tm,int rn,bool st) {
	name = t;
	Pnum = a;
	num = rn;
	time = tm;
	content = s;
	state = st;
}

void Content :: View(int code) {
	cout << "����ǻ� ��ȣ : " << code << endl <<"ȯ�ڸ� : " << name << endl << "�ڵ��� ��ȣ : " << Pnum << endl << "�����ȣ : " << num << endl << "����ð� : " << time << endl 
	<< "���᳻�� : " << content << endl << "���Ῡ�� : ";
	if(state) cout << "O" << endl;
	else cout << "X" << endl; 
}
