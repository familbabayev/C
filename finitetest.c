#include<stdio.h>

enum state{OFF,ON,BLINK};

void lamp_off();
void lamp_on();
void lamp_blink();

enum state global_state;

void (*lamp_state)(void);

int change_state = 0;

int main(){
	//lamp_state();

	while(1){
		scanf("%d",&change_state);

		if (change_state && global_state == OFF)
			lamp_state = lamp_off;

		else if (change_state && global_state == ON)
			lamp_state = lamp_on;
		
		else if (change_state && global_state == BLINK)
			lamp_state = lamp_blink;

		lamp_state();
	}


	return 0;
}

void lamp_off(){
	printf("lamp off\n");
	global_state = OFF;
	if(change_state)
		global_state = ON;
}

void lamp_on(){
	printf("lamp on\n");
	global_state = ON;
	if(change_state)
		global_state = BLINK;

}

void lamp_blink(){
	printf("lamp blink\n");
	global_state = BLINK;
	if(change_state)
		global_state = OFF;
}
