#ifndef ORDERCONTENT_H
#define ORDERCONTENT_H
#include "common.h"

class OrderContent {
	int amount;
public:
	void OrderContentSave();	//주문 내역 저장 
	void OrderContentSearch();	//주문 내역 조회 	
};


#endif
