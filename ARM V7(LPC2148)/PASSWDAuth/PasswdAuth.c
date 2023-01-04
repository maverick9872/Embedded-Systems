#include <lpc214x.h>

#define BUZZER_ON() IO0CLR=(1<<11)		 //Macro Functions to turn ON Buzzer
#define BUZZER_OFF() IO0SET=(1<<11)		 //Macro Functions to turn OFF Buzzer


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
int passwd = 3245;
int bin = 0;
PINSEL0 = 0x00000000;
PINSEL1 = 0x00000000;
PINSEL2 = 0x00000000;

IO1DIR = (1<<16) | (1<<19) | (1<<18) | (1<<17);
IO0DIR = (1<<11) ;  // Set P0.11 as Output	to control buzzer

while(1){

  if(bin == passwd){
  LED1_ON();
  Delay(1000);	 //The count value is updated in the EINT3 ISR
  LED1_OFF();
  Delay(1000);
  }

  else{
  LED1_ON();
  LED2_ON();
  LED3_ON();
  LED4_ON();
  BUZZER_ON();
  Delay(1000);
  BUZZER_OFF();
  LED1_OFF();
  LED2_OFF();
  LED3_OFF();
  LED4_OFF();
}
bin = 3245;
}
return(0);
}