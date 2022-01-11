#include <stdio.h>
#include <rc/motor.h>
#include <rc/time.h>
int main(){
    rc_motor_init();
	for(int i=0;i<4;i++){
	rc_motor_set (1, -0.235);
	rc_motor_set (2, -0.25); 
	rc_nanosleep(5E9);
	printf("Going Straight\n");
	rc_motor_set(1,0.25);
	rc_motor_set(2, -0.25);
	rc_nanosleep(7.3E8);
	printf("Turning left\n");
	}
	rc_motor_set(1,0);
	rc_motor_set (2, 0);
    rc_motor_cleanup();
}
