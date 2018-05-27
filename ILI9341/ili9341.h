#ifndef ILI9341_H__
#define ILI9341_H__

#include "lpc11xx.h"

#define     RED          0XF800	  //��ɫ
#define     GREEN        0X07E0	  //��ɫ
#define     BLUE         0X001F	  //��ɫ
#define     WHITE        0XFFFF	  //��ɫ
#define     BLACK        0X0000	  //��ɫ
#define     YELLOW       0XFFE0	  //��ɫ
#define     ORANGE       0XFC08	  //��ɫ
#define     GRAY  	     0X8430   //��ɫ
#define     LGRAY        0XC618	  //ǳ��ɫ
#define     DARKGRAY     0X8410	  //���ɫ
#define     PORPO        0X801F	  //��ɫ
#define     PINK         0XF81F	  //�ۺ�ɫ
#define     GRAYBLUE     0X5458   //����ɫ
#define     LGRAYBLUE    0XA651   //ǳ����ɫ
#define     DARKBLUE     0X01CF	  //�����ɫ
#define 		LIGHTBLUE    0X7D7C	  //ǳ��ɫ

#define OUT_DATA(value)	 LPC_GPIO2->DATA =(value<<4)
#define LCD_CS_SET LPC_GPIO3->DATA|=(1<<1)
#define LCD_CS_CLR LPC_GPIO3->DATA&=~(1<<1)
#define LCD_RS_SET LPC_GPIO3->DATA|=(1<<0)
#define LCD_RS_CLR LPC_GPIO3->DATA&=~(1<<0)
#define LCD_WR_SET LPC_GPIO1->DATA|=(1<<11)
#define LCD_WR_CLR LPC_GPIO1->DATA&=~(1<<11)

extern uint16_t  POINT_COLOR;
extern uint16_t  BACK_COLOR;

extern void LCD_WR_DATA(uint16_t val);
extern void LCD_WR_REG(uint16_t reg);
extern void LCD_Init(void);
extern void LCD_XYRAM(uint16_t stx,uint16_t sty,uint16_t endx,uint16_t endy);
extern void LcdWirteColorData(uint16_t color);
extern void LCD_Clear(uint16_t color);
extern void LCD_DrawPoint(uint16_t x, uint16_t y);
extern void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);
extern void LCD_DrawRectage(uint16_t xstart,uint16_t ystart,uint16_t xend,uint16_t yend);
extern void LCD_Fill(uint16_t xstart, uint16_t ystart, uint16_t xend, uint16_t yend);
extern void LCD_DrawCircle(uint8_t x0, uint16_t y0, uint8_t r);
extern void LCD_ShowChar(uint16_t x,uint16_t y,uint16_t num);


#endif



