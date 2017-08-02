#include <18F26K20.h>
#FUSES HS,NOWDT,NOPUT,NOPROTECT
#use delay(internal = 8000000)
#use rs232(baud = 9600,xmit=PIN_C6,rcv=PIN_C7)
/*
PORT A
#define LCD_D0 PIN_A0
#define LCD_D1 PIN_A1
#define LCD_D2 PIN_A2
#define LCD_D3 PIN_A3
#define LCD_D4 PIN_A4
#define LCD_D5 PIN_A5
#define LCD_D6 PIN_A6
#define LCD_D7 PIN_A7
*/

#define LCD_RST PIN_C0
#define LCD_CS PIN_C1
#define LCD_RS PIN_C2
#define LCD_WR PIN_C3
#define LCD_RD PIN_C4


void mkhigh(){
output_high(LCD_CS);
output_high(LCD_RS);
output_high(LCD_RD);
output_high(LCD_WR);
}
void write_addr(int8 x){
output_low(LCD_CS);
output_low(LCD_RS);
output_high(LCD_RD);
output_high(LCD_WR);
output_a(0x00);
output_low(LCD_WR);
delay_us(10);
output_high(LCD_WR);
output_a(x);
output_low(LCD_WR);
delay_us(10);
output_high(LCD_WR);
output_high(LCD_RS);
}
int16 reg_read(){
int16 value;
int16 value1;
int16 fvalue;
output_low(LCD_CS);
output_high(LCD_RS);
output_high(LCD_RD);
output_high(LCD_WR);
output_low(LCD_RD);
delay_us(10);
value = input_a()<<8;
output_high(LCD_RD);
delay_us(10);

output_low(LCD_RD);
delay_us(10);

value |= input_a();

output_high(LCD_RD);
output_high(LCD_CS);

return value;

}
void writereg(int8 addr ,int16 data){
write_addr(addr);
output_low(LCD_CS);
output_high(LCD_RS);
output_high(LCD_RD);
output_high(LCD_WR);
output_a(make8(data,1));
output_low(LCD_WR);
delay_us(10);
output_high(LCD_WR);
output_a(make8(data,0));
output_low(LCD_WR);
delay_us(10);
output_high(LCD_WR);
output_high(LCD_CS);
}
void main(){
int16 value;
mkhigh();
output_low(LCD_RST);
delay_ms(2);
output_high(LCD_RST);
delay_ms(500);
write_addr(0);
value = reg_read();
while(1){
printf("%Lx\n",value);
delay_ms(1000);
}
}