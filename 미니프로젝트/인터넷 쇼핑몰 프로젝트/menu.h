#ifndef MENU_H
#define MENU_H
#include "common.h" 
#include "customer.h"
#include "order.h"
#include "category.h"
#include "cardcompany.h"
#include "product.h"

class Menu {				//전체 화면 관리 클래스 
	static int i;			//선택 변수 
	static int price;		//가격 인 
	static int num;			//로그인한 고객 번호 
	static string ID;		//ID
	static string RRN;		//주민등록번호 
	static string name;		//이름 
	static string address;	//주소 
	static string PW;		//패스워드 
	static string mail;		//메일주소 
	static string Pnum;		//전화번호 
	static bool check;		//체크용  
	vector<Customer* > c;	//회원 리스트 
	vector<Category* > g;	//카테고리 리스트 
	vector<Product* > p;	//상품 리스트 
	Company company;
public:
	void menu();			//메인메뉴 
	int MenuSelect();		//메인메뉴 선택 
	void Login();			//로그인 화면 
	void NewAccount();		//회원가입 화면 
	void adminMenu();		//관리자 메뉴 화면 
	int adminSelect();		//관리자 메뉴 선택 
	void memberMenu();		//회원 메뉴 화면 
	int memberSelect();		//회원 메뉴 선택 
	void nonmemberMenu(); 	//비회원 메뉴 화면
	int nonmemberSelect();	//비회원 메뉴 선택 
	void categoryMenu();	//카테고리 관리 메뉴 
	int categorySelect(); 	//카테고리 메뉴 선택 
	void categoryCreate();	//카테고리 등록 화면
	void categoryMod();		//카테고리 수정 화면
	void categoryDel();		//카테고리 삭제 화면 
	void accountMenu();		//회원관리 메뉴 화면 
	int accountSelect();	//회원관리 메뉴 선택 
	void productMenu();		//상품관리 메뉴 화면
	int productSelect();	//상품관리 메뉴 선택 
	int categorySearch(); 	//카테고리 선택 
	void productSearch(); 	//회원 상품 조회 메뉴 
	void productOrder();	//상품 주문 
	void BasketDelete();	//장바구니 삭제
	void OrderPay();		//주문 결제 메뉴 화면 
	int OrderPaySelect();	//주문 결제 선택 
	void CardCreate();		//카드 생성 화면
	void CardPay();
	void OnlinePay(); 
};

#endif
