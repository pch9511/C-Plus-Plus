#ifndef ONLINEPAY_H
#define ONLINEPAY_H
#include "pay.h"
#include "common.h"

class OnlineDeposit : public Pay {
	string name;	//�Ա��� ���� 
	string date;	//�Ա� ������ 
	string bank;	//�Ա� ���� 
public:
	void PayApplication();  //�¶��� �Ա� ���� ��û 
	void PayerInfo();		//�¶��� �Ա��� ��ȸ
	void PayComplete();		//���� �Ϸ� ���� 
};



#endif
