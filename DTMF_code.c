#include <avr/io.h>
#include <util/delay.h>
int main(void)
{
       DDRA=0x00;             //this sets PORTA as input PORT
       DDRC=0xFF;             //this sets PORTC as output PORT
       char y;                //variable initialization (y will be used to store input from DTMF) 
   while(1)
   {
          y=PINA;             //this stores the input from the DTMF module in y
          y&=0x0F;            //to avoid any chances of floating value at upper nibble of PORTA
              
              /*
              WE WILL BE USING:
              '2' FOR FORWARD MOVEMENT
              '8' FOR BACKWARD MOVEMENT
              '4' FOR LEFT TURN
              '6' FOR RIGHT TURN  */
              if (y==0x02)
                     PORTC=0b00001010;         //forward movement of both the motors
              if (y==0x04)
                    PORTC=0b00001000;          //stops M-1 and causes robot to turn left
              if (y==0x06)
                     PORTC=0b00000010;         //stops M-2 and causes bot to turn right
               if (y==0x08)  
                   PORTC=0b00000101;           //backward movement of both the motors
   }
       return 0;
}
