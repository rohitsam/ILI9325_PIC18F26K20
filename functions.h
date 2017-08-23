
CD_DATA;//function Macros 

void lcd_init();
void reset();
void writereg(int8 addr ,int16 data);
void fill(int16 color);
void mkhigh();
void write_addr(int8 x);
int16 reg_read();
void writegram(int16 data);
void set_pointer(unsigned int16 x1,unsigned int16 y1,unsigned int16 x2,unsigned int16 y2);
void drawpixel(int16 x,int16 y, int16 color);
void logos(char m, int16 x, int y);
void showlogo();
void printchar1(int16 x,int16 y ,int16 line);
void printword(char *word, int16 x ,int16 y);
