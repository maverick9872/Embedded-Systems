#include <lpc214x.h>

#define LED1_ON() IO1SET = (1<<16)
#define LED2_ON() IO1SET = (1<<17)
#define LED3_ON() IO1SET = (1<<18)
#define LED4_ON() IO1SET = (1<<19)

#define LED1_OFF() IO1CLR = (1<<16)
#define LED2_OFF() IO1CLR = (1<<17)
#define LED3_OFF() IO1CLR = (1<<18)
#define LED4_OFF() IO1CLR = (1<<19)


void Delay(unsigned char j){

unsigned int i;
for(;j>0;j--){
for(i = 0; i < 60000; i++);
}
}

int main(void)
{
PINSEL0 = 0x00000000;
PINSEL1 = 0x00000000;
PINSEL2 = 0x00000000;

IO1DIR = (1<<16) | (1<<19) | (1<<18) | (1<<17);

while(1){

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_ON();

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_OFF();
LED3_ON();

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_ON();

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_OFF();
LED3_OFF();
LED4_ON();

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_ON();

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_OFF();
LED3_ON();

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_ON();

Delay(100);
LED1_ON();

Delay(100);
LED1_OFF();
LED2_OFF();
LED3_OFF();
LED4_OFF();

}
return(0);
}