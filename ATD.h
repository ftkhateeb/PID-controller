
#include "MKL25Z4.h"

#define MASK(x) (1<<x)
#define ATD_SETPOINT_POS 20 //using j10 1 connector (channel 0)
#define ATD_FEEDBACK_POS 22 //using j10 5 (channel 3)
#define ATD_SETPOINT_CHANNEL  0
#define ATD_FEEDBACK_CHANNEL  3

void ATD_Init (void);
float ReadAnalog (int );
