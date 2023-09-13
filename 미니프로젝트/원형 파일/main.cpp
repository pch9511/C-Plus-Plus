#include "common.h"
#include "menu.h"
#include "Employee.h"
#include "Worker.h"
//prototype
//사원 등록 -> Data employee 클래스 									
//					사번(중복x),이름,직책,성별,연락처(중복x) 
//		       Operator클래스 안에 employee 객체 생성 
//              -> set/get employee() 복사생성자 필수 
//							사원,주임,과장,부장,팀장 상속 
//메인 : 1. 사원등록(정보입력 -> 직책먼저 받을때 employee *clone() = 0 가상함수 만들기 ) 2. 사원조회(1.사번기준2.연락처기준3.직책기준)  3. 사원수정 4.사원삭제 5.종료 
// 													return new employee(*this) 수정도 마찬가지 


int main(int argc, char** argv) {
	while((i=MenuSelect())!=5) {
		switch(i) {
			case 1:
				
			break;
			
			case 2:
				
			break;
			
			case 3:
				
			break;
			
			case 4:
				
			break;
			
		}
	}	
	
	return 0;
}
