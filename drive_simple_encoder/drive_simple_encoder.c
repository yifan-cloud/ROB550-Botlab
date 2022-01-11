#include <stdio.h>
#include <rc/motor.h>
#include <rc/time.h>
#include <rc/encoder_eqep.h>

#define ENCODER_PER_METER 6000
#define ENCODER_PER_90 700
int main(){
    rc_motor_init();
	rc_encoder_eqep_init();
	rc_usleep(1E6);
	int left_enc;
	int right_enc;

	for(int i=0;i<4;i++){
		left_enc = rc_encoder_eqep_read(1);
		right_enc = rc_encoder_eqep_read(2);
		while(left_enc < ENCODER_PER_METER && right_enc < ENCODER_PER_METER){
			rc_motor_set (1, -0.235); 
	    		rc_motor_set (2, -0.25); 
			left_enc = rc_encoder_eqep_read(1);
			right_enc = rc_encoder_eqep_read(2);
		}
		printf("Done with going straight\n");
		rc_encoder_eqep_write(1,0);
		rc_encoder_eqep_write(2,0);

		left_enc = rc_encoder_eqep_read(1);
		right_enc = rc_encoder_eqep_read(2);

		while(left_enc > -ENCODER_PER_90 && right_enc < ENCODER_PER_90){
			rc_motor_set (1, 0.25); 
    		rc_motor_set (2, -0.25); 
			left_enc = rc_encoder_eqep_read(1);
			right_enc = rc_encoder_eqep_read(2);
		}

		rc_encoder_eqep_write(1,0);
		rc_encoder_eqep_write(2,0);
		printf("Done with turning left\n");
	}

	rc_motor_set (1, 0);
    rc_motor_set (2, 0); 
    rc_motor_cleanup();
	rc_encoder_eqep_cleanup();
	return 0;
}
