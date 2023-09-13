#ifndef SEAT_H
#define SEAT_H
#include "common.h"

class Seat {
	int seatNum;
	string seatRank;
	int price;
	string state;
	int reserveNum;
	int Stime;
	int Pnum;
	static int cnt;
public:
	Seat();
	Seat(Seat* seat);
	string getState() { return state; }
	int getStime() { return Stime; }
	string getSeatRank() { return seatRank; }
	int getSeatNum() { return seatNum; }
	int getRNum() { return reserveNum; }
	int getPrice() { return price; }
	int getPnum() { return Pnum; }
	void Show();
	void Sreserve(int r,int PN); 
	void In() { state = "I"; }
	void Out() { state = "O"; reserveNum = -1; Pnum = -1;}
	void CntReset() { cnt = 0; }
	void SetStime(int Stime) { this->Stime = Stime; }
};



#endif
