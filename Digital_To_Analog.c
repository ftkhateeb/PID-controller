#include "Digital_To_Analog.h"

void DAC_Init (void){
	//Enable clock to dac module  
	SIM->SCGC6 |=SIM_SCGC6_DAC0_MASK;
	//Enable clock to port E
	SIM->SCGC5 |=SIM_SCGC5_PORTE_MASK;
	
	//SELECT PIN AS ANALOG 
	PORTE->PCR[DAC_POS] &=~PORT_PCR_MUX_MASK;
	PORTE->PCR[DAC_POS] |=PORT_PCR_MUX(0);
	
	//Disable buffer mode 
	DAC0->C1 = 0;
	DAC0->C2 = 0;
	
	//Enable DAC , select VDDA as ref voltage 
	DAC0->C0 = DAC_C0_DACEN_MASK ;//| DAC_C0_DACRFS_MASK;
	
		
}
void DAC_OUT_VOLTAGE  (float OUTVOLT){
	/*this functioin used to produce output voltage at pin 30 in port E
	the maximum voltage = 3.3v */
	int level = OUTVOLT *(4096/3.3) -1;
	
	//Set min and max vals
			if (level>=4095){
				level = 4095;
			}else if (level <=0){
				level =0;
			}
			
	//Write to the dac 	
	DAC0->DAT[0].DATL = DAC_DATL_DATA0(level);
	DAC0->DAT[0].DATH = DAC_DATH_DATA1(level >> 8);
	
	
}

