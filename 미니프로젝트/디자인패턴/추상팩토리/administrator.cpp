#include "administrator.h"

int Administrator :: play(vector<Seat *> *S) {
	Set(S);
	while((i=AdMenuSelect())!=6) {
		switch(i) {
			case 1:
			seatSet();	
			break;
			
			case 2:
			RState();	
			break;
			
			case 3:
			SState();	
			break;
			
			case 4:
			timeSchedule();	
			break;
			
			case 5:
			totalPrice();
			break;
			
			default:
			SELERROR;
			break;
		}
	}
	Get(&S);
}
