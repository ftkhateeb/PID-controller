#include "ATD.h"


void ATD_Init (void){
	
	//Enable clock to ADC module 
		SIM->SCGC6 |=SIM_SCGC6_ADC0_MASK;// This mask is defined in the MKLZ25
	
	//Enable clock to portE 
		SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;
	
	//ENABLE BIT 20 & 22 as analog to be used by the DAC Module on channel 0 and 3
  //BIT 20 corresponds to the setpoint pos
  //BIT 22 corresponds to the Feedback Pos
	
	PORTE->PCR[ATD_SETPOINT_POS] &=~PORT_PCR_MUX_MASK;
	PORTE->PCR[ATD_SETPOINT_POS] |=PORT_PCR_MUX(0);
	PORTE->PCR[ATD_FEEDBACK_POS] &=~PORT_PCR_MUX_MASK;
	PORTE->PCR[ATD_FEEDBACK_POS] |=PORT_PCR_MUX(0);
	
	// COFIGURE LOW POWER MODE , LONG SAMPLE TIME 16 BIT AND USE BUS CLOCK 
	ADC0->CFG1 |= ADC_CFG1_MODE(3) |ADC_CFG1_ADICLK(0);
	//normal power short sampling time 
		ADC0->CFG1 &= ~ADC_CFG1_ADLPC_MASK &~ ADC_CFG1_ADLSMP_MASK ; 
	//use external reference for voltage
	ADC0->SC2 |= ADC_SC2_REFSEL(1);
	
}

float ReadAnalog (int channel ){
	
	
	float n;
	// PTE20 for channel 0 and PTE22 use channel 3 
	
	ADC0->SC1[0] &=~ADC_SC1_ADCH_MASK;
	ADC0->SC1[0] |=ADC_SC1_ADCH(channel);
	

	//Wait for conversion 
	while (!(ADC0->SC1[0] &ADC_SC1_COCO_MASK));
	//Read result , conver to floating pint 
	n = (float) ADC0->R[0];
	return ( n*(3.3/65535));
	
	}
