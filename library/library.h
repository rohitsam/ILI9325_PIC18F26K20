
#include "register.h"
#include "bangothic16x16.h"
#include <stdlib.h>


#define RAND_MAX 25000
#define PORTRAIT 0
#define LANDSCAPE 1
#define RANDC 1

#define CD_DATA  {\
                  output_low(LCD_CS); \
                  output_high(LCD_RS);\
                  output_high(LCD_RD);\
                  output_high(LCD_WR);\
                  }

int1 rcolor;
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
void writegram(int16 data){
      int8 lo,hi;
      hi = data>>8;
      lo = data;
      output_a(lo);
      output_low(LCD_WR);
      delay_us(10);
      output_high(LCD_WR);
      output_a(hi);
      output_low(LCD_WR);
      delay_us(10);
      output_high(LCD_WR);
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

void reset(){

   int8 i =0;
   output_high(LCD_CS);
   output_high(LCD_WR);
   output_high(LCD_RD); 
   output_low(LCD_RST);
   delay_ms(2);
   output_high(LCD_RST); 
   output_low(LCD_CS);
   write_addr(0x00); 
   for(i=0;i<3;i++){
   output_low(LCD_WR);
   output_high(LCD_WR);
     }

}
void lcd_init(){
   //writereg(0xE5, 0x78F0);
   //writereg(START_OSC, 0x0001);
   //delay_ms(50);
   writereg(DRIV_OUT_CTRL, 0x0100);
   writereg(DRIV_WAV_CTRL, 0x0700);
   
   writereg(ENTRY_MOD, 0x1020);
   writereg(RESIZE_CTRL,0x0000);
   writereg(DISP_CTRL2,0x0202);
   writereg(DISP_CTRL3,0x0000);
   writereg(DISP_CTRL4,0x0000);
   writereg(RGB_DISP_IF_CTRL1,0x0000);
   writereg(FRM_MARKER_POS,0x0);
   writereg(RGB_DISP_IF_CTRL2,0x0);
   writereg(POW_CTRL1,0x0000);
   writereg(POW_CTRL2,0x0007);
   writereg(POW_CTRL3,0x0000);
   writereg(POW_CTRL4,0x0000);
   delay_ms(200);
   writereg(POW_CTRL1,0x1690);
   writereg(POW_CTRL2,0x0227);
   delay_ms(50);
   writereg(POW_CTRL3,0x001A);
   delay_ms(50);
   writereg(POW_CTRL4,0x1800);
   writereg(POW_CTRL7,0x002A);
   delay_ms(50);
   writereg(GAMMA_CTRL1,0x0000);
   writereg(GAMMA_CTRL2,0x0000);
   writereg(GAMMA_CTRL3,0x0000);
   writereg(GAMMA_CTRL4,0x0206);
   writereg(GAMMA_CTRL5,0x0808);
   writereg(GAMMA_CTRL6,0x0007);
   writereg(GAMMA_CTRL7,0x0201);
   writereg(GAMMA_CTRL8,0x0000);
   writereg(GAMMA_CTRL9,0x0000);
   writereg(GAMMA_CTRL10,0x0000);
   writereg(GRAM_HOR_AD,0x0000);
   writereg(GRAM_VER_AD,0x0000);
   writereg(HOR_START_AD,0x0000);
   writereg(HOR_END_AD, 0x00EF);
   writereg(VER_START_AD, 0X0000);
   writereg(VER_END_AD, 0x013F);
   writereg(GATE_SCAN_CTRL1, 0x2700); // Driver Output Control (R60h)
   writereg(GATE_SCAN_CTRL2, 0x0001); // Driver Output Control (R61h)
   writereg(GATE_SCAN_CTRL3,0x0000); // Driver Output Control (R62h)
   writereg(PANEL_IF_CTRL1, 0X0010); // Panel Interface Control 1 (R90h)
   writereg(PANEL_IF_CTRL2, 0X0000);
   writereg(PANEL_IF_CTRL3, 0X0003);
   writereg(PANEL_IF_CTRL4, 0X1100);
   writereg(PANEL_IF_CTRL5, 0X0000);
   writereg(PANEL_IF_CTRL6, 0X0000);
   writereg(DISP_CTRL1, 0x0133); // Main screen turn on

}
void set_pointer(unsigned int16 x1,unsigned int16 y1,unsigned int16 x2,unsigned int16 y2){
   //ILI9325 has 240x320 pixel
   writereg(0x20,x1);
   writereg(0x21,y1);
   writereg(0x50, x1);
   writereg(0x51, x2);
   writereg(0x52, y1);
   writereg(0x53, y2);
   output_low(LCD_CS);

}
void fill(int16 color){
 
   int32 i=320;
   i *=240;
   writereg(0x20,0x0);
   writereg(0x21,0x0);
   write_addr(0x22);
   
   CD_DATA;
   while(i--){
   writegram(color);
   }
   output_high(LCD_CS);
}


void drawpixel(int16 x,int16 y, int16 color){
  
  
  writereg(0x20,y);
  writereg(0x21,x);
  
  
  write_addr(0x22);
  CD_DATA;
  writegram(color);
  
}


void logos(char m, int16 x, int y)
{      
        int16 line;
        switch(m){
        case 'A':line = 0;
        break;
        case 'H':line = 186;
        break;
        case 'O':line = 372;
        break;
        case 'Y':line = 744;
        break;
        case 'S':line = 558;
        break;
        
        
        }
         
         int16 h,w,w1;
         int16 color1;        
         int32 temp, ref;
         int16 temp2,ref2;
         int16 color=0xFFFF;;
         for (h=0;h<31;h++)
         {
           temp= make32(ahoy_buff[line],ahoy_buff[line+1],ahoy_buff[line+2],ahoy_buff[line+3]);
           ref = 0x80000000;
           for(w=0;w<31;w++)
           { // color = rand();
              if(temp & ref)
                drawpixel(x+w,y+h,color1);
              ref = ref >> 1;
           }
           line = line + 4;
           temp2= make16(ahoy_buff[line],ahoy_buff[line+1]);
           ref2 = 0x8000;
           for(w1=0;w1<10;w1++)
           {  //color = rand();
              if(temp2 & ref2)
                drawpixel(x+31+w1,y+h,color1);
              ref2 = ref2 >> 1;
              
           }
           line = line + 2;
         }
         

}

void showlogo(){
   int8 space = 2;
   int16 x =10,y=90;
   showchar('A',x,y);
   showchar('H',x+42+space,y);
   showchar('0',x+86+space,y);
   showchar('Y',x+126+space,y);
   showchar('S',x+168+space,y);
   showchar('Y',x+210+space,y);
   showchar('S',x+252+space,y);   

}
/*
void printchar(int16 x,int16 y){

        
         int16 line = 60;
         int16 h,w,w1;
         int16 color = 0xFFFF;        
         int32 temp, ref;
         int16 temp2,ref2;
         for (h=0;h<20;h++)
         {
           temp= make16(fonts[line],fonts[line+1]);
           ref = 0x8000;
           for(w=0;w<16;w++)
           {  
              if(temp & ref)
                drawpixel(x+w,y+h,color);
              ref = ref >> 1;
           }
           line = line + 2;
           temp2 = fonts[line];
           ref2 = 0x80;
           for(w1=0;w1<8;w1++)
           {  
              if(temp2 & ref2)
                drawpixel(x+31+w1,y+h,color);
              ref2 = ref2 >> 1;
              
           }
           line = line + 1;
         }
         

}
*/
void printchar1(int16 x,int16 y ,int16 line){
         
         int16 h,w;
         int16 color = 0xFFFF;
         int32 temp, ref;
         
         int8 fwidth = 31;
         int8 fheight =27;
         for (h=0;h<fheight;h++)
         { 
          
             
           temp =make32(ffonts[line],ffonts[line+1],ffonts[line+2],ffonts[line+3]);
           ref = 0x00000000;
           bit_set(ref,fwidth);
           for(w=0;w<fwidth;w++)
           
           { 
               if(rcolor)color =rand();
               
           
               if(temp & ref)
              
                drawpixel(x+w,y+h,color);
              
             
              ref = ref >> 1;
              
           }
           
           line = line + 4;          
              
           }
         
         
         
         
}
         
void printword(char *word, int16 x ,int16 y){
   int16 line;
   int8 i;
   int size = strlen(word);
   for(i=0;i<size;i++){
      if(word[i]<59){
      line = (word[i]-'0')*(int16)108;
      //printf("%c index is %Ld\n\r",word[i],line);
      printchar1(x,y,line);
      x=x+31;
      
      }
      else{
      
      line = ((word[i]-'A')*(int16)108)+1080;
      //printf("%c index is %Ld\n\r",word[i],line);
     printchar1(x,y,line);
      x =x+31;
      
      }
      
      
      
      
   
   }

      
      
      
      


}




