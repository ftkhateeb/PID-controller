
//Created by Khateeb's Team ( Ahmed Elkhateeb, Ahmed Aboelfadl, Saeed Mohammed saeed, Ahmed Mohamed, Ahmed Abdelhakeem)
/************************************************************************************************************************************/

//Presented to DR. Mohamed EL-SHafie and Eng. Mostafa Arafa
//Special Thanks to Abdallah Awdallah

/**************************************************************************************************************************************

// This is a Program to control a Motor position using Classical control theories (PID) 
// we utilize the Microcontroller MKl25z
// an encoder is connected to the Microcontroller Pin to read the postion of the motor
/* output voltage to the Microcontroller is done using the DAC Module
**************************************************************************************************************************************/
  
#include "Digital_To_Analog.h"
#include "ATD.h"
#include "PID_Control.h"


int main (void ){
	//ADC and DAC initialization 
	DAC_Init();
	ATD_Init();
	
	//The main program function the contains our while(1) and initialization for the PID Parameters   
	PID_Control_Loop();
	
} 
