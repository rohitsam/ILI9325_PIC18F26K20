#include <18F26K20.h>
#DEVICE  ICD=TRUE
#FUSES HS,NOWDT,NOPUT,NOPROTECT
#use delay(internal = 32000000)
#use rs232(baud = 9600,xmit=PIN_C6,rcv=PIN_C7)
#include "library\library.h"

void main(){

   reset();
   lcd_init();
   fill(0x0);
      char *hello = "HELLO";
      char *world = "WORLD";
   printword(*hello,10,10);
   printword(*world,10,31);
   

}
