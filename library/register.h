//control registers of ILI9325.

#define START_OSC          0x00
#define DRIV_OUT_CTRL      0x01
#define DRIV_WAV_CTRL      0x02
#define ENTRY_MOD          0x03
#define RESIZE_CTRL        0x04
#define DISP_CTRL1         0x07
#define DISP_CTRL2         0x08
#define DISP_CTRL3         0x09
#define DISP_CTRL4         0x0A
#define RGB_DISP_IF_CTRL1  0x0C
#define FRM_MARKER_POS     0x0D
#define RGB_DISP_IF_CTRL2  0x0F
#define POW_CTRL1          0x10
#define POW_CTRL2          0x11
#define POW_CTRL3          0x12
#define POW_CTRL4          0x13
#define GRAM_HOR_AD        0x20
#define GRAM_VER_AD        0x21
#define RW_GRAM            0x22
#define POW_CTRL7          0x29
#define FRM_RATE_COL_CTRL  0x2B
#define GAMMA_CTRL1        0x30
#define GAMMA_CTRL2        0x31
#define GAMMA_CTRL3        0x32
#define GAMMA_CTRL4        0x35
#define GAMMA_CTRL5        0x36
#define GAMMA_CTRL6        0x37
#define GAMMA_CTRL7        0x38
#define GAMMA_CTRL8        0x39
#define GAMMA_CTRL9        0x3C
#define GAMMA_CTRL10       0x3D
#define HOR_START_AD       0x50
#define HOR_END_AD         0x51
#define VER_START_AD       0x52
#define VER_END_AD         0x53
#define GATE_SCAN_CTRL1    0x60
#define GATE_SCAN_CTRL2    0x61
#define GATE_SCAN_CTRL3    0x6A
#define PART_IMG1_DISP_POS 0x80
#define PART_IMG1_START_AD 0x81
#define PART_IMG1_END_AD   0x82
#define PART_IMG2_DISP_POS 0x83
#define PART_IMG2_START_AD 0x84
#define PART_IMG2_END_AD   0x85
#define PANEL_IF_CTRL1     0x90
#define PANEL_IF_CTRL2     0x92
#define PANEL_IF_CTRL3     0x93
#define PANEL_IF_CTRL4     0x95
#define PANEL_IF_CTRL5     0x97
#define PANEL_IF_CTRL6     0x98

//LCD_D[0:7] are connected to portA
//PINS connected
#define LCD_RST PIN_C0
#define LCD_CS PIN_C1
#define LCD_RS PIN_C2
#define LCD_WR PIN_C3
#define LCD_RD PIN_C4

