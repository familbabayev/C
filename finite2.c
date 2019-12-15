#include<stdio.h>
#include<string.h>

enum state{
	TON,
	TOFF,
	ML,
	MR,
	STOP
};

struct statemachine{
	enum state s;
	void (*func) (void);

};

void turn_off(void);
void turn_on(void);
void move_left(void);
void move_right(void);
void stop_state(void);

struct statemachine robot[] = {
	{TON, turn_on},
	{TOFF, turn_off},
	{ML, move_left},
	{MR, move_right},
	{STOP, stop_state}	
	};

enum state curr_state = TOFF;

int main(){
	while(1){
		turn_off();
		turn_on();
		move_left();
		move_right();
		stop_state();
	}
	
	return 0;
}

void turn_off(void){
	if(curr_state == TOFF){
		printf("robot is off\n");
		
		char ns[64];
		scanf("%s",ns);
		if(strcmp(ns,"turnon")==0)
			curr_state = TON;
	}
}

void turn_on(void){
	if (curr_state == TON){
		printf("robot is on\n");
		
		char ns[64];
		scanf("%s",ns);
		if(strcmp(ns,"turnoff") == 0)
			curr_state = TOFF;
		else if(strcmp(ns,"stop")==0)
			curr_state = STOP;

	}
}

void stop_state(void){
	if(curr_state == STOP){
		printf("robot is stopped\n");
		
		char ns[64];
		scanf("%s",ns);
		if(strcmp(ns,"turnoff") == 0)
			curr_state = TOFF;

		else if(strcmp(ns,"moveright") == 0)
			curr_state = MR;

		else if(strcmp(ns,"moveleft") == 0)
			curr_state = ML;
	
	
	}

}

void move_left(void){
	if(curr_state == ML){
		printf("robot moved left\n");

		char ns[64];
		scanf("%s",ns);
		if(strcmp(ns,"stop") == 0)
			curr_state = STOP;
	}

}


void move_right(void){
	if(curr_state == MR){
		printf("robot moved right\n");

		char ns[64];
		scanf("%s",ns);
		if(strcmp(ns,"stop") == 0)
			curr_state = STOP;
	}

}
