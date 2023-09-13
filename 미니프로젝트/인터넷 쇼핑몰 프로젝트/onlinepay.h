#ifndef ONLINEPAY_H
#define ONLINEPAY_H
#include "pay.h"
#include "common.h"

class OnlineDeposit : public Pay {
	string name;	//입금자 성명 
	string date;	//입금 예정일 
	string bank;	//입금 은행 
public:
	void PayApplication();  //온라인 입금 결제 신청 
	void PayerInfo();		//온라인 입금자 조회
	void PayComplete();		//결제 완료 실행 
};



#endif
