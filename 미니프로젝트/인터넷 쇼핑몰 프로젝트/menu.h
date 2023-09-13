#ifndef MENU_H
#define MENU_H
#include "common.h" 
#include "customer.h"
#include "order.h"
#include "category.h"
#include "cardcompany.h"
#include "product.h"

class Menu {				//��ü ȭ�� ���� Ŭ���� 
	static int i;			//���� ���� 
	static int price;		//���� �� 
	static int num;			//�α����� �� ��ȣ 
	static string ID;		//ID
	static string RRN;		//�ֹε�Ϲ�ȣ 
	static string name;		//�̸� 
	static string address;	//�ּ� 
	static string PW;		//�н����� 
	static string mail;		//�����ּ� 
	static string Pnum;		//��ȭ��ȣ 
	static bool check;		//üũ��  
	vector<Customer* > c;	//ȸ�� ����Ʈ 
	vector<Category* > g;	//ī�װ� ����Ʈ 
	vector<Product* > p;	//��ǰ ����Ʈ 
	Company company;
public:
	void menu();			//���θ޴� 
	int MenuSelect();		//���θ޴� ���� 
	void Login();			//�α��� ȭ�� 
	void NewAccount();		//ȸ������ ȭ�� 
	void adminMenu();		//������ �޴� ȭ�� 
	int adminSelect();		//������ �޴� ���� 
	void memberMenu();		//ȸ�� �޴� ȭ�� 
	int memberSelect();		//ȸ�� �޴� ���� 
	void nonmemberMenu(); 	//��ȸ�� �޴� ȭ��
	int nonmemberSelect();	//��ȸ�� �޴� ���� 
	void categoryMenu();	//ī�װ� ���� �޴� 
	int categorySelect(); 	//ī�װ� �޴� ���� 
	void categoryCreate();	//ī�װ� ��� ȭ��
	void categoryMod();		//ī�װ� ���� ȭ��
	void categoryDel();		//ī�װ� ���� ȭ�� 
	void accountMenu();		//ȸ������ �޴� ȭ�� 
	int accountSelect();	//ȸ������ �޴� ���� 
	void productMenu();		//��ǰ���� �޴� ȭ��
	int productSelect();	//��ǰ���� �޴� ���� 
	int categorySearch(); 	//ī�װ� ���� 
	void productSearch(); 	//ȸ�� ��ǰ ��ȸ �޴� 
	void productOrder();	//��ǰ �ֹ� 
	void BasketDelete();	//��ٱ��� ����
	void OrderPay();		//�ֹ� ���� �޴� ȭ�� 
	int OrderPaySelect();	//�ֹ� ���� ���� 
	void CardCreate();		//ī�� ���� ȭ��
	void CardPay();
	void OnlinePay(); 
};

#endif
