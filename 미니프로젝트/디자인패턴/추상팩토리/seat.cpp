#include "seat.h"

int Seat :: cnt = 0;

Seat :: Seat() {
	seatNum = cnt; 
	cnt++;
	i = rand()%3;
	switch(i) {
		case 0:
		seatRank = "VVIP";
		price = 10000;
		break;
		
		case 1:
		seatRank = "VIP";
		price = 5000;
		break;
		
		case 2:
		seatRank = "Noraml";
		price = 2000;
		break;	
	}
	state = "O";
	reserveNum = -1;
}

Seat :: Seat(Seat* seat) {
	seatNum = seat->getSeatNum();
	seatRank = seat->getSeatRank();
	price = seat->getPrice();
	state = seat->getState();
	reserveNum = seat->getRNum();
	Stime = seat->getStime();
	Pnum = seat->getPnum();
}

void Seat :: Show() {
	cout << "좌석번호 : " << seatNum << endl << "좌석등급 : " << seatRank << endl << "가격 : " << price << endl << "시간 : " << Stime << endl;	
}

void Seat :: Sreserve(int r,int PN) {
	state = "R"; 
	reserveNum = r;		
	Pnum = PN;
}
