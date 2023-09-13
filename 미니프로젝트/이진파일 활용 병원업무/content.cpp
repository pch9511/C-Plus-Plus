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
	cout << "담당의사 번호 : " << code << endl <<"환자명 : " << name << endl << "핸드폰 번호 : " << Pnum << endl << "예약번호 : " << num << endl << "예약시간 : " << time << endl 
	<< "진료내용 : " << content << endl << "진료여부 : ";
	if(state) cout << "O" << endl;
	else cout << "X" << endl; 
}
