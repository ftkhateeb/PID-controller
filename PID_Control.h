#include "Digital_To_Analog.h"
#include "ATD.h"

//The tuned PID parameters for the position controller 
#define kp 21
#define ki 500
#define kd 1
#define dt 10

//Functions prototypes
void PID_Control_Loop(void);
void delay_fn(int );

