#include "PID_Control.h"



void delay_fn(int counter){
	counter = counter +16000000;
	while(counter--);
}

void PID_Control_Loop(void){
	
	// define pid variables
	// all variables are assigned to floats due to the neccissity of the application
	float  previous_error =0;
	float integral =0;
	float error=0 ;
	float setpoint = ReadAnalog(ATD_SETPOINT_CHANNEL);
	float measured_value = ReadAnalog(ATD_FEEDBACK_CHANNEL);
	float derivative =0;
	float output=0;
	
 // The Program control Loop
		while (1){
			setpoint = ReadAnalog(ATD_SETPOINT_CHANNEL);
			measured_value = ReadAnalog(ATD_FEEDBACK_CHANNEL);
			error = setpoint - measured_value ;
			integral = integral + error * dt ;
			derivative = (error -previous_error)/dt;
			output = kp * error + ki*integral +kd *derivative;
			DAC_OUT_VOLTAGE (output);
			previous_error = error;
			delay_fn (dt);
			
					}
				}
